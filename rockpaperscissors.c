/**
 * This program simulates a continuous rock, paper, scissors game.
 * The game keeps track of the stats and the user can choose when to quit playing.
 *
 * @author     James Phan
 * @assignment ICS 212 Assignment 09
 * @date       9/29/22 
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// declare function prototypes
void introGame();
int randomVal();
void displayRound(char firstPlay, char secondPlay);

int main(void) {

	srand(time(NULL));  // seeds the random generator
	
	introGame();  // first function

	char userPlay;

	// initilalize/declare the stat counters
	int computerWins = 0;
	int userWins = 0;
	int ties = 0;
	
	/* Plays rock, paper, scissors game continuously.
	   The game stops if the user requests to quit. */
	do {
		// Ask the user to input what item they want to play
		printf("\nEnter 'r', 'p', or 's' for rock, paper, or scissors: ");
        	userPlay = getchar();
        	getchar();
		
		/* If the user inputs rock, paper, or scissors,
		   continue with rest of game. If not, 
		   display error message and ask for input again. */    
		if (userPlay == 'r' || userPlay == 'p' || userPlay == 's') {
			char computerPlay;
			
			int value = randomVal();  // second function

			/* If random value is 0, computer plays rock.
			   If random value is 1, computer plays paper.
			   If random value is 2, computer plays scissors. */
       			if (value == 0) {
                		computerPlay = 'r';
        		} else if (value == 1) {
                		computerPlay = 'p';
        		} else if (value == 2) {
                		computerPlay = 's';
        		}
			
			displayRound(userPlay, computerPlay);  // third function

			/* When the user and computer plays the same item, it is a tie.
			   There is only one scenario per item where the user wins. 
			   Any other scenario would be a computer win.
			   Display each outcome accordingly and increment its counter. */ 
			if (userPlay == computerPlay) {
                                printf("TIE!\n");
				ties++;
                        } else if ((userPlay == 'r') && (computerPlay == 's')) {
                                printf("YOU WIN!\n");
                                userWins++;
                        } else if ((userPlay == 'p') && (computerPlay == 'r')) {
                                printf("YOU WIN!\n");
                                userWins++;
                        } else if ((userPlay == 's') && (computerPlay == 'p')) {
                                printf("YOU WIN!\n");
                                userWins++;
                        } else {
                                printf("COMPUTER WINS!\n");
                                computerWins++;
                        }

        	} else if ((userPlay != 'r') && (userPlay != 'p') && (userPlay != 's') && (userPlay != 'q') && (userPlay != 'Q')){
                	printf("ERROR: '%c' is not a valid choice.\n", userPlay);
        	}



	} while ((userPlay != 'q') && (userPlay != 'Q'));

	// display stats of the game
	printf("\nUser Wins: %i", userWins);
	printf("\nComputer Wins: %i", computerWins);
	printf("\nTies: %i\n", ties);
	
	return 0;
}

/* Displays a message describing the game.
   Displays a message telling user how to quit. */
void introGame() {
	printf("This is a rock-paper-scissors game.");
        printf("\nTo quit the game, press Q or q and Enter.\n");
	return;
}

/* rand() function returns random number from 0-large number.
   % 3 gets remainder after dividing by 3, so 0,1,2. */
int randomVal() {
	int number = rand() % 3;
	return number;
}

/* Translates r, p, s into rock, paper, scissors.
   Considers all nine combinations in the game.
   Displays the combination if it has been played. */
void displayRound(char firstPlay, char secondPlay) {
	if ((firstPlay == 'r') && (secondPlay == 'r')) {
		printf("Rock vs. Rock. ");
	} else if ((firstPlay == 'r') && (secondPlay == 'p')) {
		printf("Rock vs. Paper. ");
	} else if ((firstPlay == 'r') && (secondPlay == 's')) {
		printf("Rock vs. Scissors. ");
	} else if ((firstPlay == 'p') && (secondPlay == 'p')) {
		printf("Paper vs. Paper. ");
	} else if ((firstPlay == 'p') && (secondPlay == 'r')) {
		printf("Paper vs. Rock. ");
	} else if ((firstPlay == 'p') && (secondPlay == 's')) {
		printf("Paper vs. Scissors. ");
	} else if ((firstPlay == 's') && (secondPlay == 's')) {
		printf("Scissors vs. Scissors. ");
	} else if ((firstPlay == 's') && (secondPlay == 'r')) {
		printf("Scissors vs. Rock. ");
	} else if ((firstPlay == 's') && (secondPlay == 'p')) {
		printf("Scissors vs. Paper. ");
	} 
	return;
}


