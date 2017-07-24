#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
//Gets a random character in fromt he ASCII code, from 32-126
//It must include all the brackets[]{}(), 'a', 'x', and a space ' '
	char c = (rand() % (127 - 32)) + 32;
	return c;
}
	
char *inputString()
{
	//The string needs to be as long as the word "reset" plus the NUL terminator
	char* s = malloc(6);
	int i;
	//Generates a random string of 5 letters, for now, just the lowercase letters
	//Every string must end with a NUL terminator (\0), so it is added to the end
	for (i = 0; i < 5; i++)
	{
	//Gets a random ASCII character in range [97-122]
	s[i] = (rand() % (123 - 65)) + 65; //set includes all uppercase and lower case letters, plus a few characters
	}
	s[5] = '\0';
	return s;
}
	
void testme()
{
	int tcCount = 0;
	char c;
	char *s;
	int state = 0;
	while (1)
	{
		tcCount++;
		c = inputChar();
		s = inputString();

		//This significanty reduces the actual testing time.  It gives an update every half million tests.
																			//Originally it printed every iteration, but the professor wants the test to finish in under 3 minutes
																			if (tcCount % 500000 == 0) {
			printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
		}
		if (c == '[' && state == 0) state = 1;
		if (c == '(' && state == 1) state = 2;
		if (c == '{' && state == 2) state = 3;
		if (c == ' '&& state == 3) state = 4;
		if (c == 'a' && state == 4) state = 5;
		if (c == 'x' && state == 5) state = 6;
		if (c == '}' && state == 6) state = 7;
		if (c == ')' && state == 7) state = 8;
		if (c == ']' && state == 8) state = 9;
		if (s[0] == 'r' && s[1] == 'e'
		&& s[2] == 's' && s[3] == 'e'
		&& s[4] == 't' && s[5] == '\0'
		&& state == 9)
		{
			//prints status of iteration that executes error message
			printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
			printf("error \n");
			free(s);
			//getchar();  //I used this to pause so I could see where the count ended
			exit(200);
		}
																			free(s);
	}
}
	
	
int main(int argc, char *argv[])
{
	srand(time(NULL));
	testme();
	return 0;
}
