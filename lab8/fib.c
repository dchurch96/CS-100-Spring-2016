#include<stdio.h>
#include<stdlib.h>
#include"scanner.h"
#include<string.h>
int count = 0;

int fib(int num){
	count++;
	if (num == 0) return 1;
	if (num == 1) return 1;
	return fib(num-1) + fib(num-2);
}

int main(int argc,char **argv){
	int num;
	num = atoi(argv[1]);
	int num2 = fib(num);
	printf("fib(%d) = %d and has %d recursive calls.", num, num2, count);

	return 0;
}