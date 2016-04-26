#include<stdio.h>

int main()
{
	int int1,int2,int3,int4,int5;
	printf("Please enter an integer:   ");
	scanf("%d", &int1);
	printf("Please enter an integer:   ");
	scanf("%d", &int2);
	printf("Please enter an integer:   ");
	scanf("%d", &int3);
	printf("Please enter an integer:   ");
	scanf("%d", &int4);
	printf("Please enter an integer:   ");
	scanf("%d", &int5);

	int sum;
	double average;

	sum = int1 + int2 + int3 + int4 + int5;
	average = (double)sum/5;


	printf("\n The sum is %d", sum);
	printf("\n The average is %lf", average);

	return 0;









}
