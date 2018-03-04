#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

int randomGreatHall(){
    int m;
    //Define random seed
    int seed = random() % 1000;
    //Define number of players, random from 2-4
    int numPlayer = random() % 3 + 2;

    int p, r;
    //Kingdom cards required to initialize game
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    //Defines game state variable
    struct gameState G;
    //Defines max hand count, 5 cards are allowed in one hand
    int maxHandCount = 5;

    for (p = 0; p < numPlayer; p++){
        for (int j = 0; j < maxHandCount; j++){
            r = initializeGame(numPlayer, k, seed, &G);
            G.whoseTurn = p;
            G.handCount[p] = maxHandCount;
            int tempActions = G.numActions;
            int tempCard = G.handCount[p];
            m = cardEffect(great_hall, 1, 1, 1, &G, 1, 0);
            if( m != 0 ){
                return 1;
            }
            else{
                if (G.handCount[p] != tempCard || G.numActions != tempActions + 1){
                    return 1;
                }
            }
        }
    }
    return 0;
}


int main(){
    srandom(time(NULL));
    int test_failed = 0;
    int test_passed = 0;

    for (int x = 0; x < 50; x ++){
        int b = randomGreatHall();
        if (b == 1){
            test_failed++;
        }
        else{
            test_passed++;
        }
    }
    printf("Great Hall Test Passed: %d times\nGreat Hall Test Failed: %d times\n\n", test_passed, test_failed);
}