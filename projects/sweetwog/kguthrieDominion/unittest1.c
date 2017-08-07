





#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv) {
	
	int r;

	int asserttrue(int* k,int x) {
		
		switch (x) {
		case 0:
			if (k[0] == adventurer) {
				r = 1;
			}
			else { r = 0; }
			
			break;
		case 1:
			if (k[1] == outpost) {
				r = 1;
			}
			else { r = 0; }
			
			  break;
		case 2:
			if (k[2] == minion) {
				r = 1;
			}
			else { r = 0; }
			
			  break;
		case 3:
			if (k[3] == mine) {
				r = 1;
			}
			else { r = 0; }
			
			  break;
		case 4:
			if (k[4] == council_room) {
				r = 1;
			}
			else { r = 0; }
			
			  break;
		case 5:
			if (k[5] == smithy) {
				r = 1;
			}	
			else { r = 0; }
			
			  break;
		case 6:
			if (k[6] == gardens) {
				r = 1;
			}
			else { r = 0; }
			
			  break;
		case 7:
			if (k[7] == embargo) {
				r = 1;
			}
			else { r = 0; }
			
			  break;
		case 8:
			if (k[8] == steward) {
				r = 1;
			}
			else { r = 0; }
			
			  break;
		case 9:
			if (k[9] == cutpurse) {
				r = 1;
			}
			else { r = 0; }
			
			  break;
		default: r = 0;
		}

	}

	printf("Testing kingdomCards():\n");

	int* k =kingdomCards(
		adventurer,
		outpost,
		minion,
		mine,
		council_room,
		smithy,
		gardens,
		embargo,
		steward,
		cutpurse

	);

	int i;	
	
	for (i = 0; i < 10; i++) {
		r = asserttrue(k, i);
	}

	free(k);

	if (r == 1) {
		printf("TEST SUCCESSFULLY COMPLETED\n");
	}
	else {
		printf("TEST FAILED\n");
	}
	

	return 0;

}
