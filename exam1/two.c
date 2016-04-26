#include<stdio.h>

double numOfPages(int x) {
	double words, pages;
	words = x*45000; //total words for all the pencils
	pages = words/350; //total words divided by words per page
	return pages;
}

double numOfHours(double pages) {
	double minutes, hours;
	minutes = pages * 20.0; //total minutes of writing
	hours = minutes/60.0; //hours of writing
	return hours;
}

int main(){
	int x;
	double pages, hours;
	printf("Please enter an integer:  ");
	scanf("%d", &x);
	pages = numOfPages(x);
	hours = numOfHours(pages);
	printf("You could write %lf pages with that many pencils.\n", pages);
	printf("Which would tak you %lf hours.", hours);

	return 0;
}
