/* Includes */
#include <stdio.h>     /*Standard IO Library always required */ 
#include <stdlib.h>    /*Stdlib required for: atoi, calloc   */
#include <string.h>    /*String library used for strlen functions  */
#include <unistd.h>    /*Required for fork */
#include <sys/wait.h>  /*Used for wait() */
#include <sys/types.h> /* required for shared memory*/
#include <sys/ipc.h>   /* required for shared memory*/
#include <sys/shm.h>   /* required for shared memory*/

/* Defines */
#define INVALID_INPUT -1 /* Invalid input code */
#define ERROR -1         /* Error code */
#define NO_ERRORS 0      /* No Errors code*/
#define MAX_ARGUMENTS 7  /* Maximum command line arguments */
#define INPUT_OUT_OF_BOUNDS inputData[index] > 9 || inputData[index] < 0 /*Bounds for args*/
#define INVALID_ARGUMENT_COUNT argc > 8 || argc < 2 /*min and max argc counts*/
#define BUFFER_SIZE 500   /*Output buffer size */

/* Typedefs/Structures */
typedef struct sharedmem {
    int shm_id;  /*Shared memory id       */
    int *ShmPTR; /*Shared memory pointer  */
    int size; /*Size of the shared memory */
} sharedmem;

typedef struct childProc {
    pid_t pid;  /*Child process PID */
    int status; /*Child process exit status */
} process;

/* Function Prototypes */
int main(int, char**);
int* validateInput(int, char**, int*);
sharedmem allocateSharedMem(int, int*);
void spawnChildren(sharedmem);
void childProcess(int,sharedmem);
void printSharedMem(sharedmem);
