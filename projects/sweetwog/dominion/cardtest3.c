#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv) {

	printf("Testing card: gardens\n");

	struct gameState testGame;

	int choice1 = 0, choice2 = 0, choice3 = 0, handPos = 3;


	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	initializeGame(2, k, 3, &testGame);

	int cardCheck = cardEffect(gardens, choice1, choice2, choice3, &testGame, handPos, NULL);

	void asserttrue(int a){
		if(a != -1) {
			printf("TEST FAILED\n");
		} else {
			printf("TEST SUCCESSFULLY COMPLETED\n");
		}
	}
	
	asserttrue(cardCheck);
	return 0;
}
