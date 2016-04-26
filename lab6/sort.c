#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"scanner.h"

int main(int argc, char **argv){
	FILE *fp = fopen(argv[1], "r");
	FILE *fe = fopen("evens", "w");
	FILE *fo = fopen("odds", "w");
	char *token = readToken(fp);
	int num;
	while (!feof(fp)){
		num = atoi(token);
		if (num%2 == 0){
			fprintf(fe, "%d ", num);
		}
		else {
			fprintf(fo, "%d ", num);
		}
		token = readToken(fp);
	}


	fclose(fp);
	return 0;
}
