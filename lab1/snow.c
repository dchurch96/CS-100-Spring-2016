#include<stdio.h>

int main(){

	int water;
	double snow;

	printf("How many gallons of water do you have?");
	scanf("%d", &water);

	snow = water * 3.78 / .000003;

	printf("You could make %lf snowflakes out of that water!", snow);
}
