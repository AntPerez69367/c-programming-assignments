#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deck.h"

/* Identify Card Face using Number % CARDS_PER_SUIT */
const char *face[CARDS_PER_SUIT] = { "Ace", "Two","Three", "Four", "Five", 
    "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

/* Identify Card Suit using Number / CARDS_PER_SUIT */
const char *suit[SUITS_PER_DECK] = {"Hearts","Clubs","Diamonds","Spades"};

/**
 * @brief Initiates the gamespace by creating a new deck of cards, shuffling
 * the deck of cards, dealing to the players and displaying their hands.
 *
 * @param cardsPerHand Number of cards per hand.
 * @param numOfPlayers Number of players per game.
 */
void initGameSpace(int cardsPerHand, int numOfPlayers)
{
    /*Initialize Variables */
    int *pHands[MAX_CARDS]; /*Pointer to player hands*/
    int deck[MAX_CARDS];    /*Deck of Cards Array*/
    int *dp = &deck[0];     /*Pointer to the beginning of the deck*/

    /*Initialize deck to fresh unshuffled status*/
    newDeck(dp);

    /*Print fresh unshuffled deck*/
    printf("\nPrinting out unshuffled deck....\n");
    printDeck(dp);

    /*Shuffle fresh deck*/
    printf("\n\nShuffling deck...\n");
    shuffleDeck(dp);

    /*Print shuffled deck */
    printf("\nPrinting shuffled deck...\n");
    printDeck(dp);

    /*Deal X cards to Y players*/
    dealCards(cardsPerHand, numOfPlayers, pHands, dp);
    
    /*Print player hands*/
    printf("\n\n");
    printHands(numOfPlayers, cardsPerHand, pHands);
}


/**
 * @brief Deals the cards from the top of the deck into the players hands in a one
 * to one fashion
 *
 * @param numOfCards Number of Cards per Hand
 * @param numOfPlayers Number of Players per Game
 * @param phands Pointer to player hands
 * @param dp Pointer to deck
 */
void dealCards(int numOfCards, int numOfPlayers ,int **phands, int *dp)
{
    /* Initialize Variables */
    int cardCount = 0;    /*The card number being dealt for the player*/
    int playerCount = 0;  /*The player number being dealt a card */

    /*Deals each player a single card and repeats until all players have reached
     * the desired card count*/
    for (cardCount = 0; cardCount < numOfCards; cardCount++)
    {
        for (playerCount = 0; playerCount < numOfPlayers; playerCount++)
        {
            *((phands + playerCount) + cardCount) = dp;
            dp++;
        }
    } 
}


/**
 * @brief Shuffles the deck with a seeded random number.
 *
 * @param dp Pointer to the deck.
 */
void shuffleDeck(int *dp)
{
    /*Initialize Variables*/
    srand(time(NULL));  /*Seed Random with Time*/
    int counter = 0;    /*Counter for loop*/
    int randCard = 0;   /*RandomCard location to swap with*/
    int temp = 0;       /*Temporary swap storage */


    /*Shuffle Algorithm selects a random card and swaps position
     * with the card located at the counter index */
    for (counter = 0; counter < MAX_CARDS; counter++)
    {
        randCard = rand() % MAX_CARDS;
        temp = *(dp + counter);
        *(dp + counter) = *(dp + randCard);
        *(dp + randCard) = temp;
    }
}

/**
 * @brief initializes a new deck into the unshuffled order
 *
 * @param dp Pointer to the deck being renewed
 *
 */
void newDeck(int *dp)
{
    /*Initialize Variables */
    int counter = 0; /*Simple counter*/

    /*Initialize deck from 0 to Max_Cards */
    for (counter = 0; counter < MAX_CARDS; counter++)
    {
        *(dp + counter) = counter;
    }
}


/**
 * @brief Prints the deck
 *
 * @param dp Pointer to the deck
 */
void printDeck(int *dp)
{

    /*Initialize Variables */
    int counter = 0;   /*Simple Counter*/

    /*Print all cards */
    for (counter = 0; counter < MAX_CARDS; counter++)
    {
        if(counter % 4 == 0)
        {
            printf("\n");
        }
        printf("%s of %-9s\t",
                face[*(dp + counter)%CARDS_PER_SUIT],
                suit[*(dp+counter)/CARDS_PER_SUIT]);
    }
}


/**
 * @brief Print each players hand
 *
 * @param players Number of players 
 * @param cards   Number of cards per player
 * @param phands  Pointer to player hands
 */
void printHands(int players, int cards, int **phands)
{
    /*Initialize Variables*/
    int pCounter = 0;  /*Player Counter*/
    int cCounter = 0;  /*Card Counter*/

    /*For each player print their cards*/
    for (pCounter = 0; pCounter < players; pCounter++)
    {
        printf("\nPlayer %d |-----------------------------------------------------------------\n \t",
                pCounter + 1);
        for (cCounter = 0; cCounter < cards; cCounter++)
        {
            /*Limits the output to four cards per line*/
            if(cCounter % 4 == 0 && (cCounter != 0))
            {
                printf("\n \t");
            }

            /*Stops the , from showing on the last card printed*/
            if(cCounter == cards-1)
            {
                printf(" %s of %s" , 
                        face[*(*(phands + pCounter) + cCounter)%CARDS_PER_SUIT],
                        suit[*(*(phands + pCounter) + cCounter)/CARDS_PER_SUIT]);
            }
            /*Prints the other cards*/
            else{
                printf(" %s of %s," , 
                        face[*(*(phands + pCounter) + cCounter)%CARDS_PER_SUIT],
                        suit[*(*(phands + pCounter) + cCounter)/CARDS_PER_SUIT]);
            } 
        }
        printf("\n");
    }
}

