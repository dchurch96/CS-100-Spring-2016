#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	
	printf("%s", argv[1]);
	printf("%s", argv[2]);
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	int min;	

	

	min = (13-x) * 60 + (60-y);
	printf("You have stayed awake %d minutes up until the exam began",min);
	return 0;
}
