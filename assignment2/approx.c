/*=======================================================================
 |   Source code: approx.c  
 |   Author:      Anthony Perez
 |   Student ID:  5456512 
 |   Assignment:  Program #2 Approximation of e and square roots 
 |  
 |   Course:      COP4338 - Programming III  
 |   Section:     U04  
 |   Instructor:  William Feild  
 |   Due Date:    07 February 2017, at the beginning of class
 |
 |   I hereby certify that this collective work is my own
 |   and none of it is the work of any other person or entity.
 |	______________________________________ [Signature]
 |  
 |  Language:     C 
 |
 |  Compile/Run:  gcc -Wall approx.c -lm -lrt  
 | 
 |+-----------------------------------------------------------------------
 |  
 | Description: This program will display an approximation of the 
 |   exponential e using an infinite series. It will then show the 
 |   value of the exponential e using the math libraries.
 |   The program will then ask the user for a number  which it will
 |   then approximate the value of the square root using the Babylonian
 |   method. It will show the number of iterations and the time it took.
 |
 | 
 |  The exponential e will be computed using the formula:
 |                       
 |                         ∞
 |                     e = ∑  1/n!          
 |                        n=0               
 |
 |
 |  The Babylonian method uses the formula:
 |
 |                         ∞
 |                    √s = ∑  X_(n+1) = 1/2 * (X_n + (S/X_n))
 |                        n=0
 |
 |  Where X_0 is the initial "guess".
 |
 |
 |
 |  Input: The user is required to input a number.
 |    It is expected that the number will be a real number >= 0
 |  
 |  Output: This program will display the computed value for e,
 |   the <math.h>  expected value of e, the number of iterations it took
 |   to reach sixteen decimal-places, and the time in milliseconds that it
 |   took to compute. It will also include the computed value for the
 |   square root of a value input by the user, the number of iterations
 |   it took to reach sixteen decimal-place accuracy, and the time in
 |   milliseconds that it takes  to compute the square root. 
 |               
 |
 |  Example outputs:   
 |
 |     Estimated value of e: 2.718281828459045265424
 |     Expected value of e:  2.718281828459045235362
 |     Iterations: 300
 |     Time: 0.05 milliseconds
 |
 |     Please input a number to find the square root of: 30
 |
 |     Estimated value of Sqrt(30): 5.4772255750516611856435
 |     Expected value of Sqrt(30):  5.4772255750516611345696
 |     Iterations: 70
 |     Time: 1.32 milliseconds
 |
 |  
 |  Process: The Program's steps are as follows:
 |
 |  1.) The program will calculate e using the formula.  
 |  2.) The program will save the time and number of iterations needed  
 |  3.) The program will output the information to the terminal  
 |  4.) User is prompted to input a number to find the square root of
 |  5.) The program will estimate the square root using Babylonian
 |  method    
 |  6.) The program will save the time and number of iterations needed
 |  7.) The program will output the information to the terminal
 |
 |
 |  Required Features Not Included: All features are included. 
 |  
 |  Known Bugs: None; the program operates correctly.  
 |
 |*======================================================================*/

#include <stdio.h> /* Standard Input Output */
#include <ctype.h> /* Used for isdigit() check */
#include <math.h>  /* Used to get the expected value of e and sqrt */
#include <time.h>  /* Used for measuring task time */

 /* Defines / Constants */
#define NO_ERRORS 0      /* No Errors Returned */
#define MILLION   1000000.0   
#define SEC_TO_MS 1000.0 /* Convert Seconds to Milliseconds */

 /* http://stackoverflow.com/questions/5248915/execution-time-of-c-program
  * I attempted to use clock() to time the function time but it would return
  * 0 no matter what I did. Found timespec structure used in time.h */

 struct timespec start, stop; /*Only used to time code execution*/ 

 /* Function Prototypes*/
 int main(void);  
 void estimateExp(void);    /*Estimate Exponential Constant e*/
 double getFactorial(int);  /*Calculate Factorial*/
 void calculateSqrt(void);  /*Calculate SquareRoot*/
 double userInput(void);    /*Get User Input*/
 void clearGetChar(void);   /*Clear getchar() buffer*/



 /* Functions */

 /**
  * @brief main used to call the rest of the program
  *
  * @return 0 NO_ERRORS
  */
int main(void)
{

    estimateExp();
    calculateSqrt();

    return NO_ERRORS;
}

/**
 * @brief Estimate the exponential e to 16 decimal places.
 */
