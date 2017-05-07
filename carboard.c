#include "carboard.h"
#include <stdio.h>
#include <string.h>

#define MENU_FALIURE 0
#define MENU_SUCCESS 1
#define MENU_EXIT 2

char* underLine(char* str, int length, char c) {
	int i;
	int indexOfNull = strlen(str);
	if(length >= 2 * indexOfNull) {
		str[indexOfNull] = '\n';
		for(i = indexOfNull + 1; i <= 2 * indexOfNull; i++) {
			str[i] = c;
		}
		str[i] = '\0';
	}
	return str;
}

void showMenu() {
	char welcome[STR_LEN] = "Welcome to Car Board";
	
	printf("%s\n", underLine(welcome, sizeof(welcome), '-'));
	printf("1. %s\n2. %s\n3. %s\n\n", "Play Game", 
		"Show Student Information", "Exit");
	printf("Please enter your choice: ");
}

#define CHOICE_GAME "1\n"
#define CHOICE_INFO "2\n"
#define CHOICE_QUIT "3\n"

int menu() {
	/* input vars */
	char input[STR_LEN];
	int inLength = STR_LEN;

	while(1) {
		showMenu();

		fgets(input, inLength, stdin); /*this puts /n on the end*/
		printf("\n");
		if(strcmp(input, CHOICE_GAME) == 0) {
			playGame();
		} else if(strcmp(input, CHOICE_INFO) == 0) {
			showStudentInformation();
		} else if(strcmp(input, CHOICE_QUIT) == 0) {
			printf("Exiting..\n");
			break;
		}
	}

	return 0;
}

void showStudentInformation()
{
	char line[STR_LEN] = "-------------------------";
	printf("%s\nNAME: %s\nNO: %s\nEMAIL: %s\n%s\n\n", line, 
		STUDENT_NAME, STUDENT_ID, STUDENT_EMAIL, line);
}

int main()
{
	int hardcoded = 5;
	int *myvalue;
	/*set the pointer to point to the hardcoded variable*/
	changePointer((void *)&myvalue, &hardcoded);
	printf("\nvalue: %d", *myvalue);
	printf("\n");
	printf("\n");

	menu();

	printf("\n");
	return EXIT_SUCCESS;
}
