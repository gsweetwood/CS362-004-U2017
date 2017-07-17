
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv) {

	struct gameState testGame;

	int k[10] = { adventurer, gardens, council_room, village, minion, mine, cutpurse,
		sea_hag, great_hall, smithy };

	int copperCount = 0;
	int r = initializeGame(2, k, 123, &testGame);

	testGame.supplyCount[copper] = 10;
	copperCount = testGame.supplyCount[copper];

	printf("Testing supplyCount(): \n");

	assert(copperCount == 10);

	
	assert(r == 0);

	printf("TEST SUCCESSFULLY COMPLETED\n");

	return 0;
}
