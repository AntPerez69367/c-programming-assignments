#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

/**
 * @brief Validate command line input
 * 
 * @param argc command line argument count
 * @param argv[] command line arguments
 *
 * @return valid or invalid
 */
int validate(int argc, char *argv[])
{
    /*Initialize Variables*/
    int cardsPerHand = 0;
    int numberOfHands = 0;

    /*Check argument count first*/
    if (argc != 3)
    {
        return INVALID_INPUT;
    }
    else
    {
        /* Validate Arguments */
        cardsPerHand = atoi(argv[1]);
        numberOfHands = atoi(argv[2]);

        /*Make sure there are appropriate values of players and hands*/
        if (cardsPerHand > MAX_HANDS || numberOfHands > MAX_PLAYERS)
        {
            return INVALID_INPUT;
        }
        if (cardsPerHand < MIN_HANDS || numberOfHands < MIN_PLAYERS)

        {
            return INVALID_INPUT;
        }
    }

    /* Ensure cards * players is less than max cards */
    if ((cardsPerHand * numberOfHands) > MAX_CARDS)
    {
        return INVALID_INPUT;
    }
}
