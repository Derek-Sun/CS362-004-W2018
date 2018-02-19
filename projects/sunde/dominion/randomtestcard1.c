#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

#define VARI 1

int gardenTest(){
    //Kingdom cards required to initialize game
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

    int m;
    //Define Random Seed
    int seed = random() %1000;
    //Generate Number of Players, 2-4 Randomly
    int numPlayer = random() % 3 + 2;

    int r;
    //Defines game state variable
    struct gameState G;

    r = initializeGame(numPlayer, k, seed, &G);
    m = cardEffect(gardens, 1, 1, 1, &G, 1, 0);
    if(m != -1){
        //Error
        return 1;
    }
    else{
        //Pass
        return 0;
    }
}


int main()
{
    srandom(time(NULL));
    int test_failed = 0;
    int test_passed = 0;

    for (int x = 0; x < 300; x ++){
        int b = gardenTest();
        if (b == 1){
            test_failed++;
        }
        else{
            test_passed++;
        }
    }
    printf("Garden Test Passed: %d times\nGarden Test Failed: %d times\n\n", test_passed, test_failed);
    return 0;
}