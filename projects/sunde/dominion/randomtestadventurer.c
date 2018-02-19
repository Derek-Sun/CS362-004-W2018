#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

int randomAdventurer(){
    //Define random seed
    int seed = random() % 1000;
    //Define number of players, Random between 2-4
    int numPlayer = random() % 3 + 2;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    //Defines game state variable
    struct gameState G;
    //Defines max hand count, 5 cards are allowed in one hand
    int maxHandCount = 5;
    int p, j, r, m;
    r = initializeGame(numPlayer, k, seed, &G);

    //Initialize game int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
    for (p = 0; p < numPlayer; p++){
        for (j = 0; j < maxHandCount; j++){
            //r = initializeGame(numPlayer, k, seed, &G);
            //G.whoseTurn = p;
            G.handCount[p] = maxHandCount; //Set number of cards for player
            int tempHandCount = G.handCount[p];
            m = cardEffect(adventurer, 1, 1, 1, &G, 1, 0);
            if (m != 0){
                return 1;
            }
            if (G.hand[p][G.handCount[p]-1] == embargo){
                return 1;
            }
            else if (G.handCount[p] != tempHandCount){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    srandom(time(NULL));
    int test_failed = 0;
    int test_passed = 0;

    for (int x = 0; x < 100; x ++){
        int b = randomAdventurer();
        if (b == 1){
            test_failed++;
        }
        else{
            test_passed++;
        }
    }
    printf("Adventurer Test Passed: %d times\nAdventurer Test Failed: %d times\n\n", test_passed, test_failed);
}