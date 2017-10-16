#include "convert.h"

/**
 * @brief gathers the data from stdin then processes the line and sends the data
 * to be converted and printed out.
 */
void gatherData()
{

    /*Initialize Variables */
    int numOfRecords = 0; /*Number of records expected to be processed*/
    boolean dataComplete = False; /*Boolean flag for completion*/
    int month = 0;   /*Month*/
    int day = 0;     /*Day*/
    int year = 0;    /*Year*/
    int counter = 0; /*Counter to keep track of processed records*/
    char endFlag[5] = ""; /*Codeword storage - "DONE" to complete processing */
    char *line = NULL;    /* getline Buffer */
    size_t size;          /* buffer size returns strlen pg103 */

    /* Gather number of records being passed */
    if (getline(&line, &size, stdin) == -1) 
    {
        printf("ERROR: No line\n");
    }
    else 
    {
        sscanf(line, "%d", &numOfRecords);
        if (numOfRecords == 0)
        {
            //printf("Successful Communication, receiving all records.\n");
            
            while(getline(&line, &size, stdin) >0 & !dataComplete)
            {
                if(sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
                {
                    convertDate(month, day, year);
                }
                else if(sscanf(line, "%5s", &endFlag) == 1)
                {
                    if (strcmp(endFlag, "DONE") == 0)
                    {
                        dataComplete = True;
                        appendDatFile();
                    }
                }
            }
        }
        else
        {
            while(!dataComplete)
            {
                getline(&line, &size, stdin);
                if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
                {
                    convertDate(month,day,year);
                    counter++;
                }
                /* If single string was scanned check if it says DONE*/
                else if(sscanf(line, "%5s", &endFlag) == 1)
                {
                    if (strcmp(endFlag, "DONE") == 0 && (counter == numOfRecords))
                    {
                        /*"DONE" detected .. end data processing */
                        dataComplete = True;
                        appendDatFile();
                    }
                    else
                    {
                        /* Throw error if data mismatch occured */
                        printf("Error Occured - endFlag: %s\n", endFlag);
                        printf("expected %d records,received %d records\n", 
                                numOfRecords, counter);
                        exit(-1);
                    }
                }
            }
        }
    }
}



/**
 * @brief Converts the month from a number into a string and rearrange
 * from MM/DD/YYYY to DD/MMM/YYYY
 *
 * @param month a month
 * @param day   a day
 * @param year  a year
 */
void convertDate(int month, int day, int year)
{
    printf("%02d %3s % -d\n", day, nameOfMonth[month], year);
}

/**
 * @brief reads from the file data.dat and prints out what it reads.
 */
void appendDatFile()
{
    /*Initialize Variables*/
    FILE *fp; /* Pointer to file being read */
    char line[MAX_SIZE]; /*Buffer*/


    printf ("[------------ORIGINAL DATA FROM DATA.DAT------------------]\n");

    /*Begin file operations ------------*/
    fp = fopen("dates.dat", "r");

    if (fp == NULL)
    {
        printf("ERROR OPENING FILE\n");
    }
    else
    {
    while(fgets(line, MAX_SIZE, fp) != NULL)
    {
        printf("%s", line);
    }

    fclose(fp);
    }
    /*End file operations ------------*/
    exit(0);
}
