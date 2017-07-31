#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {

	//Random test for card Adventurer
	srand(time(NULL));

	struct gameState testGame;

	int numTests = 1000;
	int i;
	int errCount = 0;
	int origNumHand;
	int card1, card2;
	//int player = 0;	

	int k[10] = { adventurer, gardens, council_room, village, minion, mine, cutpurse,
		sea_hag, great_hall, smithy };

	int choice1;
	int choice2;
	int choice3;
	int handPos;
	int bonus;	
	int player;	

	for (i = 0; i < numTests; i++) {
		
		player = rand() % 3;
		initializeGame(4, k, 3, &testGame);
		testGame.deckCount[player] = rand() % 50;
		testGame.handCount[player] = rand() & 50;

		origNumHand = testGame.handCount[0];
		//origNumDeck = testGame.deckCount[0];
		
		choice1 = rand() % 50;
		choice2 = rand() % 50;
		choice3 = rand() % 50;
		handPos = rand() % MAX_HAND;
		bonus =  rand() % 50;
	
		cardEffect(adventurer, choice1, choice2, choice3, &testGame, handPos, &bonus);

		if (testGame.handCount[player] != origNumHand + 2) {
		//	printf("TEST FAILED: Did not draw correct amount of cards");
			errCount++;
		}
		card1 = testGame.hand[player][testGame.handCount[player]] - 1;
		if (card1 != copper && card1 != silver && card1 != gold) {
			//printf("TEST FAILED: Did not draw correct card type");
			errCount++;
		}
	
		card2 = testGame.hand[player][testGame.handCount[player]] - 2;
		if (card2 != copper && card1 != silver && card1 != gold) {
			//printf("TEST FAILED: Did not draw correct card type");
			errCount++;
		}

		}
	printf("TEST COMPLETE, FOUND %d ERRORS\n", errCount);
	//Display the amount of failures, known bug should result in all failures	
	return 0;
}
