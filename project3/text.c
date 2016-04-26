//Daniel Church
//Dr. Zhang
//3/10/2016
//Project 3

//This program translates and combines two different peoples text
//messages into a single interface that can be read in 
//order based off of time.



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"scanner.h"
#include<time.h>


char *readableTime(int sec) {
 // this function takes an integer representing a time in seconds
 // it returns a formatted string that contains the date
 // the formatted string includes a newline character at the end
 time_t epoch_time = (time_t) sec;
 return asctime( localtime( &epoch_time ) );
}

//Take the string and find the length and subtract that length from
//the total width in order to find how many spaces you need to indent.
void indent(int dateLen, FILE *fw){
	int a, spaces;
	spaces = 30 - dateLen;
	for (a=0; a<=spaces; a++){
		fprintf(fw," ");
	}
}

//This function indents the distance for the second person.
void indentResp(FILE *fw) {
	int k = 0;
	for (k = 0; k < 35; k++) {
		fprintf(fw, " ");
	}
}

//This function closes all of the files
void close(FILE *fw, FILE *f1, FILE *f2) {
	fclose(fw);
	fclose(f1);
	fclose(f2);
}



int main(int argc, char **argv){
	//Opens all of the files necessary for this program
	FILE *f1 = fopen(argv[1], "r");
	FILE *f2 = fopen(argv[2], "r");
	FILE *fw = fopen("transcript", "w");

	//Creates a variable for each individual word to be stored in
	//before it is printed
	char *word;

	//Reads in the first date stamp for each file
	int num1 = readInt(f1);
	int num2 = readInt(f2);
	int words1 = 0, words2 = 0;
	int i=0;
	int length;

	while (!feof(f2) && !feof(f1)){
		//The if statement decides which text was sent first by taking the
		//smaller of the numbers and printing that line first
		if (num1>num2){
			indentResp(fw);
			//Reads the amount of words that are present in the message
			words2 = readInt(f2);
			//Reads the first word of the text and finds the initial value 
			//for the length
			i = 0;

			word = readToken(f2);
			length = strlen(word);
			//Itterates the number of times a word appears
			while (i < words2 - 1) {
				if (length <= 30) {
					fprintf(fw, "%s ", word);
					//Reads in the next word and adds its length
					word = readToken(f2);
					length = length + strlen(word) + 1;
					i++;
				}
				if (length > 30) {
					//Prints a new line and assigns and sets length back
					//equal to zero
					fprintf(fw, "\n");
					indentResp(fw);
					length = strlen(word);
				}
			}
			fprintf(fw, "%s", word);
			//Print a new line and indent for the date
			fprintf(fw, "\n");
			indentResp(fw);
			indent(strlen(readableTime(num2)), fw);
			//Prints the time stamp at the end of the message
			fprintf(fw, "%s\n", readableTime(num2));
			//Gets the next time stamp for num1 to compare with num1 to see
			//which should be printed next
			num2 = readInt(f2);
		}
		if (num2>num1){
			//Reads the amount of words that are present in the message
			words1 = readInt(f1);
			//Reads the first word of the text and finds the initial value 
			//for the length
			i = 0;

			word = readToken(f1);
			length = strlen(word);
			//Itterates the number of times a word appears
			while (i < words1 - 1) {
				if (length <= 30) {
					fprintf(fw, "%s ", word);
					//Reads in the next word and adds its length
					word = readToken(f1);
					length = length + strlen(word) + 1;
					i++;
				}
				if (length > 30) {
					//Prints a new line and assigns and sets length back
					//equal to zero
					fprintf(fw, "\n");
					length = strlen(word);
				}
			}
			fprintf(fw, "%s", word);
			//Print a new line and indent for the date
			fprintf(fw, "\n");
			indent(strlen(readableTime(num1)), fw);
			//Prints the time stamp at the end of the message
			fprintf(fw, "%s\n", readableTime(num1));
			//Gets the next time stamp for num1 to compare with num1 to see
			//which should be printed next
			num1 = readInt(f1);
		}
	}

	while (!feof(f2)) {
		indentResp(fw);
		//Reads the amount of words that are present in the message
		words2 = readInt(f2);
		//Reads the first word of the text and finds the initial value 
		//for the length
		i = 0;

		word = readToken(f2);
		length = strlen(word);
		//Itterates the number of times a word appears
		while (i < words2 - 1) {
			if (length <= 30) {
				fprintf(fw, "%s ", word);
				//Reads in the next word and adds its length
				word = readToken(f2);
				length = length + strlen(word) + 1;
				i++;
			}
			if (length > 30) {
				//Prints a new line and assigns and sets length back
				//equal to zero
				fprintf(fw, "\n");
				indentResp(fw);
				length = strlen(word);
			}
		}
		fprintf(fw, "%s", word);
		//Print a new line and indent for the date
		fprintf(fw, "\n");
		indentResp(fw);
		indent(strlen(readableTime(num2)), fw);
		//Prints the time stamp at the end of the message
		fprintf(fw, "%s\n", readableTime(num2));
		//Gets the next time stamp for num1 to compare with num1 to see
		//which should be printed next
		num2 = readInt(f2);
	}

	while (!feof(f1)) {
		//Reads the amount of words that are present in the message
		words1 = readInt(f1);
		//Reads the first word of the text and finds the initial value 
		//for the length
		i = 0;

		word = readToken(f1);
		length = strlen(word);
		//Itterates the number of times a word appears
		while (i < words1 - 1) {
			if (length <= 30) {
				fprintf(fw, "%s ", word);
				//Reads in the next word and adds its length
				word = readToken(f1);
				length = length + strlen(word) + 1;
				i++;
			}
			if (length > 30) {
				//Prints a new line and assigns and sets length back
				//equal to zero
				fprintf(fw, "\n");
				length = strlen(word);
			}
		}
		fprintf(fw, "%s", word);
		//Print a new line and indent for the date
		fprintf(fw, "\n");
		indent(strlen(readableTime(num1)), fw);
		//Prints the time stamp at the end of the message
		fprintf(fw, "%s\n", readableTime(num1));
		//Gets the next time stamp for num1 to compare with num1 to see
		//which should be printed next
		num1 = readInt(f1);
	}

	close(fw, f1, f2);

	return 0;
}
