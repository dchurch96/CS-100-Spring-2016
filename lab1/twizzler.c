#include<stdio.h>

int main()
{
	double dist, mile, twiz;


	printf("How many miles would you like your twizzler string to reach?   ");
	scanf("%lf", &dist);

	mile = (double) 12*5280/8;
	twiz = (double) mile * dist;

	printf("It would take %lf twizzlers strung together to reach your destination.", twiz);

	return 0;

}
