#include <stdio.h>
#include <math.h>

void readData(int *array){
	printf("What is the first value?");
	scanf("%d", &array[0]);
	printf("What is the first value?");
	scanf("%d", &array[1]);
	printf("What is the first value?");
	scanf("%d", &array[2]);
	printf("What is the first value?");
	scanf("%d", &array[3]);
	printf("What is the first value?");
	scanf("%d", &array[4]);
}

double findMean(int *array){
	double mean = (double)(array[0] + array[1] + array[2] + array[3] + array[4])/5;
	return mean;
}

double findVariance(int *array, double mean){
	double var;
	var = (double)(array[0] - mean)*(array[0] - mean) + (double)(array[1] - mean)*(array[1] - mean) + (double)(array[2] - mean)*(array[2] - mean) + (double)(array[3] - mean)*(array[3] - mean) + (double)(array[4] - mean)*(array[4] - mean);
	return var;
}
void printResults(double mean, double var, double stddev){
	printf("The mean is %lf\n", mean);
	printf("The variance is %lf\n", var);
	printf("The standard deviation is %lf", stddev);
}

int main( ) {
	int array[5];
	readData(array);
	double mean, variance, stddev;
	mean = findMean(array);
	variance = findVariance(array, mean);
	stddev = sqrt(variance);
	printResults(mean, variance, stddev);
	return 0;
}
