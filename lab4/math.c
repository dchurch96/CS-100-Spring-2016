#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(int avrc, char *avrg[])
{
	int num1, num2;
	double x;

	num1 = atoi(avrg[1]);
	num2 = atoi(avrg[3]);
	
	if (*avrg[2] == '+') x = num1 + num2;
	if (*avrg[2] == '-') x = num1 - num2;
	if (*avrg[2] == '*') x = num1 * num2;
	if (*avrg[2] == '/') x = (double)num1 / num2;

	printf("%lf", x);
	return 0;
}
