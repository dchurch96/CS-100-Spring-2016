#include<stdio.h>


int main(){

int q,d,n,p,cents;

printf("How many cents do you have?   ");
scanf("%d", &cents);

q = cents/25;
cents = cents%25;
d = cents/10;
cents = cents%10;
n = cents/5;
cents = cents%5;
p = cents/1;

printf("You have %d quarters.\n", q);
printf("You have %d dimes.\n", d);
printf("You have %d nickels.\n", n);
printf("You have %d pennies.", p);

return 0;

}
