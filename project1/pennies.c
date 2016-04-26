#include<stdio.h>
#include<math.h>
/*Daniel Church
 Dr. Zhang
 2-12-2016
 pennies.c

 The purpose of this program is to calculate the amount of pennies the user has based off of the amount of cash they have.  This program will also serve to give the user the weight of the pennies in pounds as well as the total volume in cubic feet.

 */

int cashPrompt(char *a){
	int num;
	printf("How many %s do you have? ", a);
	scanf("%d", &num);
	return num;
}

double pennyWeight(int pennies){
	double weight;
	weight = (double)(pennies * 2.5)/(453.592);
	return weight;
}

double pennyVolume(int pennies){
	double volume, radiusSq, thickness;
	radiusSq = pow(((0.75/12.0)/2),2);
	thickness = ((1.52/25.4)/12);
	volume = radiusSq * thickness * 3.14159 * pennies;
	return volume;
}


int main(){
	int twenty = cashPrompt("twenty dollar bills");
	int ten = cashPrompt("ten dollar bills");
	int five = cashPrompt("five dollar bills");
	int one = cashPrompt("one dollar bills");
	int quarter = cashPrompt("quarters");
	int dime = cashPrompt("dimes");
	int nickel = cashPrompt("nickels");
	int penny = cashPrompt("pennies");

	int total = ((20*twenty+10*ten+5*five+one)*100)+(quarter*25)+(dime*10)+(nickel*5)+penny;
	double weight = pennyWeight(total);
	double volume = pennyVolume(total);

	printf("You have %d pennies.\n", total);
	printf("Those pennies have a weight of %lf pounds!\n", weight);
	printf("The total volume of your pennies is %lf cubic feet.", volume);

	return 0;

}

