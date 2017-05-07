#include "helpers.h"

void readRestOfLine()
{
    int ch;
    while(ch = getc(stdin), ch != EOF && ch != '\n')
    { } /* Gobble each character. */

    /* Reset the error status of the stream. */
    clearerr(stdin);
}

void changePointer(void **ptr, void *value) {
	*ptr = value;
}

void* twod_arr_copy(void *data, int xlen, int ylen, size_t s) {
	size_t full_len = xlen*ylen*s;
	void *new_array = malloc(full_len);

	if(new_array == NULL) {
		printf("Err: Out of Memory.\n");
		return NULL;
	}
	
	/*printf("New array is %d bytes long\n", (unsigned int) full_len); 
*/
	return memcpy(new_array, data, full_len);
}
 
void* twod_arr_repl(void *data, void *dest, int xlen, int ylen, size_t s) {
	size_t full_len = xlen*ylen*s;

	/*printf("Array should be %d bytes long\n", (unsigned int) full_len); 
	*/
	return memcpy(dest, data, full_len);
}
