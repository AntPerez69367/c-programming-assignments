/*=============================================================================  
 * |      Source code:  forker.c
 * |           Author:  Anthony Perez 
 * |       Student ID:  5456512  
 * |       Assignment:  Program #6 Final Project
 * |  
 * |           Course:  COP4338 - Programming III  
 * |          Section:  U04
 * |       Instructor:  William Feild  
 * |         Due Date:  April 20, 2017, at the beginning of class
 * |
 * |        I hereby certify that this collective work is my own
 * |        and none of it is the work of any other person or entity.
 * |            ______________________________________ [Signature]
 * |  
 * |         Language:  C 
 * |      Compile/Run:  Must have forker.h in the same directory
 * |      Using Makefile: make
 * |      Using GCC:      gcc forker.c –o forker.out
 * |      to Run:         ./forker.out _ _ _ _ _ _ _* 
 * |      *(Between 1 and 7, inclusive – each a unique integer between 0-9.)
 * | 
 * |  +-----------------------------------------------------------------------------  
 * |  
 * |  Description:  Parent process will fork off children depending on user input. Forked
 * |                children will receive access to shared memory array of input which
 * |                will be manipulated by each child process. The children will display the
 * |                memory as they see it, modify it and display it again before exiting.
 * |                The parent will wait for children to end and then detach and terminate 
 * |                the shared memory.
 * |                  
 * |        Input:  User input is supplied via the command line. The program accepts 
 * |                between 1-7 integers each required to be unique and between 0-9. 
 * | 
 * |                Example: ./forker.out 1 3 5 7 9 2
 * |
 * |  
 * |       Output:  The program will have varied output from Parent process and 
 * |             Child Process it will display each step taken by each process.
 * |
 * |                Example:
 * |
 * |                Parent Process - Forking Child 1
 * |                       Child 1 - Beginning operations
 * |                       Child 1 - blah blah
 * |                Parent Process - Forking Child 2
 * |                       Child 1 - ending
 * |                       Child 2 - beginning operations
 * |                  
 * |  
 * |     Process:   Program uses structures to pass data required for shared memory.
 * |                Validation is called first through a separate function from the main. 
 * |  
 * |   Required Features Not Included:  All requirements met per spec sheet.
 * | 
 * |   Known Bugs:  Parent and Children sometimes interrupt eachother's output if
 * |               they are running a loop.
 * |
 * |  *===========================================================================*/

#include "forker.h" // User defined header.

/**
 * @brief main controls and calls all other functions.
 *
 * @param argc command line argument count
 * @param argv[] command line argument storage
 *
 * @return NO_ERRORS on successful run
 */
int main(int argc, char *argv[])
{
    /* Initialize Variables */
    sharedmem newMem = {0,NULL, 0};           /* Shared Memory Structure */
    process   childProcess[7];                /* Structure for storing child info*/
    int       size = argc-1;                  /* Number of children to be forked */
    int       counter = 0;                    /* Loop counter variable  */
    int      *inputData = NULL;               /* Array holds the command line data*/


    /* calloc - From the book pg 167 returns a pointer to space for an array
     * of n objects initialized to 0 */
    inputData = (int*)calloc(size, sizeof(int));

    /* Validate Input Data */
    if((inputData = validateInput(argc, argv, inputData))== NULL)  
    {
        /*Clean up*/
        free(inputData);
        return INVALID_INPUT;
    }
    else
    {
        /* Create shared memory */
        newMem = allocateSharedMem(size, inputData);

        /* Create children */
        spawnChildren(newMem);

        /* Wait for all children to exit */
        for (counter = 0; counter < size; counter ++)
        {
            childProcess[counter].pid = wait(&childProcess[counter].status);
        }

        /* Display PID and EXIT status */
        printf("PID\t EXIT\n");
        for (counter = 0; counter<size; counter ++)
        {
            printf("%5d\t %3d\n",childProcess[counter].pid, childProcess[counter].status);
        }
        printf("Parent - All child processes have exited. \n");

        /* Detach and remove shared memory */
        shmdt((void *) newMem.ShmPTR);
        printf("Parent -  detached the shared memory.\n");
        shmctl(newMem.shm_id, IPC_RMID, NULL);
        printf("Parent -  removed the shared memory.\n");

        /* Final clean up */
        free(inputData);


        return NO_ERRORS;
    }
}

/**
 * @brief Validate input - Validates the  command line input
 *
 * @param argc command line argument count 
 * @param argv[] command line arguments
 * @param inputData array for working with the input data
 *
 * @return the validated command line input.
 */
int *validateInput(int argc, char* argv[],int* inputData)
{

    /*Initialize Variables*/
    int numOfArguments = argc - 1; /*Number of command line arguments*/
    int          index = 0;        /*Outer loop index counter */           
    int          inner = 0;        /*Inner loop index counter */


    /* Validate Number of Arguments */
    if (INVALID_ARGUMENT_COUNT) 
    {
        printf("Invalid number of arguments. \n");
        return NULL;
    }
    else
    {
        /* Check if input is valid integer between 0-9 */
        for (index = 0; index < numOfArguments; index++)
        {
            sscanf(argv[index+1], "%d", &inputData[index]);
            if (INPUT_OUT_OF_BOUNDS)
            {
                printf("Input out of bounds. Numbers should be between 1-9.\n");
                return NULL;
            }
        }
        /* Check for duplicates in input */
        for (index = 0; index < numOfArguments-1; index++)
        {
            for (inner = index+1; inner < numOfArguments; inner++)
            {
                if (inputData[index] == inputData[inner])
                {
                    printf("Duplicate numbers detected. Please use unique integers.\n");
                    return NULL;
                }
            }
        }
        return inputData;
    }
}

