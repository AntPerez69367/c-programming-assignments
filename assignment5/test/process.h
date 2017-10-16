#include <stdio.h> /*Standard IO*/
#include <stdlib.h>/*Standard Library*/
#include <limits.h>/*used for INT_MIN and INT_MAX*/

#define INVALID_INPUT -1 /*Invalid Input return*/
#define NO_ERRORS 0      /*No errors returned*/
#define TWENTY_NINE 29   
#define TWENTY_EIGHT 28
#define ONE 1
#define THIRTY_ONE 31
#define THIRTY 30

/*Months of the Year*/
enum Months {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

/*Boolean type*/
typedef enum boolean{
    False = 0,
    True = !False 
} boolean;

/*Function Prototypes*/
void processDates(int);
boolean validDate(int, int, double);

