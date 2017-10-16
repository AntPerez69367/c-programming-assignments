
/*=============================================================================  
 * |    Source code:  process.c process_funcs.c process.h 
 * |         Author:  Anthony Perez 
 * |     Student ID:  5456512  
 * |     Assignment:  Program #5 Redirection & Pipes
 * |  
 * |         Course:  COP4338 - Programming III  
 * |        Section:  U04
 * |     Instructor:  William Feild  
 * |       Due Date:  03/30/2017, at the beginning of class
 * |
 * |        I hereby certify that this collective work is my own
 * |        and none of it is the work of any other person or entity.
 * |            ______________________________________ [Signature]
 * |  
 * |       Language:  C 
 * |       Compile:   process.h must be in the directory
 * |                  gcc process.c process_funcs.c –o process
 * |           Run: ./process # (# must be an integer >= 0)
 * |         
 * |      To pipe input into ./convert and output to text file:
 * |                ./process < data.dat # | ./convert.dat > output.dat 
 * |  +-----------------------------------------------------------------------------  
 * |  
 * |  Description:  This program processes and validates each line to check for a 
 * |                valid date. If a valid date is found it prints it out, otherwise
 * |                the input is skipped. 
 * |                  
 * |        Input:  Command line argument supplied dictates how many valid dates need
 * |                to be processed. Input is taken from stdin and looks for a date
 * |                in the format of MM/DD/YYYY. Year can be from INT_MIN to INT_MAX. 
 * |  
 * |       Output:  The program will first output the # you put in the command line arg.
 * |                it will then output dates, after it has finished outputting dates it 
 * |                will out put "DONE" to indicate that it is finished processing.
 * |  
 * |      Process:  The program first checks the command line argument to know how much  
 * |                it needs to process. It then processes the stdin until it either reaches
 * |                the supplied count or reaches EOF. 
 * |  
 * |   Required Features Not Included:  None
 * |  
 * |   Known Bugs:  None
 * |
 * |  *===========================================================================*/

#include "process.h"

/**
 * @brief main function validates command line input and initiates the rest of the 
 * program
 *
 * @param argc command line argument count
 * @param argv[] command line arguments
 *
 * @return 
 */
int main(int argc, char* argv[])
{
    /*Initialize Variables*/
    int processNumber = 0;
 
    /*Validate number of arguments */
    if (argc != 2)
    {
        printf("Invalid number of command line arguments.\n");
        return INVALID_INPUT;
    }

    /*Validate that the input received was an integer*/
    if (sscanf(argv[1], "%d", &processNumber) != 1) 
    {
        printf("Invalid input detected. \n");
        return INVALID_INPUT;

    }
    /*Make sure integer is not negative*/
    if (processNumber < 0)
    {
        printf ("Invalid input detected. \n");
    }
    else
    {
        //printf("Success, processing dates.dat \n");
        processDates(processNumber);
    }
   
    return NO_ERRORS;
}
