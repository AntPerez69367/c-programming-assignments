#include <stdio.h>
#include "deck.h"

void initGameSpace()
{
    int deck[MAX_CARDS];
    int *dp = &deck[0];
    newDeck(dp);
}