/**
 * @brief allocates space for shared memory
 *
 * @param size the size of the memory space needed.
 * @param inputData[] the data that will be stored in shared memory
 *
 * @return shared memory structure
 */
sharedmem allocateSharedMem(int size, int inputData[])
{
    /*Initialize Variables*/
    sharedmem newMem = {0,NULL,0}; /*Shared memory structure*/
    int        index = 0;          /*Loop counter variable*/
    char buffer[BUFFER_SIZE];      /*String buffer*/

    /*Get shared memory key*/
    newMem.size = size;
    printf("Parent - Requesting shared memory of %d integers. \n", size);
    newMem.shm_id = shmget(IPC_PRIVATE, (size)*sizeof(int), IPC_CREAT | 0666);

    if (newMem.shm_id < 0) {
        printf("shmget error\n");
        exit(1);
    }
    printf("Parent - Shared memory received.\n");

    /*Attach memory to address space */
    newMem.ShmPTR = (int *) shmat(newMem.shm_id, NULL, 0);

    /*(void*)-1 is the return value of an error according to man shmat*/
    if (newMem.ShmPTR == (void *) -1) {
        printf("*** shmat error (server) ***\n");
        exit(1);
    }
    printf("Parent - Shared memory successfully attached. \n");

    /*Populate shared memory with command line input */
    for (index = 0; index < size; index++)
    {
        newMem.ShmPTR[index] = inputData[index];
    }
    printf("Parent - Shared memory populated with values. \n");

    /*Display shared memory */
    sprintf (buffer, "Parent - Shared memory values: ");
    write(1, buffer, strlen(buffer));
    for (index = 0; index<size; index++)
    {
        sprintf(buffer, " %d ",newMem.ShmPTR[index]);
        write(1, buffer, strlen(buffer));
    }
    sprintf(buffer, "\n");
    write(1, buffer, strlen(buffer));


    return newMem;
}

/**
 * @brief create child processes using fork()
 *
 * @param newMem shared memory structure which holds shared mem key, size, and 
 *               pointer to the shared memory data.
 */
void spawnChildren(sharedmem newMem)
{
    /*Initialize Variables*/
    int childCount = 0; /*Loop counter for spawning children*/
    pid_t fid;          /*fork() id return value */
    char pbuffer[BUFFER_SIZE]; /*String buffer for output */


    /*Parent Process - Begin Spawning size children */
    for (childCount = 0; childCount < newMem.size; childCount++)
    {
        sprintf(pbuffer, "Parent - Forking child #%d \n", childCount+1);
        write(1, pbuffer, strlen(pbuffer));

        /*Check if we are parent/child process and for successful fork*/
        if ((fid=fork()) < 0)
        {
            printf("Fork error - Terminating.\n");
            exit(1);
        }
        else if (fid == 0) {
            sprintf(pbuffer, "Parent - Child %d forked successfully.\n", childCount+1);
            write(1, pbuffer, strlen(pbuffer));

            childProcess(childCount, newMem);
            exit(0);
        }

    }
}
/**
 * @brief childProcess - these are the operations that the child processes that are
 *  forked will perform. 
 *
 * @param count Number of the child that was just forked.
 * @param newMem shared memory structure
 */
void childProcess(int count, sharedmem newMem)
{
    /*Initialize Variables*/
    char buffer[BUFFER_SIZE];
    int uniqueID = count + 1;
    pid_t myPid = 0;

    myPid = getpid();

    /* Child Process - start */
    sprintf(buffer, "\t Child %d - Process started with a PID of %d.\n", uniqueID, myPid);
    write(1, buffer, strlen(buffer));

    /* Child Process - Display initial state of shared memory*/     
    sprintf(buffer, "\t Child %d - This is the initial shared memory: ", uniqueID);
    write(1, buffer, strlen(buffer));
    printSharedMem(newMem);

    /* Child Process - Display private memory - unique ID */
    sprintf(buffer, "\t Child %d - This is my private memory: %d.\n", uniqueID, uniqueID);
    write(1, buffer, strlen(buffer));

    /* Child Process - Multiply array[uniqueID] by unique ID */
    newMem.ShmPTR[count] *= uniqueID;
    sprintf(buffer, "\t Child %d - Multiplying array element by %d.\n", uniqueID, uniqueID);
    write(1, buffer, strlen(buffer));

    /* Child Process - Display modified shared memory */
    sprintf(buffer, "\t Child %d - This is the modified shared memory: ", uniqueID);
    write(1, buffer, strlen(buffer));
    printSharedMem(newMem);

    /* Child Process - Complete, exit code 0 */
    sprintf(buffer, "\t Child %d - Process Complete, exiting with a code of 0.\n", uniqueID);
    write(1, buffer, strlen(buffer));
}

/**
 * @brief displays the shared memory
 *
 * @param newMem shared memory to be displayed
 */
void printSharedMem(sharedmem newMem)
{
    /*Initialize Variables*/
    int loopCounter = 0;      /*Loop counter variable*/
    char buffer[BUFFER_SIZE]=""; /* Output buffer */

    for(loopCounter = 0; loopCounter < newMem.size; loopCounter++)
    {
        if (loopCounter == newMem.size - 1)
        {
            sprintf(buffer, "%d\n", newMem.ShmPTR[loopCounter]);    
            write(1, buffer, strlen(buffer));
 
        }
        else
        {
            sprintf(buffer, "%d ", newMem.ShmPTR[loopCounter]);
            write(1, buffer, strlen(buffer));
 
        }
    }
}
