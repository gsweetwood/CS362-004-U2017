#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv) {
	

	printf("Testing card: adventurer\n ");
	struct gameState testGame;

	int before = 0, after = 0;
	int choice1 = 0, choice2 = 0, choice3 = 0, handPos = 3;

	int cPlayer = whoseTurn(&testGame);
	int hCount = numHandCards(&testGame);	

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	initializeGame(2, k, 3, &testGame);

	int i;
	for (i=0; i < hCount; i++){
		if (testGame.hand[cPlayer][i] == copper || testGame.hand[cPlayer][i] == silver ||  testGame.hand[cPlayer][i] == gold ) {
			before++;
		}
	}

	cardEffect(adventurer, choice1, choice2, choice3, &testGame, handPos, NULL);

	for (i=0; i < hCount; i++){
		if (testGame.hand[cPlayer][i] == copper || testGame.hand[cPlayer][i] == silver ||  testGame.hand[cPlayer][i] == gold ) {
			after++;
		}
	}

	void asserttrue (int before, int after) {
		if(after != (before + 2)){
			printf("TEST FAILED\n");
		} else {
			printf("TEST SUCCESSFULLY COMPLETED\n");
		}
	}
	
	asserttrue(before, after);

	return 0;
} 	

	
