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

	int handPos;
	int handCountStart;
	int origPlayed;
	int numTests = 2000;
	int i;
	int passed =0;
//	int player;
	for(i = 0; i < numTests; i++){
	 int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

	initializeGame(2, k, 3, &testGame);

//	choice1 = rand() % 50;
//	choice2 = rand() % 50;
//	choice3 = rand() % 50;
	handPos = rand() % MAX_HAND;
//	bonus = rand() % 50;
//	player = rand() % 3;	

	testGame.handCount[testGame.whoseTurn] = rand() % 497;	
	handCountStart = numHandCards(&testGame);
	origPlayed = testGame.playedCardCount;
	//cardEffect(smithy, choice1, choice2, choice3, &testGame, handPos,& bonus);
	playSmithy(handPos, &testGame);
	void asserttrue(int a, int b){
		if (a != b){
			printf("TEST FAILED\n");
			passed = 1;
		}
		if (origPlayed != testGame.playedCardCount +1) {
			printf("TEST FAILED, card trashed\n");
			passed = 1;
		}
		
	}

	asserttrue(numHandCards(&testGame), (handCountStart + 2));
	}

	if(passed == 0){
		printf("TESTS ALL SUCCESSFUL\n");
	} else {printf("TEST COMPLETE, FAILURES DETECTED\n");
	}

return 0;
}
