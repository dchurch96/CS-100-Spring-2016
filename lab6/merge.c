#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"scanner.h"

int main(int argc, char **argv){
	
	FILE *fp1 = fopen(argv[1], "r");
	FILE *fp2 = fopen(argv[2], "r");
	FILE *fp = fopen("alldata", "w");

	char* token1 = readToken(fp1);
	char* token2 = readToken(fp2);
	int num1, num2;

	while (!feof(fp1) && !feof(fp2)){
		num1 = atoi(token1);
		num2 = atoi(token2);
		if (num1>num2){
			fprintf(fp, "%d ", num2);
			token2 = readToken(fp2);
		}
		if (num2>num1){
			fprintf(fp, "%d ", num1);
			token1 = readToken(fp1);
		}
		if (num2==num1){
			fprintf(fp, "%d ", num1);
			token2 = readToken(fp2);
			token1 = readToken(fp1);
		}
	}

	while(!feof(fp2)){
			num2 = atoi(token2);
			fprintf(fp, "%d ", num2);
			token2 = readToken(fp2);
	}
	while(!feof(fp1)){
			num1 = atoi(token1);
			fprintf(fp, "%d ", num1);
			token1 = readToken(fp1);
	}

	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
