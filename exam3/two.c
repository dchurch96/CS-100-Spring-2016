#include <stdio.h>
#include <stdlib.h>

int j=0;
int i = 0;
int min;
int max;

int findMin(int a[], int size) {
	if (i == 0){
		min = a[0];
	}
	if (size == 1) return a[0];
	if (a[i] < min){
		min = a[i];
	}
	if (i == size - 1){
		return min;
	}
	i++;
	return findMin(a, size);
}

int findMax(int a[], int size) {
	if (j == 0){
		max = a[0];
	}
	if (size == 1) return a[0];
	if (a[j] > max){
		max = a[j];
	}
	if (j == size - 1){
		return max;
	}
	j++;
	return findMax(a, size);
}

int main(int argc, char *argv[]) {
    if (argc==1) {
        printf("Error: it requires a list of integers as arguments.\n");
        return 1;
    }
    int size=argc-1;
    int *array=(int *)malloc(sizeof(int)*size);
    int a;
    for (a=0; a<size; a++) {
        array[a] = atoi(argv[a+1]);
    }
    printf("Min=%d\n", findMin(array, size));
    printf("Max=%d\n", findMax(array, size));
    return 0;
}

