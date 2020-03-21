/***************************************************************************//**
  @file         tic-tac-toe.c
  @author       Alexis Rodriguez
  @date         Created Thursday, 20 March 2020
  @brief        Tic tac toe implementation
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//        Colors        //
#define RED     "\x1b[91m"
#define YELLOW  "\x1b[93m"
#define BLUE    "\x1b[94m"
//    Original color    //
#define RESET   "\x1b[0m" 


#define CHOICE_X 'X'
#define CHOICE_O 'O'


// will be used to test the 
// status of the game
typedef enum {
	VICTORY,
	TIE,
	CONTINUE
} status;


/*      Functions Declarations      */
status showGrid(int position, bool player);
void startGame();
int promptUser();
// status checkStatus(char gridValue[][]);
char endGame(status check, bool player);



int main() {
	bool player = true;
	int position = 0;
	char playAgain;
	status game;

	startGame(); 
	do {
		game = showGrid(position, player);
		position = promptUser();
		player = !player;
	} while(game != VICTORY || game != TIE);
	playAgain = endGame(game, player);

	if(playAgain == 'Y' || playAgain == 'y')      /// start game over
		main()
	else
		return 0;
}


/*
 * Function: showGrid
 * -----------------------
 * Displays welcome message
 *
*/
status showGrid(int position, bool player) {
	static char marker;
	status v = CONTINUE;
	int grid[3][3] = {

		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'}
	};

	if(player == true)
		marker = CHOICE_X;
	else
		marker = CHOICE_O;

	// checking value of position
	// and changing value in 2-d grid
	// to X or O
	switch(position) {
		case 1:
			grid[0][0] = marker;
			break;
		case 2:
			grid[0][1] = marker;
			break;
		case 3:
			grid[0][2] = marker;
			break;
		case 4:
			grid[1][0] = marker;
			break;
		case 5:
			grid[1][1] = marker;
			break;
		case 6:
			grid[1][2] = marker;
			break;
		case 7:
			grid[2][0] = marker;
			break;
		case 8:
			grid[2][1] = marker;
			break;
		case 9:
			grid[2][2] = marker;
			break;

		default:
			printf("Invalid position!");
			exit(EXIT_SUCCESS);
	}

	/*                   THE GRID                     */
	printf(YELLOW "\n\n\n\t\t  %c  " RESET, grid[0][0]);
	printf(RED "|" RESET);
	printf(YELLOW "  %c  " RESET, grid[0][1]);
	printf(RED "|" RESET);
	printf(YELLOW "  %c  " RESET, grid[0][2]);
	printf(RED "\n\t\t-----------------\n" RESET);
	printf(YELLOW "\t\t  %c  " RESET, grid[1][0]);
	printf(RED "|" RESET);
	printf(YELLOW "  %c  " RESET, grid[1][1]);
	printf(RED "|" RESET);
	printf(YELLOW "  %c  " RESET, grid[1][2]);
	printf(RED "\n\t\t-----------------\n" RESET);
	printf(YELLOW "\t\t  %c  " RESET, grid[2][0]);
	printf(RED "|" RESET);
	printf(YELLOW "  %c  " RESET, grid[2][1]);
	printf(RED "|" RESET);
	printf(YELLOW "  %c  \n\n\n" RESET, grid[2][2]);

	// call checkStatus to check if victory or tie

	return v;
}


/*
 * Function: startGame
 * -----------------------
 * Displays welcome message
 *
*/
void startGame() {
	system("clear");
	printf(BLUE "\t       Welcome to tic tac toe!\n\n" RESET);
}


/*
 * Function: promptUser
 * -----------------------
 * Displays welcome message
 *
*/
int promptUser() {
	int selection = 0;
	printf("Choose a number from 1-9 (0 to exit program):> ");
	scanf("%d", &selection);

	if(selection == 0)
		exit(EXIT_SUCCESS);

	return selection;
}

/*
 * Function: checkStatus
 * -----------------------
 * Displays welcome message
 *
*/
// status checkStatus(char gridValue[][]) {
// }


/*
 * Function: endGame
 * -----------------------
 * Displays welcome message
 *
*/
char endGame(status check, bool player) {
	char playAgain;
	
	if(check == VICTORY && player == true)
		printf("Victory is yours, player X");

	else if(check == VICTORY && player == false)
		printf("Victory is yours, player O");

	else
		printf("A tie!");

	printf("Would you like to play again? (Y/n): ");
	scanf("%c", &playAgain);

	return playAgain;
}