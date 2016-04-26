#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"scanner.h"

int main(int argc, char **argv){
	FILE *fp = fopen(argv[1], "r");
	char* token, a[99];
	int num, i, max=0,j,k;
	token = readToken(fp);
	for (i=0; i<100; i++){
		a[i]=0;
	}
	while (!feof(fp)){
		num = atoi(token);
		a[num]++;
		token = readToken(fp);
	}
	for (j=0; j<100; j++){
		if (a[j]>max) max = a[j];
	}
	for (k=0; k<100; k++){
		if (a[k]==max){
			printf("%d ", k);
		}
	}
	fclose(fp);
	return 0;
}
