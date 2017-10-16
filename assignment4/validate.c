#include "deck.h"


/**
 * @brief Validate command line input
 * 
 * @param argc command line argument count
 * @param argv[] command line arguments
 *
 * @return valid or invalid
 */

int validate(int numPlayers)
{
    /*Make sure there are appropriate values of players and hands*/
    if (numPlayers < MIN_PLAYERS || numPlayers > MAX_PLAYERS)
    {
        return INVALID_INPUT;
    }
}
