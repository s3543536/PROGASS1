#include "game.h"

int parseInt(char* string, int* i) {
	char* stringEndPtr;

	*i = strtol(string, &stringEndPtr, 10);
	if(string == stringEndPtr || *stringEndPtr != '\0') {
		/*printf("NaN\nend: %x\n", *stringEndPtr);*/
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

void token(char* str, char* delim, char **tokens, int* tokCount) {
	int max = *tokCount;/*make tokCount the max number of tokens*/
	*tokCount = 0;
	/*tokenise the string*/
	tokens[0] = strtok(str, &*delim);
	
	while(tokens[*tokCount] != NULL && *tokCount < max) {
		(*tokCount)++;
		tokens[*tokCount] = strtok(NULL, &*delim);
		/* *(tokens + tokCount) should also work */
	}
}

void strToLower(char* s, int size) {
	int i;
	for(i = 0; i < size; i++) {
		s[i] = tolower(s[i]);
	}
}

int getStr(char* s, int size) {
	int i;

	fgets(s, size, stdin);
	strToLower(s, size);

	for(i = 0; i < size; i++) {
		if(s[i] == '\n') {
			/*printf("checkStr index (\\n): %d\n", i);*/
			s[i] = '\0';/*trim the \n*/
			if(s[0] == '\0')
				return EXIT_FAILURE;
			return EXIT_SUCCESS;
		}
	}


	readRestOfLine();
	printf("Input too Long\n");
	s[0] = '\0';
	return EXIT_FAILURE;
}

void printMenu(int stage) {
	char instructionText[STR_LEN] = "You can use the following commands"
					" to play the game:";
	char loadText[STR_LEN] = 	"load <g>"
					"\n\tg: number of the "
					"game board to load";
	char initText[STR_LEN] = 	"init <x>,<y>,<direction>"
					"\n\tx: horisontal position of the "
					"car on the board (between 0 & 9)"
					"\n\ty: vertical position of the car"
					" on the board (between 0 & 9)"
					"\n\tdirection: direction of the "
					"car's movement (north,"
					" east, south, west)";
	char movementText[STR_LEN] =	"forward (or f)\nturn_left"
					" (or l)\nturn_right (or r)";
	char quitText[STR_LEN] =	"quit";


	printf("\n%s\n", instructionText);
	switch(stage) {
		case STATE_UNLOADED:
			printf("%s\n", loadText);
		break;
		case STATE_LOADED:
			printf("%s\n", initText);
		break;
		case STATE_INIT:
			printf("%s\n", movementText);
		break;
		default:
			printf("%s\n%s\n%s\n", loadText, initText, movementText);
		break;
	}
	printf("%s\n", quitText);
}

void playGame() {
	Cell board[BOARD_HEIGHT][BOARD_WIDTH];
	int num;
	int num2;
	int tokNum;
	char* tokens[TOKCOUNT];
	/*2d array, tokens haven't been assigned yet*/
	char str[STR_LEN];
	Player player;
	int gameState = STATE_UNLOADED;
	PlayerMove playerMoved;
	int totalMoves = 0;

	initialiseBoard(board);
	for(;;) {

		if(gameState == STATE_INIT)
					displayBoard(board, &player);
		else
					displayBoard(board, NULL);
		printMenu(gameState);

		if(getStr(str, STR_LEN) == EXIT_SUCCESS) {

			tokNum = TOKCOUNT;
			/* tokens is the address of the first position */
			token(str, DELIM, tokens, &tokNum);
			
			/*load command*/	
			if(strcmp(COMMAND_LOAD, tokens[0]) == 0 
				&& tokNum == 2 
				&& gameState == STATE_UNLOADED) {

				parseInt(tokens[1], &num);
				gameState++;
				switch(num) {
					case 1:
						loadBoard(board, BOARD_1);
					break;
					case 2:
						loadBoard(board, BOARD_2);
					break;
					default:
						gameState--;
					break;
				}

			/*quit command*/
			} else if(strcmp(COMMAND_QUIT, tokens[0]) == 0 
				&& tokNum == 1) {

				printf("Total player moves: %d\n\n", totalMoves);
				return;	
			/*init command*/	
			} else if(strcmp(COMMAND_INIT, tokens[0]) == 0 
				&& tokNum == 4 
				&& gameState == STATE_LOADED) {

				parseInt(tokens[1], &num);
				parseInt(tokens[2], &num2);
				player.position.x = num;
				player.position.y = num2;


				if(strcmp(tokens[3], "north") == 0) {
					player.direction = NORTH;
				} else if(strcmp(tokens[3], "south") == 0) {
					player.direction = SOUTH;
				} else if(strcmp(tokens[3], "east") == 0) {
					player.direction = EAST;
				} else if(strcmp(tokens[3], "west") == 0) {
					player.direction = WEST;
				}
/*asdfsadf*/	
				if(placePlayer(board, player.position)) {
					gameState++;
				} else {
					printf("Invalid Input\n");
				}
			/*move forward command*/
			} else if((strcmp(COMMAND_FORWARD, tokens[0]) == 0 
				|| strcmp(COMMAND_FORWARD_SHORTCUT, 
					tokens[0]) == 0) 
				&& tokNum == 1 
				&& gameState == STATE_INIT) {

				playerMoved = movePlayerForward(board, &player);
				if(playerMoved == PLAYER_MOVED) {
					totalMoves++;
				} else if(playerMoved == CELL_BLOCKED) {
					printf("Cell Blocked\n");
				} else {
					printf("Out of Bounds\n");
				}
			/*turn left*/
			} else if((strcmp(COMMAND_TURN_LEFT, tokens[0]) == 0 
				|| strcmp(COMMAND_TURN_LEFT_SHORTCUT, 
					tokens[0]) == 0) 
				&& tokNum == 1 
				&& gameState == STATE_INIT) {

				/*direction is an enum with 4 states (ints 0,1,2,3)
 * 				this means we can increment it and use mod to
 * 				make sure the bounds are correct*/
				player.direction = (player.direction - 1) % 4;
			/*turn right*/
			} else if((strcmp(COMMAND_TURN_RIGHT, tokens[0]) == 0 
				|| strcmp(COMMAND_TURN_RIGHT_SHORTCUT, 
					tokens[0]) == 0) 
				&& tokNum == 1 
				&& gameState == STATE_INIT) {

				player.direction = (player.direction + 1) % 4;
			/*no command found*/
			} else {
				printf("Invalid Input\n");
			}
		}
	}
}




































