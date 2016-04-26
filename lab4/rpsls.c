#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int x = 0;

	if (strcmp(argv[1],"rock") == 0) {
		// Rock ties rock
		if (strcmp(argv[2], "rock") == 0) {
			x = 0;
			 
		}
		// Paper covers rock
		if (strcmp(argv[2], "paper") == 0) {
			x = 1;
			 
		}
		// Rock crushes scissors
		if (strcmp(argv[2], "scissors") == 0) {
			x = 1;
			 
		}
		// Rock crushes lizard
		if (strcmp(argv[2], "lizard") == 0) {
			x = 1;
			 
		}
		// Spock vaporizes rock
		if (strcmp(argv[2], "spock") == 0) {
			x = 2;
			 
		}
		 
	}

	if (strcmp(argv[1], "paper") == 0) {
		//  Paper covers rock
		if (strcmp(argv[2], "rock") == 0) {
			x = 1;
			 
		}
		// Paper ties paper
		if (strcmp(argv[2], "paper") == 0) {
			x = 0;
			 
		}
		// Scissors cut paper
		if (strcmp(argv[2], "scissors") == 0) {
			x = 2;
			 
		}
		// Liazard eats paper
		if (strcmp(argv[2], "lizard") == 0) {
			x = 2;
			 
		}
		// Paper disproves Spock
		if (strcmp(argv[2], "spock") == 0) {
			x = 1;
			 
		}
		 
	}
	if (strcmp(argv[1], "scissors") == 0) {
		// Rock crushes scissors
		if (strcmp(argv[2], "rock") == 0) {
			x = 2;
			 
		}
		// Scissors cuts paper
		if (strcmp(argv[2], "paper") == 0) {
			x = 1;
			 
		}
		// Scissors ties scissors
		if (strcmp(argv[2], "scissors") == 0) {
			x = 0;
			 
		}
		// Scissors decapitates lizard
		if (strcmp(argv[2], "lizard") == 0) {
			x = 1;
			 
		}
		// Spock vsmashes scissors
		if (strcmp(argv[2], "spock") == 0) {
			x = 2;
			 
		}
		 
	}
	if (strcmp(argv[1], "lizard") == 0) {
		// Rock crushes lizard
		if (strcmp(argv[2], "rock") == 0) {
			x = 2;
			 
		}
		// Lizard eats paper
		if (strcmp(argv[2], "paper") == 0) {
			x = 1;
			 
		}
		// Scissors decapitates lizard
		if (strcmp(argv[2], "scissors") == 0) {
			x = 2;
			 
		}
		// Lizard ties lizard
		if (strcmp(argv[2], "lizard") == 0) {
			x = 0;
			 
		}
		// Lizard poisons spock
		if (strcmp(argv[2], "spock") == 0) {
			x = 1;
			 
		}
		 
	}
	if (strcmp(argv[1], "spock") == 0) {
		// Spock vaperizes rock
		if (strcmp(argv[2], "rock") == 0) {
			x = 1;
			 
		}
		// Paper disproves spock
		if (strcmp(argv[2], "paper") == 0) {
			x = 2;
			 
		}
		// Spock crushes scissors
		if (strcmp(argv[2], "scissors") == 0) {
			x = 1;
			 
		}
		// Lizard poisons Spock
		if (strcmp(argv[2], "lizard") == 0) {
			x = 2;
			 
		}
		// Spock ties spock
		if (strcmp(argv[2], "spock") == 0) {
			x = 0;
			 
		}
		 
	}

	if (x == 1) {
		printf("Player 1 wins!");
	}
	if (x == 2) {
		printf("Player 2 wins!");
	}
	if (x == 0) { 
		printf("You tied!"); 
	}
	return 0;
}