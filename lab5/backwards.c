#include<stdio.h>
#include<string.h>
int main(int argc, char **argv){
	int i=0, j=0, len = 0;
	for (j=0; j<(argc-1); j++){
		len = strlen(argv[j+1]);
		for (i = 0; i<len; i++){
			char c = argv[j+1][len-(i+1)];
			printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}