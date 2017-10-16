#include "process.h" /*Custom header for program */

/**
 * @brief Processes the stdin searching for valid dates.
 *
 * @param numOfRecords the number of valid dates to process.
 */
void processDates(int numOfRecords)
{
    /* Initialize Variables */
    char *buffer = NULL; /*Buffer for input*/
    size_t size; /*size of buffer returns strlen*/
    int month;  /*month*/
    int day;    /*day*/
    double year;/*year*/
    int counter = 0; /*counter variable*/
    boolean complete = False; /*processing complete flag*/
    boolean limitFunc = False; /*flag for continuous or fixed processing*/


    if (numOfRecords > 0)
    {
        limitFunc = True;
    }
    printf("%d\n", numOfRecords);

    /*Process input ----------*/
    while(getline(&buffer, &size, stdin) > 0 &&  !complete) 
    {

        if (limitFunc) /*Fixed processing until counter reaches numOfRecords*/
        {
            if (sscanf(buffer, "%d/%d/%lf", &month, &day, &year)==3)
            {
                if(validDate(month, day, year))
                {
                    printf("%d/%d/%d\n", month, day, (int)year);
                    counter++;
                }
            }
            if(numOfRecords == counter)
            {
                complete = True;
            }
        }
        else /*Continuous processing until EOF*/
        {
            if (sscanf(buffer, "%d/%d/%lf", &month, &day, &year)==3)
            {
                if (validDate(month,day,year))
                {
                    printf("%d/%d/%d\n", month, day, (int)year);
                }
            }
        }
    }

    printf("DONE\n"); /* Completion */
}

/**
 * @brief Validates the date provided
 *
 * @param month the month
 * @param days  the day
 * @param year  the year
 *
 * @return True  if valid 
 *         False if invalid
 */
boolean validDate(int month,int days, double year)
{

    /*Initiate Variables*/
    boolean leapYear = False;  /*is a leap year flag*/
    boolean validYear = False; /*is a valid year flag*/
    boolean validMonth = False;/*is a valid month flag*/
    boolean validDay = False;  /*is a valid day flag*/

    /* Check if year is between INT_MIN and INT_MAX */
    if (year <= INT_MAX && year >= INT_MIN)
    {
        /*Check if the year is a leap year*/
        if ((int)year % 4 == 0)
        {
            if ((int)year % 100 == 0)
            {
                if ((int)year % 400 == 0)
                {
                    leapYear = True;
                }
                else 
                {
                    leapYear = False;
                }
            }
            else
            {
                leapYear = True;
            }
        }
        else
        {
            leapYear = False;
        }
        validYear = True;
    }
    else
    {
        return False;
    }

    /* Check if month is between 1 and 12 */
    if (month >= January && month <= December)
    {
        validMonth = True;

    }
    else
    {
        return False;
    }


    /* Check if the day is valid for that month */
    if (leapYear && month == February)
    {
        if (days <= TWENTY_NINE && days >= ONE)
        {
            validDay = True;
        }
        else
        {
            return False;
        }
    }
    else if (month == February)
    {
        if (days <= TWENTY_EIGHT && days >= ONE)
        {
            validDay = True;
        }
        else
        {
            return False;
        }
    }
    else if (month == April || month == June || month == September || month == November)
    {
        if (days <= THIRTY && days >= ONE)
        {
            validDay = True;
        }
        else
        {
            return False;
        }
    }
    else
    {
        if (days <= THIRTY_ONE && days >= ONE)
        {
            validDay = True;
        }
        else
        {
            return False;
        }
    }

    
    if (validYear && validMonth && validDay)
    {
        //   printf("Valid!");
        return True;
    }
    else
    {
        //   printf("Invalid");
        return False;
    }
}
