#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.h"

int addMatrix(int **arr, int row, int col);
int **allocateMatrix(int row, int col);
void initMatrix(int **arr, int row, int col);
void printMatrix(int **arr, int row, int col);

int main(int argc, char **argv){
	
	int row = atoi(argv[1]);
	int col = atoi(argv[2]);

	int **array = allocateMatrix(row, col);
	initMatrix(array, row, col);

	int sum = addMatrix(array, row, col);
	
	printf("Array size = %d rows and %d columns, the sum of all elements in the array is %d \n", row, col, sum);

	return 0;
}


int **allocateMatrix(int row, int col)
{
	int a;
	int **arr;
	arr = malloc(sizeof(int *) * row);
	for (a=0; a<row; a++)
        	arr[a] = malloc(sizeof(int) * col);
   
	return arr;
}

int addMatrix(int **arr, int row, int col)
{
	int sum=0;
	int i, j;
	for (i=0; i<row; i++) {
		for (j=0; j<col; j++) {
			sum=sum+arr[i][j];
		}
	}

	return sum;
}

void initMatrix(int **arr, int row, int col)
{
	FILE *fp = fopen("Data1", "r");
	int i, j;
	for (i=0; i<row; i++) {
		for (j=0; j<col; j++) {
			arr[i][j]= readInt(fp);

		}
	}
	fclose(fp);
}

void printMatrix(int **arr, int row, int col)
{
	int i, j;
	for (i=0; i<row; i++) {
		for (j=0; j<col; j++) {
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
}


