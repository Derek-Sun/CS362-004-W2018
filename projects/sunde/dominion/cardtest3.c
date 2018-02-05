#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


#define TESTCARD "adventurer"

int main(){
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 10;
    int numPlayers = 2;
    struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	int thisPlayer = 0;

    initializeGame(numPlayers, k, seed, &G);

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	memcpy(&testG, &G, sizeof(struct gameState));

	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

    int newCards = 2;
    int discarded = 1;

    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards - discarded){
        printf("Test failed!\n");
    }
    if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards){
        printf("Test failed!\n");
    }

    printf("Test Done!\n");

    return 0;
}