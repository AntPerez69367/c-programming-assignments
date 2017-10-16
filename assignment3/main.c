/*==========================================================================
 * |   Source code: main.c validate.c deck.c deck.h 
 * |   Author:  Anthony Perez 
 * |   Student ID:  5456512  
 * |   Assignment:  Program #3 Deck of cards
 * |  
 * |   Course:  COP4338 - Programming III
 * |   Section:  U04 
 * |   Instructor:  William Feild  
 * |   Due Date:  Feb 21 2017, at the beginning of class
 * |
 * |        I hereby certify that this collective work is my own
 * |        and none of it is the work of any other person or entity.
 * |        ______________________________________ [Signature]
 * |  
 * |   Language:  C 
 * |   Compile/Run:
 * |        To compile using makefile run: make
 * |        To manually compile: gcc -o cards main.c validate.c deck.c deck.h
 * |        ./cards _ _  (num of cards, num of players)
 * |        example: ./cards 5 5
 * |
 * |
 * +----------------------------------------------------------------------  
 * |  
 * |  Description:  This program uses pointers to create a deck of 52 cards
 * |      it accepts command line arguments specifying how many players
 * |      and how many cards per player. It prints an unshuffled deck,
 * |      shuffles and then prints the shuffled deck, before finally dealing
 * |      the specified number of cards to the specified number of players.
 * |
 * |  Input:  This uses command line arguments. When the program is run two
 * |      arguments must be provided. The number of cards per player and the
 * |      number of players playing the game. Valid input is between 1-13 for
 * |      each field and cards * players can not exceed 52 cards.
 * |  
 * |  Output:  This program will output a list of 52 unshuffled cards in 
 * |      sequential order. It will then shuffle and reprint the list of 52 
 * |      cards to show they are now shuffled.
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
 * |       Player cards are limited to four cards per line for readability.
 * |  
 * |  Process: Program is split into main, validate and deck. main commands top
 * |       level functions only. validate is called by main to validate the command
 * |       line arguments and deck controls everything related to working with
 * |       the deck of cards. From main we initGameSpace() which is located in deck. 
 * |       this goes through the process of setting up a card game where it creates 
 * |       a new fresh unshuffled deck, shuffles that deck using a random number, and
 * |       deals the supplied number of cards to the supplied number of players from 
 * |       the deck. It then displays each players respective hand. This program makes
 * |       heavy usage of pointers to work with arrays. 
 * |  
 * |  Required Features Not Included:  All features included.
 * |  
 * |   Known Bugs: None. 
 * |
 * *===========================================================================*/

#include <stdio.h> /* Standard Input/Output */
#include <stdlib.h> /* Standard Library used for atoi */
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
    int validation = validate(argc, argv);
    int players = 0;
    int cards = 0;
    if (validation == INVALID_INPUT)
    {
        printf("\nInvalid Input, Terminating Program.\n");
        return INVALID_INPUT;
    }
    else{ 
    players = atoi(argv[2]);
    cards = atoi(argv[1]);
    /*Call game initialization*/
    initGameSpace(cards, players); 
    }
    return NO_ERRORS;

}
