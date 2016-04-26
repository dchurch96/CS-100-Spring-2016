#include<stdio.h>
#include<string.h>

int main(int argc, char **argv){
	int i=0, j=0, k=0, max=0, length=0;
	max = strlen(argv[k]);
	for (k = 0; k<argc-1; k++){
		if (strlen(argv[k+1])>max) max = strlen(argv[k+1]);
	}
	for(i = 0; i< max; i++){
		for(j = 0; j<(argc); j++){
			length = strlen(argv[j]);
			if (i<length){
				printf("%c ", argv[j][i]);
			}
			if ((i+1)>length){
				printf("  ");
			}
		}
		printf("\n");
	}


	return 0;
}