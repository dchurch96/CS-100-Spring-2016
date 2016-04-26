#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"scanner.h"

int main(){
	FILE *fp = fopen("data", "r");
	int token1 = readInt(fp);
	int token2 = readInt(fp);
	while (!feof(fp)){
		if (token2>=token1){
			token1 = token2;
			token2 = readInt(fp);
		}
		else {
			printf("no");
			fclose(fp);
			return 0;
		}
		
	}
	printf("yes");
	fclose(fp);
	return 0;
} 