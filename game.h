#ifndef GAME_H
#define GAME_H

#include "helpers.h"
#include "board.h"
#include "player.h"

#define COMMAND_LOAD "load"
#define COMMAND_INIT "init"
#define COMMAND_FORWARD "forward"
#define COMMAND_FORWARD_SHORTCUT "f"
#define COMMAND_TURN_LEFT "turn_left"
#define COMMAND_TURN_LEFT_SHORTCUT "l"
#define COMMAND_TURN_RIGHT "turn_right"
#define COMMAND_TURN_RIGHT_SHORTCUT "r"
#define COMMAND_QUIT "quit"

#define DIRECTION_NORTH "north"
#define DIRECTION_EAST "east"
#define DIRECTION_SOUTH "south"
#define DIRECTION_WEST "west"

#define STR_LEN 250
#define TOKCOUNT 20
#define DELIM ", \n\t\b"

#define STATE_UNLOADED 0
#define STATE_LOADED 1
#define STATE_INIT 2

/**
 * Main menu option 1 - play the game as per the specification.
 *
 * This function makes all the calls to board & player and handles interaction
 * with the user (reading input from the console, error checking, etc...).
 *
 * It should be possible to break this function down into smaller functions -
 * but this is up to you to decide and is entirely your own design. You can
 * place the additional functions in this header file if you want.
 *
 * Note that if you don't break this function up it could become pretty big...
 */
void playGame();

#endif
