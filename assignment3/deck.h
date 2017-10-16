/* Definitions */
#define MAX_CARDS 52
#define CARDS_PER_SUIT 13
#define SUITS_PER_DECK 4
#define MAX_HANDS 13
#define MIN_HANDS 1
#define MAX_PLAYERS 13
#define MIN_PLAYERS 1
#define NO_ERRORS 0      /* No Errors */ 
#define INVALID_INPUT -1 /* Invalid Input Detected    */


/* Main.c Function Prototypes */
int main (int, char*[]);

/* Validate.c Function Prototypes */
int validate(int, char*[]);

/* Deck.c Function Prototypes */
void initGameSpace(int, int);
void dealCards(int, int, int**, int*);
void shuffleDeck(int*);
void newDeck(int*);
void printDeck(int*);
void printHands(int,int,int**);
   
