#include<stdio.h>
#include<math.h>

int main(){

int a[5];
double avg, var, stdev, zero, one, two, three, four;

printf("Enter an integer:   ");
scanf("%d", &a[0]);

printf("Enter an integer:   ");
scanf("%d", &a[1]);

printf("Enter an integer:   ");
scanf("%d", &a[2]);

printf("Enter an integer:   ");
scanf("%d", &a[3]);

printf("Enter an integer:   ");
scanf("%d", &a[4]);


avg =(double) (a[0] + a[1] + a[2] + a[3] + a[4])/5;

zero = (double) ((double)a[0] - avg);
one = (double) (a[1] - avg);
two = (double) (a[2] - avg);
three = (double) (a[3] - avg);
four = (double) (a[4] - avg);
printf("%lf %lf %lf %lf %lf", one, two, three, four, zero);
var =(double) ((pow(one,2)) + (pow(two,2)) + (pow(three,2)) + (pow(four,2)) + (pow(zero,2)))/5;

stdev =(double) sqrt(var);

printf("The average is %lf \n", avg);
printf("The variance is %lf \n", var);
printf("The standard deviation is %lf", stdev);

return 0;

}
