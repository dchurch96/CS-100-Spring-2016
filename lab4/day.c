#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int month, day, days;
	month = atoi(argv[1]);
	day = atoi(argv[2]);
	if (month == 1) days = day;
	if (month == 2) days = 31 + day;
	if (month == 3) days = 31 + 29 + day;
	if (month == 4) days = 31 + 29 + 31 + day;
	if (month == 5) days = 31 + 29 + 31 + 30 + day;
	if (month == 6) days = 31 + 29 + 31 + 30 + 31 + day;
	if (month == 7) days = 31 + 29 + 31 + 30 + 31 + 30 + day;
	if (month == 8) days = 31 + 29 + 31 + 30 + 31 + 30 + 31 + day;
	if (month == 9) days = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + day;
	if (month == 10) days = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
	if (month == 11) days = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
	if (month == 12) days = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;

	printf("%d", days);
	return 0;

}
