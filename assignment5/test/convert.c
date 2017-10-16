
/*=============================================================================  
 * |    Source code:  convert.c convert_funcs.c convert.h
 * |         Author:  Anthony Perez 
 * |     Student ID:  5456512  
 * |     Assignment:  Program #5 Redirection & Pipes
 * |  
 * |         Course:  [COP4338 - Programming III ]  
 * |        Section:  [U04]  
 * |     Instructor:  William Feild  
 * |       Due Date:  [03/30/2017], at the beginning of class
 * |
 * |        I hereby certify that this collective work is my own
 * |        and none of it is the work of any other person or entity.
 * |            ______________________________________ [Signature]
 * |  
 * |       Language:  C 
 * |        Compile:  convert.h must be in the directory
 * |                  gcc convert.c convert_funcs.c –o convert
 * |            Run:  ./convert
 * |
 * |      To pipe input into ./convert and output to text file:
 * |                ./process < data.dat # | ./convert.dat > output.dat 
 * | 
 * |  +-----------------------------------------------------------------------------  
 * |  
 * |    Description:  This program receives a date in the format of MM/DD/YYYY 
 * |                 and converts it into a different format. 
 * |                  
 * |        Input:   Input is normally piped in from the process sister program.
 * |                 which validates the input.
 * |                 if not not piping input from the sister program and manually
 * |                 supplying the input it must be a valid date and in the format:
 * |
 * |                 (The first input must be the number of dates being supplied.
 * |                  0(default) will process dates until you type the keyword DONE. )  
 * |
 * |                 ./convert            OR        ./convert
 * |                 5                              0 
 * |                 01/01/2000                     1/01/2000
 * |                 02/01/25050                    2/25/2001
 * |                 5/13/190                       DONE
 * |                 1/01/0 
 * |                 2/2/-545440
 * | 
 * |  
 * |       Output:  01 JAN  2000                    01 JAN 2000
 * |                01 FEB  25050                   25 FEB 2001
 * |                13 MAY  190 
 * |                01 JAN  0
 * |                02 FEB -545440
 * |                -------DATA.DAT CONTENTS
 * |                ...etc
 * |                ...etc
 * |  
 * |     Process:  The program expects to be told how many records are going to be passed 
 * |               to it. This is done through the stdin. The program reads the stdin line
 * |               by line. The first line it expects a #, if no # is found it defaults to 0
 * |               which is unlimited processing until it is told it is done. This is done 
 * |               by reading the string "DONE" from stdin. When the program detects this 
 * |               string is stops processing input and begins appending the data.dat to 
 * |               output.
 * |  
 * |   Required Features Not Included:  All features should be included.
 * |  
 * |   Known Bugs:  If run without the sister program it does not validate input
 * |             
 * |
 * |
 * | *===========================================================================*/

#include "convert.h"

/**
 * @brief main initiates the rest of the program.
 *
 * @return NO_ERRORS
 */
int main()
{
    gatherData();

    return NO_ERRORS;
}


