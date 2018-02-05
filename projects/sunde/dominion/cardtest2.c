#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


#define TESTCARD "council_room"

int main(){
    for (
        int numPlayers = 2; numPlayers <= 4; numPlayers ++){
        int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
        int seed = 10;
        struct gameState G, testG;
        int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
        int buyNum = 1;
        

        initializeGame(numPlayers, k, seed, &G);

        printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

        memcpy(&testG, &G, sizeof(struct gameState));


        cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);

        int newCards = 4;
        int discarded = 1;
        int thisPlayer = 1;

        printf("Action Player: hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
        printf("Player buy count: %d, Expected: %d\n", testG.numBuys, buyNum += 1);
        printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
        for (int otherPlayer = 0; otherPlayer < numPlayers; otherPlayer++){
            if (otherPlayer != thisPlayer){
                printf("Other Player %d: hand count =%d, expected = %d\n", otherPlayer, testG.handCount[otherPlayer], G.handCount[otherPlayer] + 1);
            }
        }
        if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards - discarded){
            printf("Test failed!\n");
        }
        if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards){
        printf("Test failed!\n");
        }
        if(testG.numBuys != buyNum){
        printf("Test failed!\n");
          }
        for (int otherPlayer = 0; otherPlayer < numPlayers; otherPlayer++){
            if (otherPlayer != thisPlayer){
                if(testG.handCount[otherPlayer] != G.handCount[otherPlayer] + 1){
                    printf("Test failed!\n");
                }
            }
        }
    }
    printf("Test Done!\n");
    return 0;
}