/* Includes -----------------------------------------------------------*/
#include <stdio.h>  /*Standard IO Library for input/output functions   */
#include <stdlib.h> /*Standard Function Library for atoi               */
#include <time.h>   /*Time functions library. Used for time_t          */
/*---------------------------------------------------------------------*/
/* Definitions---------------------------------------------------------*/
/*|- Used in studpokermain.c ---------------------------------------------------*/
#define VALID_ARGC (argc == 3)       /* Valid argc count               */
#define NUM_OF_PLAYERS atoi(argv[2]) /* Number of players              */
#define MAX_PLAYERS 7                /* Maximum number of players      */ 
#define MIN_PLAYERS 1                /* Minimum number of players      */
#define NO_ERRORS 0                  /* No Errors                      */
#define INVALID_INPUT -1             /* Invalid Input Detected         */
/*---------------------------------------------------------------------*/
/*|- Used in deck.c ---------------------------------------------------*/
#define FIRST 0                      /* First card in the hand         */
#define SECOND 1                     /* Second card in the hand        */
#define THIRD 2                      /* Third card in the hand         */
#define FOURTH 3                     /* Fourth card in the hand        */
#define FIFTH 4                      /* Fifth card in the hand         */
#define MAX_CARDS 52                 /* Number of cards in a deck      */
#define FIVE_CARDS 5                 /* Five cards                     */
#define FOUR_CARDS 4                 /* Four Cards                     */
#define CARDS_PER_SUIT 13            /* Number of Cards per Suit       */
#define SUITS_PER_DECK 4             /* Number of Suits per Deck       */
#define MAX_TEST_CASES 8             /* Number of test cases created   */
#define HIGH_CARD pHands[pCounter].myCards[4].cFace /*Last card in hand*/
/*---------------------------------------------------------------------*/
/*|- Hand Rankings ----------------------------------------------------*/
#define FLUSH 100                    /* Point values for a flush       */
#define STRAIGHT 90                  /*   -     -     -  a straight    */
#define FOUR_OF_A_KIND 80            /*   -     -     -  4 of a kind   */
#define FULL_HOUSE 70                /*   -     -     -  a full house  */
#define THREE_OF_A_KIND 60           /*   -     -     -  3 of a kind   */
#define TWO_PAIR 50                  /*   -     -     -  two pairs     */
#define ONE_PAIR 40                  /*   -     -     -  one pair      */
#define ACE_HIGH 14                  /*   -     -     -  Ace high      */
/*---------------------------------------------------------------------*/
/* Deck.c Structures --------------------------------------------------*/
/*Structure for a playing card   */
struct card{
   int cFace; /* Card face value */
   int cSuit; /* Card suit value */
};
/* Structure for a hand of cards  */
struct hand{
   struct card myCards[FIVE_CARDS]; /*Five cards per hand*/ 
   char *rank; /* Hand Rank   */
   int value;  /* Rank Value  */
   int winner; /* Winner flag */
};

enum cardSuits {
    Hearts = 0,
    Clubs,
    Diamonds,
    Spades
};

enum cardFaces {
    Ace =   0,
    Two,
    Three,
    Four,    
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

enum testCases{
    Flush = 0,
    Straight,
    FourOfAKind,
    FullHouse,
    ThreeOfAKind,
    TwoPair,
    OnePair,
    HighCard
};

enum Boolean{
    False = 0,
    True = 1
};


/* Custom data types */
typedef enum Boolean Boolean;  
typedef enum cardFaces Face;
typedef enum cardSuits Suit;
typedef struct card Card; 
typedef struct hand Hand;

/* Main.c Function Prototypes */
int main (int, char*[]);

/* Deck.c Function Prototypes */
void initGameSpace(int);
void newDeck(Card *);
void createTestCases(Hand *);
void shuffleDeck(Card *);
void dealCards(Hand *, Card *,  int);
void sortHands(Hand *, int);
void rankHands(Hand *, int);
void printDeck(Card *);
void printHands(Hand *, int, Boolean);
