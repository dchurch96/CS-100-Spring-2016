#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
	int max;
	max = atoi(argv[1]);
	if (atoi(argv[2]) > max) max = atoi(argv[2]);
	if (atoi(argv[3]) > max) max = atoi(argv[3]);
	if (atoi(argv[4]) > max) max = atoi(argv[4]);
	if (atoi(argv[5]) > max) max = atoi(argv[5]);

	int min;
	min = atoi(argv[1]);
	if (atoi(argv[2]) < min) min = atoi(argv[2]);
	if (atoi(argv[3]) < min) min = atoi(argv[3]);
	if (atoi(argv[4]) < min) min = atoi(argv[4]);
	if (atoi(argv[5]) < min) min = atoi(argv[5]);

	printf("range is %d", max - min);

	return 0;
}
