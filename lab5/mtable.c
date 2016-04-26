#include<stdio.h>
int main(){
	int i=0, j=0, k=0;
	printf("\t   ");
	for (k=0; k<10; k++){
		printf("%d\t", k+1);
	}
	printf("\n\t +--------------------------------------------------------------------------\n");
	for (j=0; j<10; j++){
		printf("%d\t|  ", j+1);
		for(i=0; i<10; i++){
			printf("%d\t", (j+1)*(i+1));
		}
		printf("\n");
	}
	return 0;
}
