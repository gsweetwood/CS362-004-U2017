#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>




int main(int argc, char** argv) {
	//unit test for the compare function in dominion


	int x = 0;
	int y = 0;
	
	const void* a = &x;
	const void* b = &y;

	int r = 0;
	
	

	int asserttrue(int expected) {
		if (expected != (compare(a, b))) {
			printf("TEST FAILED");
			r++;
			return 1;
		}
		else { return 0; }
	}

	printf("Testing compare(): \n");	

	x = 10;
	y = 9;

	asserttrue(1);

	x = 2;
	y = 4;

	asserttrue(-1);

	x = 20;
	y = 20;

	asserttrue(0);

	x = -22;
	y = -25;

	asserttrue(1);

	x = 0;
	y = 0;

	asserttrue(0);

	x = -1;
	y = 1;

	asserttrue(-1);

	x = -3;
	y = -3;

	asserttrue(0);

	x = 6;
	y = 8;



	if (r == 0) {
		printf("TEST SUCCESSFULLY COMPLETED\n");
	}
	else { printf("TEST FAILED\n"); }

	return 0;

}