void estimateExp()
{
    /*Initializations ------------------------------------------------*/

    double elapsedTime = 0.0;  /*Elapsed time the function took       */ 
    double estimate = 0.0;     /*Working value for constant estimate  */
    double temp = 0.0;         /*Temporary storage for comparison(new)*/
    double oldTemp = 0.0;      /*Temporary storage for comparison(prev)*/
    int decimalPlaces = 0;     /*Targeted precision of the estimate   */
    int index = 0;             /*Working index as well as iterations  */
    int exit = 0;              /*Boolean flag to exit loop            */

    clock_gettime( CLOCK_MONOTONIC_RAW, &start);

    /*Calculate Constant e -------------------------------------------*/

    while(decimalPlaces < 16)
    {
        estimate += 1.0/getFactorial(index); 

        oldTemp = temp;
        temp = estimate;
        decimalPlaces = 0;
        exit = 0;

        do /* Begin Do Loop */
        {
            if (floor(oldTemp) == floor(temp))
            {
                oldTemp -= floor(oldTemp);
                oldTemp *= 10;
                temp -= floor(temp);
                temp *= 10;
                decimalPlaces++;
            }
            else
            {
                exit = 1; /*exit loop*/
            }
        } while(exit != 1 && decimalPlaces < 16); /* End Do */

        index++;    
    }
    /*Output Results ------------------------------------------------*/
    clock_gettime( CLOCK_MONOTONIC_RAW, &stop);
    elapsedTime = ((stop.tv_sec - start.tv_sec)*SEC_TO_MS 
            + fabs(stop.tv_nsec - start.tv_nsec))/MILLION;

    printf("\tEstimation of Exponential e\n"); 
    printf("----------------------------------------------\n");

    printf("Estimate:\t\t %6.25f \n", estimate);
    printf("Actual:  \t\t %6.25f \n", exp(1));
    printf("# of Iterations: \t %d\n", index); 
    printf("Execution time of: %.6f milliseconds.\n\n", elapsedTime);
}

/**
 * @brief Calculates the Factorial for the integer passed to the function 
 *
 * @param num the number that the factorial of will be found
 *
 * @return the factorial of num
 */
double getFactorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    if (num == 1)
    {
        return 1;
    }
    else
    {
        return (num * getFactorial(num-1));
    }
}

/**
 * @brief Calculates the square root of a number provided by the user
 */
void calculateSqrt()
{
    /*Initializations ----------------------------------------------*/

    double elapsedTime = 0.0; /*Elapsed time the function took*/
    double prevSquareRoot = 0.0; /*Previous calculated squareroot */
    double squareRoot = 0.0;     /*Current calculated squareroot */
    double workingNumber = 0.0;  /*Number provided for calculation*/
    double initialGuess = 0.0;   /*x_0 starting point babylonian formula*/
    double prevX = 0.0;          /*Previous X value in the formula*/
    double nextX = 0.0;          /*Next X value in the formula */   
    double tempSquareRoot = 0.0; /*Temporary storage for comparison*/
    int decimalPlaces = 0;       /*Targeted precision */
    int exit = 0;                /*Boolean exit flag */
    int iterations = 0;          /*Iteration count*/  

    clock_gettime( CLOCK_MONOTONIC_RAW, &start);

    printf("\tEstimation of the Square Root\n"); 
    printf("----------------------------------------------\n");


    workingNumber = userInput();
    initialGuess = 10 + (workingNumber / 100.0);
    prevX = initialGuess;


    /*Calculate Square Root -----------------------------------------*/

    while(decimalPlaces < 16)
    {
        nextX = (1.0/2.0) * (prevX + (workingNumber/prevX));
        prevX = nextX;
        prevSquareRoot = squareRoot;
        squareRoot = nextX;
        tempSquareRoot = squareRoot;

        do /* Begin Do Loop */
        {
            if (floor(tempSquareRoot) == floor(prevSquareRoot))
            {
                prevSquareRoot -= floor(prevSquareRoot);
                prevSquareRoot *= 10;
                tempSquareRoot -= floor(tempSquareRoot);
                tempSquareRoot *= 10;
                decimalPlaces++;
            }
            else
            {
                exit = 1;
            }
        } while(exit != 1 && decimalPlaces < 16); /* End Do */
        iterations++;
    }

    clock_gettime( CLOCK_MONOTONIC_RAW, &stop);
    elapsedTime = ((stop.tv_sec - start.tv_sec)*SEC_TO_MS 
            + fabs(stop.tv_nsec - start.tv_nsec))/MILLION;

    /*Output Results ------------------------------------------------*/

    printf("Estimated value of Sqrt(%0.0lf): %.20f\n",
            workingNumber, squareRoot);
    printf("Math.h value of Sqrt(%0.0lf): %.20f\n", 
            workingNumber, sqrt(workingNumber));
    printf("Number of Iterations: %d \n",iterations);
    printf("Execution time of: %.6f milliseconds \n", elapsedTime);

}


/**
 * @brief Gets the user input a non negative real number.
 *
 * @return non negative real number
 */
double userInput()
{
    int input = 0;
    int validInput = 0;
    double wholeNum = 0;
    while(!validInput)
    {
        wholeNum = 0;
        printf("Enter a real number greater than or equal to 0: ");
        input = getchar();

        while (input != '\n')
        {
            if(isdigit(input))
            {
                wholeNum = (wholeNum*10) + input - '0';
                input = getchar();
                validInput = 1;
            }
            else
            {
                printf("Invalid input detected. \n");
                clearGetChar();
                validInput = 0;
                input = '\n';
            }
        }
    }
    return wholeNum;
}

/**
 * @brief clears the getchar() buffer.
 */
void clearGetChar()
{
    while(getchar()!= '\n');
}
