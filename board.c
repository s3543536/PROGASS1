#include "board.h"

Cell BOARD_1[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY }
,
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY
 },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
};

Cell BOARD_2[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY
 },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
,
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
,
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
,
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
,
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
,
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

void initialiseBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
	int i;
	int j;
	for(j = 0; j < BOARD_HEIGHT; j++) {
		for(i = 0; i < BOARD_WIDTH; i++) {
			board[j][i] = EMPTY;
		}
	}
}

void initialiseBoard2(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
	/*I WILL NOT CONFORM TO YOUR DATA CONSTRUCTS*/
	int i;
	for(i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {
		*(*board + (i*sizeof(Cell))) = EMPTY;
	}
}

void loadBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
               Cell boardToLoad[BOARD_HEIGHT][BOARD_WIDTH])
{
	twod_arr_repl((void*) boardToLoad, (void*) board, BOARD_HEIGHT, 
			BOARD_WIDTH, sizeof(**boardToLoad));
	/*memcpy(board, boardToLoad, BOARD_HEIGHT * BOARD_WIDTH * sizeof(Cell));
*/
}

/*checks if the coordinates are within the board*/
Boolean validCoords(int* y, int* x) {
	if(*y < BOARD_HEIGHT && *y >= 0) {
		if(*x < BOARD_HEIGHT && *x >= 0) {
			return TRUE;
		}
	}
	return FALSE;
}

Boolean placePlayer(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Position position)
{
	if(validCoords(&position.y, &position.x) == TRUE) {
		if(board[position.y][position.x] == EMPTY) {
			board[position.y][position.x] = PLAYER;
			return TRUE;
		}
	}
	return FALSE;
}

void moveCoordsForward(int* y, int* x, Player* player) {
	switch(player->direction) {
		case NORTH:
			(*y)--;
		break;
		case SOUTH:
			(*y)++;
		break;
		case EAST:
			(*x)++;
		break;
		case WEST:
			(*x)--;
		break;
	}
}

PlayerMove movePlayerForward(Cell board[BOARD_HEIGHT][BOARD_WIDTH]
, Player * player) {
	int x = player->position.x;
	int y = player->position.y;

	moveCoordsForward(&y, &x, player);
	if(validCoords(&y, &x) == TRUE) {
		if(board[y][x] == EMPTY) {

			board[player->position.y][player->position.x] = EMPTY;
			board[y][x] = PLAYER;
			player->position.x = x;
			player->position.y = y;
		
			return PLAYER_MOVED;
		} else {
			return CELL_BLOCKED;
		}
	} else {
		return OUTSIDE_BOUNDS;
	}
}

void parseCell(Cell c, Player * player, char* str) {
	if(c == EMPTY) {
		sprintf(str, "%c", ' ');
		return;
	} else if(c == BLOCKED) {
		sprintf(str, "%c", '*');
		return;
	} else if(c == PLAYER && 1) {
		switch(/*(*player).direction*/player->direction) {
			case NORTH:
				sprintf(str, "%s", 
				DIRECTION_ARROW_OUTPUT_NORTH);
				break;
			case SOUTH:
				sprintf(str, "%s", 
				DIRECTION_ARROW_OUTPUT_SOUTH);
				break;
			case EAST:
				sprintf(str, "%s", DIRECTION_ARROW_OUTPUT_EAST);
				break;
			case WEST:
				sprintf(str, "%s", DIRECTION_ARROW_OUTPUT_WEST);
				break;
			default:
				sprintf(str, "%c", 'x');
				break;
				
		}
		return;
	} else {
		sprintf(str, "%c", 'x');
	}
}

void displayBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * player)
{
    /* TODO make it put the player... replace printf with sprintf and overwrite 
the strings */
	char str[STR_LEN];
	int i;
	int j;
	printf("\n");
	for(j = -1; j < BOARD_HEIGHT; j++) {
		printf("|");
		if(j == -1) {
			printf(" |");
			for(i = 0; i < BOARD_WIDTH; i++) {
				printf("%d|", i);
			}
		} else {
			printf("%d|", j);
			for(i = 0; i < BOARD_WIDTH; i++) {
				parseCell(board[j][i], player, str);
				printf("%s|", str);
			}
		}
		printf("\n");
	}
}



















