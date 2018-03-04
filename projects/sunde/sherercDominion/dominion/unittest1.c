/*
Garden: Changed the return value of “Garden” from -1 to 1. 
    When running the dominion simulation, there doesn’t seem to 
    be any apparent changes in the player scores using seed values from 2-9.
Smithy: Changed the number of cards drawn for “Smithy” from 3 to 2.
Adventurer:  Changed the number of treasure cards required to be drawn from 2 to 1.
     Another change was the that one of the treasure cards that are accepted is
    the “Embargo” card.
Great Hall: Changed the number of actions for the “Great Hall” card from 1 to 2.
Village: +2 Action +1 Card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define VARI 1

int main()
{
    int m, j;
    //Define random seed
    int seed = 20;
    //Define number of players
    int numPlayer = 2;

    int p, r;
    //Kingdom cards required to initialize game
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    //Defines game state variable
    struct gameState G;
    //Defines max hand count, 5 cards are allowed in one hand
    int maxHandCount = 5;

    //Initialize game int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
    for (p = 0; p < numPlayer; p++){
        for (j = 0; j < maxHandCount; j++)
                r = initializeGame(numPlayer, k, seed, &G);
                G.handCount[p] = maxHandCount; //Set number of cards for player
                int tempAction = G.numActions; //Store number of action
                int temphandCount = G.handCount[p]; //Store number of cards in hand
                m = cardEffect(village, 1, 1, 1, &G, 1, 0); //Run village effect with card at specific position
                if (m != 0){
                    printf("Test failed!\n");
                }
#if (VARI == 1)
                printf("Village Effect Has Run Successfully\n");
#endif
#if (VARI == 1)
                printf("G.numActions = %d, expected= %d\n", G.numActions, tempAction + 2);
                printf("G.handCount = %d, expcted = %d\n", G.handCount[p], temphandCount);
#endif
                //Check if the correct number of actions were added and if a card was drawn
                if(G.numActions != tempAction + 2 && G.handCount[p] != temphandCount){
                    printf("Test failed!\n");
                }
    }
    printf("Test Done!\n");
    return 0;
}