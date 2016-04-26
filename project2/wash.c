/* wash.c

Daniel Church
Dr. Zhang
3-2-2016
CS 100

The purpose of this program is to help you decided whether or not you should wear a certain piece of clothing based off of what it is, how it smeels, if there are any stains and how many times you have already worn it.

*/

#include<stdio.h>
#include"scanner.h"
#include<string.h>
#include<stdlib.h>


//This function takes in the kind of piece of clothing the person would like to wear.'
char* kindTest(void){
	printf("What kind? ");
	return readToken(stdin);
}

//This function takes in the smell of the piece of clothing.
char* smellTest(){
	printf("How does it smell? ");
	return readToken(stdin);
}

//This function takes in the amount of stains on the piece of clothing that is in question.
char* stainTest(){
	printf("Are there any stains on it? ");
	return readToken(stdin);
}

//This function takes in the amount of itmes that a piece of clothing was worn.
int wornTest(){
	printf("How many times have you worn them? ");
	return atoi(readToken(stdin));
}

int main(){
	char* type;
	int worn;
	printf("What are you considering? ");
	type = readToken(stdin);
	int x = 0;

	if (strcmp(type, "shirt") == 0)
	{
		char* kind = kindTest();
		if (strcmp(kind, "t-shirt")==0)
		{
			char* smell = smellTest();
			if (strcmp(smell, "fine")==0 || strcmp(smell, "marginal")==0)
			{
				char* stain = stainTest();
				if (strcmp(stain, "none")==0 || strcmp(stain, "small")==0)
				{
					x = 1;
				}
				if (strcmp(stain, "lots")==0)
				{
					x = 2;
				}
			}
			if (strcmp(smell, "bad")==0){
				x = 2;
			}

		}
		if (strcmp(kind, "nice")==0)
		{
			char* stain = stainTest();
			if (strcmp(stain, "none")==0)
			{
				x = 1;
			}
			if (strcmp(stain, "lots")==0 || strcmp(stain, "small")==0)
			{
				x = 2;
			}
		}
		if (strcmp(kind, "sweatshirt")==0)
		{
			worn = wornTest();
			if (worn<3)
			{
				char* stain = stainTest();
				if (strcmp(stain, "none")==0 || strcmp(stain, "small")==0)
				{
					x = 1;
				}
				if (strcmp(stain, "lots")==0)
				{
					x = 2;
				}
			}
			if (worn>=3)
			{
				char* smell = smellTest();
				if (strcmp(smell, "fine")==0)
				{
					x = 1;
				}
				if (strcmp(smell, "bad")==0  || strcmp(smell, "marginal")==0){
					x = 2;
				}
			}
		}
	}
	if (strcmp(type, "pants") == 0)
	{
		char* kind = kindTest();
		if (strcmp(kind, "jeans")==0)
		{
			worn = wornTest();
			if (worn<5)
			{
				x = 1;
			}
			if (worn>=5)
			{
				char* smell = smellTest();
				if (strcmp(smell, "fine")==0  || strcmp(smell, "marginal")==0)
				{
					char* stain = stainTest();
					if (strcmp(stain, "none")==0 || strcmp(stain, "small")==0)
					{
						x = 1;
					}
					if (strcmp(stain, "lots")==0)
					{
						x = 2;
					}
				}
				if (strcmp(smell, "bad")==0)
				{
					x = 2;
				}
			}
		}
		if (strcmp(kind, "other") == 0)
		{
			char* stain = stainTest();
			if (strcmp(stain, "none")==0)
			{
				x = 1;
			}
			if (strcmp(stain, "lots")==0 || strcmp(stain, "small")==0)
			{
				x = 2;
			}
		}
	}
	if (strcmp(type, "other") == 0)
	{
		char* kind = kindTest();
		if (strcmp(kind, "socks")==0)
		{
			worn = wornTest();
			if (worn==0)
			{
				x = 1;
			}
			if (worn>=1)
			{
				char* smell = smellTest();
				if (strcmp(smell, "fine")==0)
				{
					x = 1;
				}
				if (strcmp(smell, "bad")==0  || strcmp(smell, "marginal")==0){
					x = 2;
				}
			}
		}
		if (strcmp(kind, "other")==0)
		{
			worn = wornTest();
			if (worn==1)
			{
				char* stain = stainTest();
				if (strcmp(stain, "none")==0)
				{
					x = 1;
				}
				if (strcmp(stain, "lots")==0 || strcmp(stain, "small")==0)
				{
					x = 2;
				}
			}
			if (worn>=1)
			{
				char* smell = smellTest();
				if (strcmp(smell, "fine")==0  || strcmp(smell, "marginal")==0)
				{
					x = 1;
				}
				if (strcmp(smell, "bad")==0)
				{
					x = 2;
				}
			}
		}
	}
	
	if (x==1)
	{
		printf("Wear it");
		return 0;
	}
	if (x==2)
	{
		printf("Wash it");
		return 0;
	}


	return 0;
}