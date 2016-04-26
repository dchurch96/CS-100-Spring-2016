#include <stdio.h>
#include <string.h>

int main( ) {
	// Add the C statement(s) necessary to accomplish the task identified in the comments below

	// declare a string STR that holds "Hello World"
char STR[11] = {"Hello World"};
	// print the string STR followed by a newline character
printf("%s \n", STR);
	// Change the two upper-case characters in STR to lower-case, print STR again
STR[0] = 'h';
STR[6] = 'w';
printf("%s \n", STR);
	// declare an integer variable A, assign it the string length of STR, print A
int A = strlen(STR);
printf("%d \n", A);
	// declare a string S that is 25 characters in length
char S[25];
	// use strcpy to put Alabama Crimson Tide in S, then print S (followed by a newline)
strcpy (S, "Alabama Crimson Tide");
printf("%s \n", S);
	// store the length of S in A, then print A
A = strlen(S);
printf("%d \n", A);
	// declare PTR as a pointer to a character 
char *PTR;
	// set PTR so that it points to the letter 'C' in S
PTR = &S[8];
	// print the character where PTR is pointing
printf("%c \n", *PTR);
	// print the string S starting at the C (location 8, where iPTR points)
	printf("%s \n", PTR);
	// print the character two before, and two after, were PTR points
printf("%c %c \n", (*PTR - 2), (*PTR + 2));
	// put a NULL character in position 7 of S
S[6] = '0';
	// print S and its length, followed by a newline 
printf("%s, %d", S, A);
	return 0;
}
