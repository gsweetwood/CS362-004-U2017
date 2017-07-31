#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv){
	printf("Testing smithy random testing: \n");

	struct gameState testGame;

	int choice1, choice2, choice3, handPos, bonus;
	int handCountStart;

	int numTests = 2000;
	int i;
	int player;
	for(i = 0; i < numTests; i++){
	 int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

	initializeGame(2, k, 3, &testGame);

	choice1 = rand() % 50;
	choice2 = rand() % 50;
	choice3 = rand() % 50;
	handPos = rand() % MAX_HAND;
	bonus = rand() % 50;
	player = rand() % 3;	

	testGame.handCount[player] = rand() % 497;	
	handCountStart = numHandCards(&testGame);

	//cardEffect(smithy, choice1, choice2, choice3, &testGame, handPos,& bonus);
	playSmithy(&testGame, player, i, handPos);
	void asserttrue(int a, int b){
		if (a != b){
			printf("TEST FAILED\n");
		} else {
			printf("TEST SUCCESSFULLY COMPLETED\n");
		}
	}

	asserttrue(numHandCards(&testGame), (handCountStart + 2));
	}


return 0;
}
