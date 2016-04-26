#include<stdio.h>

int main()
{
	double hours, year, percent, twentyone;


	printf("How many hours on average of sleep do you get a night?   ");
	scanf("%lf", &hours);


	year = (double) hours * 365;
	printf("\nIn one year you sleep %lf hours!", year);

	percent = (double) (year / (24*365))*100;
	printf("\nThat is %lf %c of the year!", percent, '%');

	twentyone = (double) year * 21;
	printf("\nBy the time you are 21 you will have slept %lf hours!", twentyone);

	return 0;


}
