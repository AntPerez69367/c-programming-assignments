/*==========================================================================
 * |   Source code: studpokermain.c deck.c deck.h 
 * |   Author:  Anthony Perez 
 * |   Student ID:  5456512  
 * |   Assignment:  Program #4 Five card stud poker
 * |  
 * |   Course:  COP4338 - Programming III
 * |   Section:  U04 
 * |   Instructor:  William Feild  
 * |   Due Date:  Mar 9 2017, at the beginning of class
 * |
 * |        I hereby certify that this collective work is my own
 * |        and none of it is the work of any other person or entity.
 * |        ______________________________________ [Signature]
 * |  
 * |   Language:  C 
 * |   Compile/Run:
 * |        To compile using makefile run: make
 * |        To manually compile: gcc -o cards studpokermain.c deck.c
 * |        deck.h must be in the main directory with studpokermain.c and deck.c
 * |        To run: ./cards _ _  (num of cards, num of players)
 * |        example: ./cards 5 5
 * |
 * |
 * +----------------------------------------------------------------------  
 * |  
 * |  Description:  This program uses structures to create a deck of 52 cards
 * |      it accepts command line arguments specifying how many players
 * |      and how many cards per players. It prints an unshuffled deck,
 * |      shuffles and then prints the shuffled deck, before finally dealing
 * |      five cards to the specified number of players. Each player hand is then
 * |      sorted and ranked based on the cards they have. The player with the
 * |      highest ranking is labelled as the winner.
 * |
 * |  Input:  This uses command line arguments. When the program is run two
 * |      arguments must be provided. The number of cards per player and the
 * |      number of players playing the game. Valid input is between 1-7 for
 * |      each field and cards * players can not exceed 52 cards.
 * |  
 * |  Output:  This program will output a list of 52 unshuffled cards in 
 * |      sequential order. It will then shuffle and reprint the list of 52 
 * |      cards to show they are now shuffled. It will then deal the cards to 
 * |      each player, display the hands, sort the hands, rank the hands, and
 * |      re-display them again.
 * |
 * |    Example: 
 * |      Ace  of Hearts    Two of Hearts    Three of Hearts   Four  of Hearts    
 * |      Five of Hearts    Six of Hearts    Seven of Hearts   Eight of Hearts
 * |      etc.. etc..
 * |
 * |      shuffling cards....
 * |
 * |      Six of Spades    Three of Clubs    Six of Hearts    Ace of Diamonds
 * |      etc.. etc..
 * |
 * |
 * |      Player hands will print out:
 * |
 * |  Player # | -------------------------------------------------------------
 * |             Card 1    Card 2     Card 3    Card 4
 * |             Card 5    Card ...   Card n
 * |
 * |      
 * |  
 * |  Process: Program is split into main and deck. main commands top
 * |       level functions only and validates the command line arguments as well. 
 * |       Deck controls everything related to working with the deck of cards. 
 * |       From main we initGameSpace() which is located in deck. 
 * |       this goes through the process of setting up a card game where it creates 
 * |       a new fresh unshuffled deck, shuffles that deck using a random number, and
 * |       deals the cards to the players from the deck. It then displays each 
 * |       players respective hand, Sorts and ranks the hand and re-displays it.
 * |       This program makes usage of structures.   
 * |  
 * |  Required Features Not Included:  All features included.
 * |  
 * |  Known Bugs: Ranking is based on the total hand and not individual cards.
 * |       For example a pair of 2's and a pair of 6's will rank similarly even
 * |       though the pair of 6's should have be a higher ranking. 'ties' such as these
 * |       are judged by the highest card in the hand being added to the point value.
 * *===========================================================================*/

#include "deck.h"

/**
 * @brief enter program execution
 *
 * @param argc  command line argument count
 * @param argv[] command line arguments
 *
 * @return no errors if successful 
 */
int main (int argc, char* argv[])
{
    /*Initialization */
    time_t t; /* Seed random number generation with time t */
    srand((unsigned)time(&t));

    /* Validation of runtime arguments */
    if (VALID_ARGC)
    {
       int players = NUM_OF_PLAYERS;
        
        if ((NUM_OF_PLAYERS > MAX_PLAYERS) || (NUM_OF_PLAYERS < MIN_PLAYERS))
        {
            printf("\nInvalid Input, Terminating Program.\n");
            return INVALID_INPUT;
        }

        /*Call game initialization*/
        initGameSpace(players); 
        return EXIT_SUCCESS;
    }
    else
    {
        printf("\nInvalid Input, Terminating Program.\n");
        return INVALID_INPUT;
    }

    /* Program should never reach this, if it does something wrong happened.*/
    /* EXIT_FAILURE is a constant defined in stdlib.h */
    return EXIT_FAILURE;
}
