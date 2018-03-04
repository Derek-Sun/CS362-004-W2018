#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


#define TESTCARD "great_hall"

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

	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);

	int newCards = 1;
	int discarded = 1;
	int gainedActions = 1;
	int lossActions = 1;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("action count = %d, expected = %d\n", testG.numActions, G.numActions- lossActions + gainedActions);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
	if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards - discarded){
		printf("Test failed!\n");
	}
	if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards){
		printf("Test failed!\n");
	}
	if(testG.numActions != G.numActions - lossActions + gainedActions){
		printf("Test failed!\n");
	}

	printf("Test Done!\n");
	return 0;
}