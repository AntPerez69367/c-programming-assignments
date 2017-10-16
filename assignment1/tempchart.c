/*=============================================================================
  |   Source code: tempchart.c  
  |   Author:      Anthony Perez
  |   Student ID:  5456512 
  |   Assignment:  Program #1 Temperature Conversion Chart
  |  
  |   Course:      COP4338 - Programming III  
  |   Section:     U04  
  |   Instructor:  William Feild  
  |   Due Date:    24 January 2017, at the beginning of class
  |
  |   I hereby certify that this collective work is my own
  |   and none of it is the work of any other person or entity.
  |	______________________________________ [Signature]
  |  
  |  Language:     C 
  |  Compile/Run:  gcc tempchart.c -o Chart.out
  | 
  | +--------------------------------------------------------------------------
  |  
  |  Description: This program will display a temperature conversion chart 
  |               which shows the conversion from Fahrenheit to Celsius and
  |               Celsius to Fahrenheit. 
  |
  |               Range: -20.0 to +280
  |
  |               The user is asked to input the step which will determine
  |               how the chart increments
  |
  |               Formula used for conversion of Celsius to Fahrenheit:
  |
  |                                       9
  |               Temp_Fahr = Temp_Cel * --- + 32 
  |                                       5
  |
  |               Formula used for conversion of Fahrenheit to Celsius:
  |
  |                                              5
  |               Temp_Cel = (Temp_Fahr - 32) * ---
  |                                              9
  |              
  |  Input: The user is required to input the step factor. It is expected
  |               that the user will type a number between 1-9 using their 
  |               keyboard.  
  |  
  |  Output: This program will display a chart that will increase based on 
  |               the user input step.
  |
  |        Example output with step 5:   
  |
  |          Fahrenheit | Celsius                      Celsius | Fahrenheit  
  |         _________________________________________________________________  
  |
  |              -20.0  | -28.9                         -20.0  |  -4.0
  |              -15.0  | -26.1                         -15.0  |   5.0   
  |              -10.0  | -23.3                         -10.0  |  14.0
  |
  |  Process: The Program's steps are as follows:
  |
  |             1.) The program displays its purpose.  
  |             2.) The user is asked to input a step between 1-9  
  |             3.) The input is validated  
  |             4.) The temperature conversion is calculated
  |             5.) The temperature conversion is displayed
  |
  |
  |  Required Features Not Included: All features are included. 
  |  
  |  Known Bugs: None; the program operates correctly.  
  |
  |*=========================================================================*/

#include <stdio.h>
#include <ctype.h> /* Ch 2.7 introduced ctype.h used for isdigit() check */

/* Defines */
#define NO_ERRORS 0      /* No Errors of course */
#define MIN_TEMP -20     /* Lower bound temperature restriction */
#define MAX_TEMP 280     /* Upper bound temperature restriction */
#define MAX_LINE 1000    /* Maximum Input Length for User Input */

/* Declarations */
int GetStep();           /* Get the Step from the User */   
float FahrToCel(float);   /* Convert Fahrenheit to Celsius */
float CelToFahr(float);   /* Convert Celsius to Fahrenheit */
void displayChart(int);      /* Display the chart output to screen*/

int main()
{
	/* Declare and initialize variables */	
	int step = 0;      /* Step Unit*/

	printf("Welcome to the Temperature Conversion chart. \n");

	step = GetStep();
	displayChart(step);

	return NO_ERRORS;
}

/*---------------------------- GetStep() ----------------------------
  |  function GetStep ()
  |
  |  Purpose:  This function gets the step unit from the user and
  |     validates the input from getchar and converting it to an int by
  |     using step - '0'.
  |
  |  
  |  @return  step unit is returned. 
 *-------------------------------------------------------------------*/

int GetStep()
{
	/*Declare and initialize variables*/
	int step = 0;       /* Unit Step */
	int i = 0;          /* Iterator  */
	int temp = 0;       /* Temporary Storage */
	int validInput = 0; /* Boolean Validator*/
	int negativeFlag = 0; /* Flag for Negative Sign */ 

	/*Get and validate user input */
	while(validInput == 0)	
	{ 
		printf("Please enter a valid step factor[1-9]: ");
		for (i=0; i<MAX_LINE-1 && (temp=getchar()) !='\n'; ++i)
		{
			if ( temp == '-')
			{
				negativeFlag = 1;
			}
			step = temp;
		}
		if (isdigit(step) && step > '0' && !negativeFlag)
		{
			step = step - '0';
			validInput = 1;
		}
		else
		{
			printf("\nERROR: Invalid Input Detected.\n");
			negativeFlag = 0;
		}
	} 
	return step;
}

/*------------------------  CelToFahr  ------------------------------
  |  function CelToFahr (float)
  |
  |  Purpose:  This function receives a temp in Celsius and converts to
  |     Fahrenheit. 
  |  
  |  @return  fahren is the converted temperature which is returned. 
 *-------------------------------------------------------------------*/

float CelToFahr(float temp)
{
	/* declare and initialize variable */
	float fahren = temp * (9.0/5.0) + 32;

	return fahren;
}

/*------------------------  FahrToCel  ------------------------------
  |  function FahrToCel (float)
  |
  |  Purpose:  This function receives a temp in Farenheight and converts to
  |     Celsius. 
  |  
  |  @return  celsius is the converted temperature which is returned. 
 *-------------------------------------------------------------------*/

float FahrToCel(float temp)
{
	/*declare and initialize variable*/
	float celsius = (temp - 32) * (5.0/9.0);
	return celsius;

}

/*------------------------  displayChart  ------------------------------
  |  function displayChart (int step)
  |
  |  Purpose:  This function receives the step and outputs the chart while
  |  incrementing by the step
  |     
  |  
 *-------------------------------------------------------------------*/

void displayChart(int step)

{
	/*Declare and initialize variables */
	float i = 0.0;       /* Iterator */

	printf(" Fahrenheit |  Celsius \t\tCelsius   | Fahrenheit\n");
	printf(" _______________________________________________________\n");

	/* Iterate from MIN_TEMP to MAX_TEMP and display the Temp conversions */
	for(i = MIN_TEMP; i <= MAX_TEMP; i += step)
	{
		printf("    %6.1f  |  %6.1f \t  |-|\t",i, FahrToCel(i));
		printf(" %6.1f   |   %6.1f \n",i, CelToFahr(i));
	}
}

