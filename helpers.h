#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

typedef enum boolean
{
    FALSE = 0,
    TRUE
} Boolean;

#define NEW_LINE_SPACE 1
#define NULL_SPACE 1

/**
 * This is used to compensate for the extra character spaces taken up by
 * the '\n' and '\0' when input is read through fgets().
 **/
#define EXTRA_SPACES (NEW_LINE_SPACE + NULL_SPACE)

#define EMPTY_STRING ""

/**
 * Call this function whenever you detect buffer overflow but only call this
 * function when this has happened.
 **/
void readRestOfLine();

/**
 * my function to change a pointer instead of copying the value
 **/
void changePointer(void **ptr, void *value);

#endif

/**
 * creates new array and copies to it
 */
void* twod_arr_copy(void *data, int xlen, int ylen, size_t s);

/**
 * copy into existing 2d array
 * -assumes they are the same size
 */
void* twod_arr_repl(void *data, void *dest, int xlen, int ylen, size_t s);
