#include<stdio.h>

int main(){

	FILE *fp;
	int numberArray[100000];
	fp = fopen("NUMS.txt", "r");
	int i=0, max = 0, min = 0;
	for (i=0; i<100000; i++){
		fscanf(fp,"%d,", &numberArray[i]);
	}
	max = numberArray[0];
	min = numberArray[0];
	for (i=0; i<100000; i++){
		if(numberArray[i]>max) max = numberArray[i];
		if(numberArray[i]<min) min = numberArray[i];
	}
	printf("The max is %d \n", max);
	printf("The min is %d \n", min);
	return 0;
}