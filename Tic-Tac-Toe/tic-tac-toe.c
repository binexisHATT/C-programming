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
#define MAX_ATTEMPTS 9


// will be used to test the 
// status of the game
typedef enum {
	VICTORY,
	TIE,
	CONTINUE
} status;


/*         Functions Declarations        */
status showGrid(int position, bool player);
void startGame();
int promptPlayers(bool player);
status checkVictory(char gridValues[][3]);
void endGame(status check, bool player);


int main() {
	startGame();
	return 0;
}


/*
 * Function: startGame
 * -----------------------
 * Clears screen and displays welcome message.
 *
*/
void startGame() {
	system("clear");
	printf(BLUE "      Welcome to Tic Tac Toe by: Alexis Rodriguez\n\n" RESET);

	bool player = false;
	int position = 0, attempts = 0;
	char playAgain;
	status game;

	do {
		player = !player;
		game = showGrid(position, player);

		if(game == VICTORY)
			break;

		position = promptPlayers(player);
		system("clear");
		attempts++;
	} while(attempts < MAX_ATTEMPTS);

	if(attempts == MAX_ATTEMPTS)
		game = TIE;

	endGame(game, player);
}

/*
 * Function: showGrid
 * -----------------------
 * Displays the tic-tac-toe grid and alters the grid as
 * users provide their choices on the grid.
 * 
 * position: value on the grid from 1-9
 * player: the current players whose turn it is
*/
status showGrid(int position, bool player) {
	char marker;
	status check = CONTINUE;
	static char grid[3][3] = {

		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'}
	};

	if(player == true)
		marker = CHOICE_O;
	else
		marker = CHOICE_X;

	// checking value of position
	// and changing value in 2-d grid
	// to X or O
	switch(position) {
		case 0:
			break;
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
			printf("Invalid position!\n");
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

	return checkVictory(grid);
}


/*
 * Function: promptPlayers
 * -----------------------
 * Prompts user for valid number within game grid.
 *
*/
int promptPlayers(bool player) {
	int selection = 0;
	char whichPlayer;

	if(player)
		whichPlayer = CHOICE_X;
	else
		whichPlayer = CHOICE_O;

	printf("Player %c, pick a number from 1-9 (0 to exit program):> ", whichPlayer);
	scanf("%d", &selection);

	if(selection == 0)
		exit(EXIT_SUCCESS);

	return selection;
}

/*
 * Function: checkVictory
 * -----------------------
 * Checks if a player has won.
 * gridValues: 2d dimensional array containing the values of the current grid
*/
status checkVictory(char gridValues[][3]) {
	status determine = CONTINUE;

	// checking horizontal victories
	if((gridValues[0][0] == CHOICE_X && gridValues[0][1] == CHOICE_X && gridValues[0][2] == CHOICE_X) ||
		(gridValues[0][0] == CHOICE_O && gridValues[0][1] == CHOICE_O && gridValues[0][2] == CHOICE_O))
		determine = VICTORY;

	else if((gridValues[1][0] == CHOICE_X && gridValues[1][1] == CHOICE_X && gridValues[1][2] == CHOICE_X) ||
		(gridValues[1][0] == CHOICE_O && gridValues[1][1] == CHOICE_O && gridValues[1][2] == CHOICE_O))
		determine = VICTORY;

	else if((gridValues[2][0] == CHOICE_X && gridValues[2][1] == CHOICE_X && gridValues[2][2] == CHOICE_X) ||
		(gridValues[2][0] == CHOICE_O && gridValues[2][1] == CHOICE_O && gridValues[2][2] == CHOICE_O))
		determine = VICTORY;

	// checking diagonal victories
	else if((gridValues[0][0] == CHOICE_X && gridValues[1][1] == CHOICE_X && gridValues[2][2] == CHOICE_X) ||
		(gridValues[0][0] == CHOICE_O && gridValues[1][1] == CHOICE_O && gridValues[2][2] == CHOICE_O))
		determine = VICTORY;

	else if((gridValues[0][2] == CHOICE_X && gridValues[1][1] == CHOICE_X && gridValues[2][0] == CHOICE_X) ||
		(gridValues[0][2] == CHOICE_O && gridValues[1][1] == CHOICE_O && gridValues[2][0] == CHOICE_O))
		determine = VICTORY;

	// check vertical victories
	else if((gridValues[0][0] == CHOICE_X && gridValues[1][0] == CHOICE_X && gridValues[2][0] == CHOICE_X) ||
		(gridValues[0][0] == CHOICE_O && gridValues[1][0] == CHOICE_O && gridValues[2][0] == CHOICE_O))
		determine = VICTORY;

	else if((gridValues[0][1] == CHOICE_X && gridValues[1][1] == CHOICE_X && gridValues[2][1] == CHOICE_X) ||
		(gridValues[0][1] == CHOICE_O && gridValues[1][1] == CHOICE_O && gridValues[2][1] == CHOICE_O))
		determine = VICTORY;

	else if((gridValues[0][2] == CHOICE_X && gridValues[1][2] == CHOICE_X && gridValues[2][2] == CHOICE_X) ||
		(gridValues[0][2] == CHOICE_O && gridValues[1][2] == CHOICE_O && gridValues[2][2] == CHOICE_O))
		determine = VICTORY;

	return determine;
}


/*
 * Function: endGame
 * -----------------------
 * Displays which user won the game and asks the users if they would
 * like to continue playing the game.
 * 
 * check: status enum type containing the games results
 * player: the player who won the game determined by boolean
*/
void endGame(status check, bool player) {
	if(check == VICTORY && player == false)
		printf(BLUE "Victory is yours, player X!\n" RESET);

	else if(check == VICTORY && player == true)
		printf(BLUE "Victory is yours, player O!\n" RESET);

	else
		printf(BLUE "A tie!\n" RESET);
}