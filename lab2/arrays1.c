#include <stdio.h>

int main( ) {
	// Add the C statement(s) necessary to accomplish the task identified in the comments below

	// declare an array A of 3 doubles
double A[3];
	// put the value 3.14 in the middle location of A
A[1] = 3.14;
	// put the value 2.718 in the first and last locations of A
A[0] = 2.718;
A[2] = 2.718;
	// print the first value in A
printf("%lf \n", A[0]);
	// print the last value in A
printf("%lf \n", A[2]);
	// change the last value in A so that it is the sum of the first two and then print it
A[2] = A[0] + A[1];
	// declare an array B of 4 integers with initial values 10, 25, 50, 100
int B[4] = {10,25,50,100};
	// print the sum of all four elements in B
int sum = B[0] + B[1] + B[2] + B[3];
printf("The sum is %d \n", sum);
	// print the four elements in B in reverse order (100, 50, 25, 10)
printf("%d %d %d %d \n", B[3], B[2], B[1], B[0]);
	// declare three integers, X Y and Z, assign them the values 1, 2 and 3 and print them
int x = 1, y = 2, z = 3;
	// declare three pointers to integers, P1, P2 and P3
int *P1 = 0, *P2 = 0, *P3 = 0;
	// point P1 to X, P2 to Y, and P3 to Z.
P1 = &x;
P2 = &y;
P3 = &z;
	// print the values at X and Y and Z using the pointers P1 to P3
printf("%d, %d, %d \n", *P1, *P2, *P3);
	// using P1 and not X, change the variable X's value from 1 to 10, then print it
*P1 = 10;
printf("%d\n", x);
	// using only P1 and P2 and P3, change the value of X to be (Y + Z), then print X
*P1 = *P2 + *P3;
printf("%d\n", x);
	// point P1 to the first element in array B and print out that value using P1
P1 = &B[0];
printf("%d\n", *P1);
	// point P1 to the last element in array B and print out that value using P1
P1 = &B[3];
printf("%d\n", *P1);
	return 0;
}
