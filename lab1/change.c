#include<stdio.h>

int main(){

	int quarters, dimes, nickels, pennies, change;
	printf("How many quarters do you have?   ");
	scanf("%d", &quarters);
	printf("How many dimes do you have?   ");
	scanf("%d", &dimes);
	printf("How many nickels do you have?   ");
	scanf("%d", &nickels);
	printf("How many pennies do you have?   ");
	scanf("%d", &pennies);

	change = quarters * 25 + dimes * 10 + nickels * 5 + pennies;

	printf("You have %d cents.", change);

	return 0;
}
