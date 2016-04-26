#include<stdio.h>
#include<stdlib.h>
#include"scanner.h"
#include<string.h>

int rec = 1;


int count(int num){
	double num2 = (double) num/10;
	if (num2 > 1){
		rec++;
		return count(num2);
	}
	if (num2 < 1) {
		return rec;
	}

	if (num2 == 0) {
		return 1;
	}

	return 0;
}


int main(){
	printf("Enter a positive integer or 0 to exit: ");
	int num = readInt(stdin);
	while(num != 0){
		printf("There are %d digits in %d", count(num), num);
		printf("\nEnter a positive integer or 0 to exit: ");
		num = readInt(stdin);
		rec = 1;
	}

	return 0;
}