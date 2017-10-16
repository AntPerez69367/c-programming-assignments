#include <stdio.h>

/*  Definitions  */
/** I would change upper and lower to 
 *   *#define UPPER 280   /* comment here about what upper is 
 *     *#define LOWER -20  /* comment here about what lower is 
 *       *#define NO_ERRORS 0 
 *         */ 
float fahren, cels, upper = 280.0, lower = -20.0; /*can probably define these in the function that uses them and pass as arguments*/

/* Declarations  */
/* need to declare your functions up here
 * * int userPromt();
 * * float conversionChart(float, float);
 * **/
int step; /*move into main and pass as an argument to display */


main() /* needs to be int main() */
{

	/*int step = 0;   always initialize when you declare even if its just to 0*/
	int userPrompt();    /* step = userPrompt(); */
	conversionChart();  /* move function into display function */
	displayChart();        /* displayChart(step); pass step to the displayChart 

	/*return 0 or NO_ERRORS if you define NO_ERRORS as 0 at the top*/
}


/*
 * Prompts the user for step increment.
 * uses if statements to validate the user's input.
 * */
int userPrompt()
{

	do
	{
		printf("Enter step increment number: ");
		step = getchar();

		if(step > '9' || step < '1')
		{
			printf("Invalid. Enter a number between 1 and 9.\n");
		}
		else if(step == ' ' || step == '\n' || step == '\t')
		{
			printf("Invalid. Enter a valid integer.\n");
		}	
		else
		{
			step = step - '0';
		}


	}while(step > '9' || step < '1' || step == ' ' 
			|| step == '\n' || step == '\t');


	return step;
}

/*
 * convert cels to fahr and fahr to cels using the equation for celsius and the 
 * step increment the user has input. 
 *
 * */

/* I would scrap this entire function and replace it with ConvertToCelsius(float whatever) and ConvertToFahr(float whatever) */
float conversionChart(float fahren, float cels)
{

	while(fahren <= upper)
	{
		cels = (5.0 / 9.0) * (fahren - 32.0);

		for(fahren = 0; fahren <= upper; fahren = fahren + step)
		{
			printf("%3.1f %6.1f\n", fahren, cels);
		}
	}

	return fahren;
}

/** ConvertToCelsius(float fahren)
 * *{
 * *    float cels = conversion formula * fahren;
 * * return cels;
 * *}
 * */

/** ConvertToFahren(float cels)
 * *{
 * *    float fahren = conversion formula * cels;
 * * return fahren;
 * *}
 * */

public void displayChart() /** public is for java just do void displayChart(int step) **/
{
	/** directly display here by calling ConvertToCelsius and ConvertToFahren **/
	printf("Fahrenheit \t Celscius \t\t\t Celscius \t Fahrenheit\n");
	printf("---------------------------------------------------------------------------------\n");
	printf(fahr, cels "\t\t\t" fahr, cels);  
	/** float i = 0.0;
	 * 	/** float temp = 0.0;
	 * 		/** for(i = LOWER; i < UPPER; i += step )
	 * 			/** printf("%6.1f   %6.1f  \t\t\t   %6.1f %6.1f", i, ConvertToCelsius(i), i, ConvertToFahren(i)); */
}
