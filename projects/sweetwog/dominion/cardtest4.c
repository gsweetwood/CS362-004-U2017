#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv) {

	printf("Testing card: great_hall\n");

	struct gameState testGame;

	int choice1 = 0, choice2 = 0, choice3 = 0, handPos = 3;
	
	

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	initializeGame(2, k, 3, &testGame);


	int cPlayer = whoseTurn(&testGame);

	testGame.deck[cPlayer][3] = great_hall;

	playCard(handPos, choice1, choice2, choice3, &testGame);

	void asserttrue(){
		if(numHandCards(&testGame) == 5){
			if (testGame.numActions == 1) {
				printf("TEST SUCCESSFULLY COMPLETED\n");
			}
		} else {
			printf("TEST FAILED\n");
		}
	}
	
	asserttrue();
	return 0;
}
