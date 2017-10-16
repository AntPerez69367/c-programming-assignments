/* deck.c -------------------------------------------------------------------
 *    This file contains all the operations of the game which involve        |
 *  manipulating the poker deck. This includes, Creating the deck, Shuffling |
 *  the deck, Dealing the cards, and Ranking the Hands.                      |
 *--------------------------------------------------------------------------*/
#include "deck.h"

/* Card Text Lookup Arrays 
 * (Could not put into header file as it would not compile correctly) */
char *dFace[] = { "Ace", "Two","Three", "Four", "Five", 
    "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
char *dSuit[] = {"Hearts","Clubs","Diamonds","Spades"};

/**
 * @brief Initiates the gamespace by creating a new deck of cards, shuffling
 * the deck of cards, dealing to the players, sorting, ranking and displaying 
 * their hands.
 *
 * @param numOfPlayers Number of players per game.
 */
void initGameSpace(int numOfPlayers)
{
    /*Initialize Variables */
    Card myDeck[MAX_CARDS];
    Hand myHand[numOfPlayers];
    Hand testCases[MAX_TEST_CASES];

    /*Initialize deck to fresh unshuffled status*/
    newDeck(myDeck);

    /*Print fresh unshuffled deck*/
    printf("\nPrinting out unshuffled deck....\n");
    printDeck(myDeck);

    /*Shuffle fresh deck*/
    printf("\n\nShuffling deck...\n");
    shuffleDeck(myDeck);

    /*Print shuffled deck */
    printf("\nPrinting shuffled deck...\n");
    printDeck(myDeck);

    /*Deal cards to players*/
    dealCards(myHand, myDeck, numOfPlayers);

   /*Print player hands, without rankings*/
    printf("\n\n");
    printHands(myHand, numOfPlayers, False);

    /*Sort and print hands */
    printf("\nSorting Player Hands\n");
    sortHands(myHand, numOfPlayers);
    printHands(myHand, numOfPlayers, False);

    /*Rank and print results*/
    printf("\n\nRanking Player Hands\n");
    rankHands(myHand, numOfPlayers);
    printHands(myHand, numOfPlayers, True);

    /*Initialize Test Cases and Display*/
    printf("Initializing Test Cases and Displaying\n\n");
    createTestCases(testCases);
    sortHands(testCases, MAX_TEST_CASES);
    rankHands(testCases, MAX_TEST_CASES);
    printHands(testCases, MAX_TEST_CASES, True);
}

/**
 * @brief initializes a new deck into the unshuffled order
 *
 * @param deck Pointer to the deck structure being created
 *
 */
void newDeck(Card *deck)
{
    /*Initialize Variables */
    Face face = 0; /* Face enum ACE->King*/
    Suit suit = 0; /* Suit enum Hearts->Spades*/
    int cardNumber = 0; /* Current card being created */
 
    /*Initialize deck from 0 to Max_Cards */
    for (suit = Hearts; suit <= Spades; ++suit)
    {
      for (face = Ace; face <= King; ++face)
      {
        deck[cardNumber].cFace = face;
        deck[cardNumber].cSuit = suit; 
        cardNumber++;
      }
    }
}

/**
 * @brief Create test cases for hand ranking.
 *
 * @param testCase pointer to hand structure to be initialized 
 */
void createTestCases(Hand *testCase)
{  
    /* Flush */
    testCase[Flush].myCards[FIRST].cFace = Ace;
    testCase[Flush].myCards[FIRST].cSuit = Hearts;
    testCase[Flush].myCards[SECOND].cFace = Two;
    testCase[Flush].myCards[SECOND].cSuit = Hearts;
    testCase[Flush].myCards[THIRD].cFace = Three;
    testCase[Flush].myCards[THIRD].cSuit = Hearts;
    testCase[Flush].myCards[FOURTH].cFace = Four;
    testCase[Flush].myCards[FOURTH].cSuit = Hearts;
    testCase[Flush].myCards[FIFTH].cFace = Five;
    testCase[Flush].myCards[FIFTH].cSuit = Hearts;

    /* Straight  */
    testCase[Straight].myCards[FIRST].cFace = Six;
    testCase[Straight].myCards[FIRST].cSuit = Hearts;
    testCase[Straight].myCards[SECOND].cFace = Seven;
    testCase[Straight].myCards[SECOND].cSuit = Spades;
    testCase[Straight].myCards[THIRD].cFace = Eight;
    testCase[Straight].myCards[THIRD].cSuit = Hearts;
    testCase[Straight].myCards[FOURTH].cFace = Nine;
    testCase[Straight].myCards[FOURTH].cSuit = Clubs;
    testCase[Straight].myCards[FIFTH].cFace = Ten;
    testCase[Straight].myCards[FIFTH].cSuit = Hearts;


    /* Four of a Kind  */
    testCase[FourOfAKind].myCards[FIRST].cFace = Six;
    testCase[FourOfAKind].myCards[FIRST].cSuit = Hearts;
    testCase[FourOfAKind].myCards[SECOND].cFace = Six;
    testCase[FourOfAKind].myCards[SECOND].cSuit = Spades;
    testCase[FourOfAKind].myCards[THIRD].cFace = Six;
    testCase[FourOfAKind].myCards[THIRD].cSuit = Diamonds;
    testCase[FourOfAKind].myCards[FOURTH].cFace = Nine;
    testCase[FourOfAKind].myCards[FOURTH].cSuit = Clubs;
    testCase[FourOfAKind].myCards[FIFTH].cFace = Six;
    testCase[FourOfAKind].myCards[FIFTH].cSuit = Clubs;


    /* Full House  */
    testCase[FullHouse].myCards[FIRST].cFace = Six;
    testCase[FullHouse].myCards[FIRST].cSuit = Hearts;
    testCase[FullHouse].myCards[SECOND].cFace = Six;
    testCase[FullHouse].myCards[SECOND].cSuit = Spades;
    testCase[FullHouse].myCards[THIRD].cFace = Nine;
    testCase[FullHouse].myCards[THIRD].cSuit = Diamonds;
    testCase[FullHouse].myCards[FOURTH].cFace = Nine;
    testCase[FullHouse].myCards[FOURTH].cSuit = Clubs;
    testCase[FullHouse].myCards[FIFTH].cFace = Six;
    testCase[FullHouse].myCards[FIFTH].cSuit = Clubs;


    /* Three of a Kind  */
    testCase[ThreeOfAKind].myCards[FIRST].cFace = Six;
    testCase[ThreeOfAKind].myCards[FIRST].cSuit = Hearts;
    testCase[ThreeOfAKind].myCards[SECOND].cFace = Six;
    testCase[ThreeOfAKind].myCards[SECOND].cSuit = Spades;
    testCase[ThreeOfAKind].myCards[THIRD].cFace = Seven;
    testCase[ThreeOfAKind].myCards[THIRD].cSuit = Diamonds;
    testCase[ThreeOfAKind].myCards[FOURTH].cFace = Nine;
    testCase[ThreeOfAKind].myCards[FOURTH].cSuit = Clubs;
    testCase[ThreeOfAKind].myCards[FIFTH].cFace = Six;
    testCase[ThreeOfAKind].myCards[FIFTH].cSuit = Clubs;


    /* Two Pair  */
    testCase[TwoPair].myCards[FIRST].cFace = Six;
    testCase[TwoPair].myCards[FIRST].cSuit = Hearts;
    testCase[TwoPair].myCards[SECOND].cFace = Six;
    testCase[TwoPair].myCards[SECOND].cSuit = Spades;
    testCase[TwoPair].myCards[THIRD].cFace = Nine;
    testCase[TwoPair].myCards[THIRD].cSuit = Diamonds;
    testCase[TwoPair].myCards[FOURTH].cFace = Nine;
    testCase[TwoPair].myCards[FOURTH].cSuit = Clubs;
    testCase[TwoPair].myCards[FIFTH].cFace = Two;
    testCase[TwoPair].myCards[FIFTH].cSuit = Clubs;



    /* One Pair  */
    testCase[OnePair].myCards[FIRST].cFace = Six;
    testCase[OnePair].myCards[FIRST].cSuit = Hearts;
    testCase[OnePair].myCards[SECOND].cFace = Six;
    testCase[OnePair].myCards[SECOND].cSuit = Spades;
    testCase[OnePair].myCards[THIRD].cFace = Three;
    testCase[OnePair].myCards[THIRD].cSuit = Diamonds;
    testCase[OnePair].myCards[FOURTH].cFace = Nine;
    testCase[OnePair].myCards[FOURTH].cSuit = Clubs;
    testCase[OnePair].myCards[FIFTH].cFace = Five;
    testCase[OnePair].myCards[FIFTH].cSuit = Clubs;


    /* Nothing */
    testCase[HighCard].myCards[FIRST].cFace = Six;
    testCase[HighCard].myCards[FIRST].cSuit = Hearts;
    testCase[HighCard].myCards[SECOND].cFace = Two;
    testCase[HighCard].myCards[SECOND].cSuit = Spades;
    testCase[HighCard].myCards[THIRD].cFace = Ace;
    testCase[HighCard].myCards[THIRD].cSuit = Diamonds;
    testCase[HighCard].myCards[FOURTH].cFace = Nine;
    testCase[HighCard].myCards[FOURTH].cSuit = Clubs;
    testCase[HighCard].myCards[FIFTH].cFace = Jack;
    testCase[HighCard].myCards[FIFTH].cSuit = Clubs;
}

/**
 * @brief Shuffles the deck with a seeded random number using time.h.
 *
 * Shuffle method reference
 * https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
 *
 * @param deck Pointer to the deck structure.
 */
void shuffleDeck(Card *deck)
{
    /*Initialize Variables*/
    int counter = 0;         /* Counter for loop          */
    int randIndex = 0;       /* Random deck index         */
    Card randCard = {0,0};   /* Random Card being swapped */
    Card temp = {0,0};       /* Temporary swap storage    */


    /*Shuffle Algorithm selects a random card and swaps position
     * with the card located at the counter index 
     * Shuffle method used was discussed in class which is also discussed at
     * https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm */
    for (counter = 0; counter < MAX_CARDS; counter++)
    {
        randIndex = rand() % MAX_CARDS;
        randCard = deck[randIndex];
        temp = deck[counter];
        deck[counter] = randCard;
        deck[randIndex] = temp;
    }
}


/**
 * @brief Deals the cards from the top of the deck into the players hands in a one
 * to one fashion
 *
 * @param numOfPlayers Number of Players per Game
 * @param hand player hands structure
 * @param deck Pointer to the deck card structure array
 */
void dealCards(Hand *hand, Card *deck, int numOfPlayers)
{

    /* Initialize Variables */
    int card = 0;    /*The card number being dealt for the player*/
    int player = 0;  /*The player number being dealt a card */
    Card *deckPosition = &deck[FIRST]; /*Pointer to the first card in the deck */

    /* Deals each player a single card and repeats until all players have reached
     * the desired card count, The deck pointer keeps position of where we are
     * in the deck. */
    for (card = 0; card < FIVE_CARDS; card++)
    {
        for (player = 0; player < numOfPlayers; player++)
        {
            hand[player].myCards[card] = *deckPosition;      
            deckPosition++;
        }
    } 
}


/**
 * @brief Sort player hands using a bubble sort algorithm.
 *
 * https://en.wikipedia.org/wiki/Bubble_sort
 *
 * @param pHands pointer to player hands structure
 * @param players number of players
 */
void sortHands(Hand *pHands, int players)
{
    /* Initialization */
    Card tempSwap = {0,0}; /*Temporary Card structure for sorting swap*/
    int pCounter = 0;      /*Player counter             */
    int sortIndex = 0;     /*Sort run index             */
    int cCounter = 0;      /*Card counter               */

    /*Sort player hands*/
    for (pCounter = 0; pCounter < players; pCounter++)
    {
        /*Five Passes for each hand*/
        for (sortIndex = 0; sortIndex < FIVE_CARDS; sortIndex++)
        {
            /*Check if pair is out of order and swap them*/
            for(cCounter = 0; cCounter < FIVE_CARDS-1; cCounter++)
            {
                if (pHands[pCounter].myCards[cCounter].cFace > 
                        pHands[pCounter].myCards[cCounter+1].cFace)
                {
                    tempSwap = pHands[pCounter].myCards[cCounter+1];
                    pHands[pCounter].myCards[cCounter+1] = pHands[pCounter].myCards[cCounter];
                    pHands[pCounter].myCards[cCounter] = tempSwap;
                }
            }
        }
    }
}


/**
 * @brief Ranks the hands of each player
 *
 * @param pHands pointer to player hands
 * @param players number of players in the game
 */
void rankHands(Hand *pHands, int players)
{
    /* Player Counter and Top Score */
    int pCounter = 0;
    int topScore = 0;

    /* Test Case Parameters and Temp Case Variables */
    Boolean hasAce      = False;
    Boolean caseOne     = False;
    Boolean caseTwo     = False;
    Boolean caseThree   = False;

    /* Hand Ranking Flags */
    Boolean hasFlush    = False;
    Boolean hasStraight = False;
    Boolean hasFour     = False;
    Boolean hasFull     = False;
    Boolean hasThree    = False;
    Boolean hasTwo      = False;
    Boolean hasPair     = False;

    /* Analyze each hand and assign a ranking for each player */
    for(pCounter = 0; pCounter < players; pCounter++)
    {
        /* Detect if player has an Ace ------------------------------------*/
        hasAce = (pHands[pCounter].myCards[FIRST].cFace == Ace);

        /* Test for a Flush ----------------------------------------------*/
        hasFlush = ((pHands[pCounter].myCards[FIRST].cSuit == 
                    pHands[pCounter].myCards[SECOND].cSuit) && 
                (pHands[pCounter].myCards[SECOND].cSuit == 
                 pHands[pCounter].myCards[THIRD].cSuit) &&
                (pHands[pCounter].myCards[THIRD].cSuit ==
                 pHands[pCounter].myCards[FOURTH].cSuit) &&
                (pHands[pCounter].myCards[FOURTH].cSuit ==
                 pHands[pCounter].myCards[FIFTH].cSuit));

        /* Test for a Straight -------------------------------------------*/
        if(hasAce)
        {
            /* A 2 3 4 5 - Ace Low Test */
            caseOne = (pHands[pCounter].myCards[SECOND].cFace == Two   &&
                    pHands[pCounter].myCards[THIRD].cFace    == Three &&
                    pHands[pCounter].myCards[FOURTH].cFace    == Four  &&
                    pHands[pCounter].myCards[FIFTH].cFace    == Five);

            /* 10 J Q K A - Ace High Test */
            caseTwo = (pHands[pCounter].myCards[SECOND].cFace == Ten   &&
                    pHands[pCounter].myCards[THIRD].cFace    == Jack  &&
                    pHands[pCounter].myCards[FOURTH].cFace    == Queen &&
                    pHands[pCounter].myCards[FIFTH].cFace    == King);


            hasStraight = (caseOne || caseTwo);

        }
        else
        {
            /*Check if card value increasing. Next card should be 1 more than prev */
            hasStraight = ((pHands[pCounter].myCards[FIRST].cFace == 
                        pHands[pCounter].myCards[SECOND].cFace - 1) &&
                    (pHands[pCounter].myCards[SECOND].cFace  == 
                     pHands[pCounter].myCards[THIRD].cFace - 1) &&
                    (pHands[pCounter].myCards[THIRD].cFace ==
                     pHands[pCounter].myCards[FOURTH].cFace - 1) &&
                    (pHands[pCounter].myCards[FOURTH].cFace ==
                     pHands[pCounter].myCards[FIFTH].cFace - 1));
        }

        /* Test for Four of a Kind -----------------------------------*/

        /* X X X X Y */
        caseOne = ((pHands[pCounter].myCards[FIRST].cFace == 
                    pHands[pCounter].myCards[SECOND].cFace)   &&
                (pHands[pCounter].myCards[SECOND].cFace   == 
                 pHands[pCounter].myCards[THIRD].cFace)    &&
                (pHands[pCounter].myCards[THIRD].cFace    == 
                 pHands[pCounter].myCards[FOURTH].cFace)); 

        /* Y X X X X */
        caseTwo = ((pHands[pCounter].myCards[SECOND].cFace == 
                    pHands[pCounter].myCards[THIRD].cFace)   &&
                (pHands[pCounter].myCards[THIRD].cFace   == 
                 pHands[pCounter].myCards[FOURTH].cFace)    &&
                (pHands[pCounter].myCards[FOURTH].cFace    == 
                 pHands[pCounter].myCards[FIFTH].cFace)); 


        hasFour = (caseOne || caseTwo);


        /* Test for Full House ---------------------------------------------*/

        /* X X Y Y Y */
        caseOne = ((pHands[pCounter].myCards[FIRST].cFace == 
                    pHands[pCounter].myCards[SECOND].cFace)  &&
                ((pHands[pCounter].myCards[THIRD].cFace  == 
                  pHands[pCounter].myCards[FOURTH].cFace) &&  
                 (pHands[pCounter].myCards[FOURTH].cFace ==
                  pHands[pCounter].myCards[FIFTH].cFace)));

        /* X X X Y Y */
        caseTwo = ((pHands[pCounter].myCards[FOURTH].cFace == 
                    pHands[pCounter].myCards[FIFTH].cFace)  &&
                ((pHands[pCounter].myCards[FIRST].cFace  == 
                  pHands[pCounter].myCards[SECOND].cFace) &&  
                 (pHands[pCounter].myCards[SECOND].cFace ==
                  pHands[pCounter].myCards[THIRD].cFace)));


        hasFull = (caseOne || caseTwo);

        /* Test for Three of a Kind -----------------------------------------*/
        /* X X X - - */
        caseOne = ((pHands[pCounter].myCards[FIRST].cFace == 
                    pHands[pCounter].myCards[SECOND].cFace)  &&
                (pHands[pCounter].myCards[SECOND].cFace ==
                 pHands[pCounter].myCards[THIRD].cFace));

        /* - X X X - */
        caseTwo =  ((pHands[pCounter].myCards[SECOND].cFace == 
                    pHands[pCounter].myCards[THIRD].cFace)  &&
                (pHands[pCounter].myCards[THIRD].cFace ==
                 pHands[pCounter].myCards[FOURTH].cFace));

        /* - - X X X */
        caseThree =  ((pHands[pCounter].myCards[THIRD].cFace == 
                    pHands[pCounter].myCards[FOURTH].cFace)  &&
                (pHands[pCounter].myCards[FOURTH].cFace ==
                 pHands[pCounter].myCards[FIFTH].cFace));

        hasThree = (caseOne || caseTwo || caseThree);

        /* Test for Two Pair ----------------------------------------------*/

        /* X X Y Y - */
        caseOne = ((pHands[pCounter].myCards[FIRST].cFace    == 
                    pHands[pCounter].myCards[SECOND].cFace) &&
                (pHands[pCounter].myCards[THIRD].cFace ==
                 pHands[pCounter].myCards[FOURTH].cFace));

        /*- X X Y Y */
        caseTwo = ((pHands[pCounter].myCards[SECOND].cFace  ==
                    pHands[pCounter].myCards[THIRD].cFace)  && 
                (pHands[pCounter].myCards[FOURTH].cFace ==
                 pHands[pCounter].myCards[FIFTH].cFace));

        /*X X - Y Y*/
        caseThree =((pHands[pCounter].myCards[FIRST].cFace  ==
                    pHands[pCounter].myCards[SECOND].cFace)  && 
                (pHands[pCounter].myCards[FOURTH].cFace ==
                 pHands[pCounter].myCards[FIFTH].cFace));

        hasTwo = (caseOne || caseTwo || caseThree);

        /* Test for a Pair ------------------------------------------------*/

        /* (XX---) or (-XX--) or (--XX-) or (---XX) */
        hasPair =((pHands[pCounter].myCards[FIRST].cFace ==
                    pHands[pCounter].myCards[SECOND].cFace) ||
                (pHands[pCounter].myCards[SECOND].cFace  ==
                 pHands[pCounter].myCards[THIRD].cFace) || 
                (pHands[pCounter].myCards[THIRD].cFace  ==
                 pHands[pCounter].myCards[FOURTH].cFace) || 
                (pHands[pCounter].myCards[FOURTH].cFace  ==
                 pHands[pCounter].myCards[FIFTH].cFace));  

        /* Assign Hand its ranking ----------------------------------------*/
        if (hasFlush && hasStraight && hasAce)
        {
            pHands[pCounter].rank = "Royal Flush";
            pHands[pCounter].value = FLUSH + STRAIGHT + ACE_HIGH;

        
        }
        else if (hasFlush && hasStraight)
        {
            pHands[pCounter].rank = "Straight Flush";
            pHands[pCounter].value = FLUSH + STRAIGHT + HIGH_CARD;
        }
        else if (hasFlush)
        {
            pHands[pCounter].rank = "Flush";
            pHands[pCounter].value = FLUSH + HIGH_CARD;
        }
        else if (hasStraight)
        {
            pHands[pCounter].rank = "Straight";
            pHands[pCounter].value = STRAIGHT + HIGH_CARD;
        }
        else if (hasFour)
        {
            pHands[pCounter].rank = "Four of a Kind";
            pHands[pCounter].value = FOUR_OF_A_KIND + HIGH_CARD;
        }
        else if (hasFull)
        {
            pHands[pCounter].rank = "Full House";
            pHands[pCounter].value = FULL_HOUSE + HIGH_CARD;
        }
        else if (hasThree)
        {
            pHands[pCounter].rank = "Three of a Kind";
            pHands[pCounter].value = THREE_OF_A_KIND + HIGH_CARD;
        }
        else if (hasTwo)
        {
            pHands[pCounter].rank = "Two pair";
            pHands[pCounter].value = TWO_PAIR + HIGH_CARD;
        }
        else if (hasPair)
        {
            pHands[pCounter].rank = "One Pair";
            pHands[pCounter].value = ONE_PAIR + HIGH_CARD;
        }
        else
        {   if(hasAce)
            {
             pHands[pCounter].rank = "Ace";
             pHands[pCounter].value = ACE_HIGH;
            }
            else
            {
            pHands[pCounter].rank = dFace[HIGH_CARD];
            pHands[pCounter].value = HIGH_CARD;
            }
        }
    }

    /* Determine winner using hand .value to find topScore */
    for (pCounter = 0 ; pCounter < players; pCounter++)
    {
        if (pHands[topScore].value <= pHands[pCounter].value)
        {
            pHands[topScore].winner = False;

            topScore = pCounter;
            pHands[pCounter].winner = True;

        }
        else
        {
            pHands[pCounter].winner = False;
        }
    }
}


/**
 * @brief Print each players hand. Optional: Print ranked hands or unranked 
 *
 * @param pHands pointer to player hands structure
 * @param players number of players
 * @param ranked flag to print ranked hands or unranked hands
 *               False = Unranked
 *               True = Ranked
 */
void printHands(Hand *pHands, int players, Boolean ranked)
{
    /*Initialize Variables*/
    int pCounter = 0;  /*Player Counter*/
    int cCounter = 0;  /*Card Counter*/

    if(ranked)
    {
        /*For each player print their cards*/
        for (pCounter = 0; pCounter < players; pCounter++)
        {
            if(pHands[pCounter].winner)
            {
                printf("\nPlayer %d *WINNER*|-------------------------------------------------",
                        pCounter + 1);
            }
            else
            {
                printf("\nPlayer %d |---------------------------------------------------------",
                        pCounter + 1);
            }

            printf("\n\t | Hand Rank: %-10s \t Value: %-10d \t  | \n\t",
                    pHands[pCounter].rank, pHands[pCounter].value);
            printf(" |---------------------------------------------------------  ");
            
            for (cCounter = 0; cCounter < FIVE_CARDS; cCounter++)
            {
                /*New line on every fourth card */
                if ((cCounter % FOURTH) == 0)
                {
                    printf("\n\t | ");
                }
                /*Stops the , from showing on the last card printed*/
                if(cCounter == FIVE_CARDS-1)
                {
                    printf(" %s of %s" , 
                            dFace[pHands[pCounter].myCards[cCounter].cFace],
                            dSuit[pHands[pCounter].myCards[cCounter].cSuit]);
                }
                /*Prints the other cards*/
                else{
                    printf(" %s of %s," , dFace[pHands[pCounter].myCards[cCounter].cFace],
                            dSuit[pHands[pCounter].myCards[cCounter].cSuit]);
                } 
            }
        }
        printf("\n\t |--------------------------------------------------------|\n");

    }
    else
    {
        /*For each player print their cards*/
        for (pCounter = 0; pCounter < players; pCounter++)
        {
           printf("\nPlayer %d |------------------------------------------------------------|",
                        pCounter + 1);
            
           for (cCounter = 0; cCounter < FIVE_CARDS; cCounter++)
            {
           
                /*New line for the fourth card*/
                if ((cCounter % FOURTH) == 0)
                {
                    printf("\n\t | ");
                }

                /*Stops the , from showing on the last card printed*/
                if(cCounter == FIVE_CARDS-1)
                {
                    printf(" %s of %s" , 
                            dFace[pHands[pCounter].myCards[cCounter].cFace],
                            dSuit[pHands[pCounter].myCards[cCounter].cSuit]);
                }
                /*Prints the other cards*/
                else{
                    printf(" %s of %s," , dFace[pHands[pCounter].myCards[cCounter].cFace],
                            dSuit[pHands[pCounter].myCards[cCounter].cSuit]);
                } 
            }
            printf("\n\t |------------------------------------------------------------|\n");
        }
    }
}

/**
 * @brief Prints the deck
 *
 * @param deck Pointer to the deck structure
 */
void printDeck(Card *deck)
{

    /*Initialize Variables */
    int counter = 0;   /*Simple Counter*/

    /*Print all cards */
    for (counter = 0; counter < MAX_CARDS; counter++)
    {

        /* New line after printing four cards */
        if(counter % FOUR_CARDS == 0)
        {

            printf("\n");
        }

        printf("%s of %-9s\t", dFace[deck[counter].cFace], dSuit[deck[counter].cSuit]);
    }

    printf ("\n");
}
