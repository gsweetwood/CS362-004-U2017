


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv) {

	int result = 0;
	
	struct gameState testGame;

	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	initializeGame(2, k, 6, &testGame);

	int asserttrue(struct gameState testGame, int expected) {

		int tcase = isGameOver(&testGame);

		if (expected == tcase) {
			return 0;
		}
		else {
			result = 1;
			printf("TEST FAILED\n");
		}
		return 0;

	}

	printf("Testing isGameOver(): \n");

	//Start of game, should be 0 (not game over)
	asserttrue(testGame, 0);

	//Set province cards to 0, a game ending condition
	testGame.supplyCount[province] = 0;
	asserttrue(testGame, 1);
	testGame.supplyCount[province] = 8;

	//Set 1 pile to 0
	testGame.supplyCount[adventurer] = 0;
	asserttrue(testGame, 0);

	//Set another pile to 0
	testGame.supplyCount[gardens] = 0;
	asserttrue(testGame, 0);

	//Set a third pile to 0, should end game
	testGame.supplyCount[copper] = 0;
	asserttrue(testGame, 1);

	if (result == 0) {
		printf("TEST SUCCESSFULLY COMPLETED\n");
		return 0;
	}
	else {
		printf("TEST FAILED\n");
		
	}

	return 0;
}
