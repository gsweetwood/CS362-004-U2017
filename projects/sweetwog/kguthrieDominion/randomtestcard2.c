#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	//clock_t begin = clock();
	struct gameState G;

	int k[10] = { adventurer, gardens, council_room, village, minion, mine, cutpurse,
		sea_hag, great_hall, smithy };

	int choice1;
	int choice2;
	int choice3;
	int handPos;
	int bonus;
	int i;
	int numTests = 1000;

	for(i = 0; i < numTests; i++){
	initializeGame(2, k, 13, &G);

	choice1 = (rand() % 50) - 10;
	choice2 = (rand() % 50) - 10;
	choice3 = (rand() % 50) - 10;
	handPos = rand() % MAX_HAND;
	bonus = (rand() % 50) -10;

	int r = cardEffect(gardens, choice1, choice2, choice3, &G, handPos, &bonus);

	if (r != -1) {
		printf("TEST FAILED\n");
	}

	
	}
	

	printf("TEST SUCCESSFULLY COMPLETED");

	//clock_t end = clock();
	//double total_time = (double)(end - begin)/	
	return 0;
}
