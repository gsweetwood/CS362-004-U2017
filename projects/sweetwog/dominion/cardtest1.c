#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv) {

	printf("Testing smithy: \n");

	struct gameState testGame;

	int choice1 = 0, choice2 = 0, choice3 = 0;
	int handCountStart;

	 int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

	initializeGame(2, k, 3, &testGame);

	handCountStart = numHandCards(&testGame);

	cardEffect(smithy, choice1, choice2, choice3, &testGame, 0, NULL);

	void asserttrue(int a, int b){
		if (a != b){
			printf("TEST FAILED\n");
		} else {
			printf("TEST SUCCESSFULLY COMPLETED\n");
		}
	}

	asserttrue(numHandCards(&testGame), (handCountStart + 2));


return 0;
}
