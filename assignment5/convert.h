#include <stdio.h> /*Standard IO Library*/
#include <stdlib.h>/*Standard Library */
#include <string.h>/*String Library used for strcmp()*/

/*Defines and Constants*/
#define NO_ERRORS 0 /*No Errors returned*/
#define MAX_SIZE 1000 /*Maximum Buffer Size*/

/*Names of the months*/
static const char *nameOfMonth[13] = {"none","JAN", "FEB", "MAR", "APR", "MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"}; 

/*Boolean type*/
typedef enum boolean{
    False = 0,
    True = !False 
} boolean;

/*Function Prototypes*/
void gatherData();
void convertDate(int,int,int);
void appendDatFile();
