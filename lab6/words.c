#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"scanner.h"

int main(int argc, char **argv){
	FILE *fp = fopen(argv[1], "r");
	char* token;
	token = readToken(fp);
	int count = 0, sum = 0;
	while (!feof(fp)){
		count++;
		sum += strlen(token);
		token = readToken(fp);
	}
	fclose(fp);
	printf("%d\n", count);
	printf("%lf\n", (double)sum/count);
	return 0;
}
