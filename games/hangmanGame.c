#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50 

void printHangmanScreen();
void printScreenStartGame();
int verifyShot(char shotUser, char allShots [SIZE]);
int verifyIfExistsWordInArray(char shotUser, char secretWord [SIZE]);
void hangman(int * attempts, char secretWord [SIZE]);
int lettersIn(char secretWord [SIZE]);
void optionsUser(int * userChoice, int * attempts, int * tries);
void shot(char allShots[SIZE], int * tries, int *attempts, char secretWord[SIZE], int * num);
void printTrophy();


int main() {
	system("cls");

	printHangmanScreen();

	Sleep(500);

	printScreenStartGame();

	return 1;}

void printHangmanScreen() {

	printf("  ______________________________\n");
	Sleep(50);
	printf(" / \\                             \\.\n");
	Sleep(50);
	printf("|   |       Be welcome            |.\n");
	Sleep(50);
	printf(" \\_ |                            |.\n");
	Sleep(50);
	printf("    |            To              |.\n");
	Sleep(50);
	printf("    |                            |.\n");
	Sleep(50);
	printf("    |        HangmanGame         |.\n");
	Sleep(50);
	printf("    |                            |.\n");
	Sleep(50);
	printf("    |                            |.\n");
	Sleep(50);
	printf("    |                            |.\n");
	Sleep(50);
	printf("    |                            |.\n");
	Sleep(50);
	printf("    |       Developed By:        |.\n");
	Sleep(50);
	printf("    |            Ivi ;)          |.\n");
	Sleep(50);
	printf("    |                            |.\n");
	Sleep(50);
	printf("    |                            |.\n");
	Sleep(50);
	printf("    |   _________________________|___\n");
	Sleep(50);
	printf("    |  /                            /.\n");
	Sleep(50);
	printf("    \\_/--__________________________/.\n");}

void printScreenStartGame() {
	

	while(1) {
		int tries = 0;

		int attempts = 6;
		int userChoice = 0;

		printf("\n\n\n ____________________\n");
		Sleep(50);
		printf("/___________________(1) Choose a word. \n");
		Sleep(50);
		printf("| ___________________\n");
		Sleep(50);
		printf("| | |_______________(2) This choice do nothing :(...\n");
		Sleep(50);
		printf("| |/_________________\n");
		Sleep(50);
		printf("|___________________(3) Quit.\n > ");

		scanf("%d", &userChoice);

		optionsUser(&userChoice, &attempts, &tries);

		if(userChoice == 3) {
			break;
		}

		

	}}

int verifyIfExistsWordInArray(char shotUser, char secretWord [SIZE]) {
	for(int i = 0; i < strlen(secretWord); i++) {
		if(secretWord[i] == shotUser) {
			return 1;
		}
	}
	return 0;}

int verifyShot(char shotUser, char allShots [SIZE]) {

	for(int i = 0; i < strlen(allShots); i++) {
		if (allShots[i] == shotUser) {
			return 1;
		}
	}

	return 0;}

void shot(char allShots[SIZE], int * tries, int *attempts, char secretWord[SIZE], int * num) {
	char shotUser;

	printf("\n\n > ");
	scanf(" %c", &shotUser);

	while(verifyShot(shotUser, allShots)) {
		printf("\nChoice other letter. You already said that ;)!");
		printf("\n\n > ");
		scanf(" %c", &shotUser);
	}

	if(!verifyShot(shotUser, allShots)) {
		allShots[(*tries)] = shotUser;
		if(!verifyIfExistsWordInArray(shotUser, secretWord)) {
			(*attempts)--;
		}
		else {
			(*num)++;
		}
		(*tries)++;

	}}

int lettersIn(char secretWord [SIZE]) {
	char letters [26];
	int found = 0;

	for (int i = 0; i < strlen(secretWord); i++) {
		for(int j = 0; j < strlen(letters); j++) {
			if(!(verifyIfExistsWordInArray(secretWord[i], letters))) {
				letters[i] = secretWord[i];
				found++;
			}
		}
	}
	return found;}

void optionsUser(int * userChoice, int * attempts, int * tries) {
	switch((*userChoice)) {
			case 1:
				system("cls");
				char secretWord[SIZE];
				char allShots[SIZE];
				int num = 0;

				printf("Tell us a word. \n > ");
				scanf("%s", &secretWord);

				Sleep(500);

				while(attempts > 0) {

					system("cls");
					printf("\n\nRemaining Attempts: <%d>\nCurrent Attempt: <%d>\n\n", (*attempts), (*tries));
					hangman(&(*attempts), secretWord);

					for(int i = 0; i < strlen(secretWord); i++) {
						int found = 0;

						for(int j = 0; j < (*tries); j++) {
							if(allShots[j] == secretWord[i]) {
								
								found = 1;
								break;
							}  
						}	

						if(found) {
							printf(" %c ", secretWord[i]);
						} else {
							printf(" _ ");
						}
					}

					if (num == lettersIn(secretWord)) {
						system("cls");
						printf("\n\nCONGRATULATIONS, YOU DISCOVERED THE SECRET WORD!\n <%s>", secretWord);
						printTrophy();

						Sleep(4000);
						system("cls");
						break;
					} else {
						shot(allShots, &(*tries), &(*attempts), secretWord, &num);
					}
					
					if ((*attempts) == 0) {
						printf("\n...");
						Sleep(500);
						printf("\n...");
						Sleep(500);
						system("cls");
						hangman(&(*attempts), secretWord);
						Sleep(4000);
						break;
					}
				}
				break;
			case 2:
				system("cls");
				Sleep(500);
				printf("...");
				Sleep(500);
				printf("\n...");
				Sleep(500);
				printf("\n...");
				Sleep(500);
				printf("\n...");
				printf("\nI told you that this button doesn't do anything... Trust more in me, i'm not a bad person :(\n\n");
				break;
			case 3:
				system("cls");
				Sleep(50);
				printf("\n\nGoodbye :)!\n\n");
				Sleep(300);
				break;
		}
	}	

void hangman(int * attempts, char secretWord [SIZE]) {
	if((*attempts) == 6) {
		printf("      _______\n");
		printf("     |/      |\n");
		printf("     |      \n");
		printf("     |      \n");
		printf("     |       \n");
		printf("     |      \n");
		printf("     |\n");
		printf("    _|___\n\n");
	} else if ((*attempts) == 5) {
		printf("      _______\n");
		printf("     |/      |\n");
		printf("     |      (_)\n");
		printf("     |      \n");
		printf("     |       \n");
		printf("     |       \n");
		printf("     |\n");
		printf("    _|___\n\n");
	} else if ((*attempts) == 4) {
		printf("      _______\n");
		printf("     |/      |\n");
		printf("     |      (_)\n");
		printf("     |       |\n");
		printf("     |       |\n");
		printf("     |      \n");
		printf("     |\n");
		printf("    _|___\n\n");		
	} else if ((*attempts) == 3) {
				printf("      _______\n");
		printf("     |/      |\n");
		printf("     |      (_)\n");
		printf("     |      \\|\n");
		printf("     |       |\n");
		printf("     |      \n");
		printf("     |\n");
		printf("    _|___\n\n");
	} else if((*attempts) == 2) {
				printf("      _______\n");
		printf("     |/      |\n");
		printf("     |      (_)\n");
		printf("     |      \\|/\n");
		printf("     |       |\n");
		printf("     |      \n");
		printf("     |\n");
		printf("    _|___\n\n");
	} else if ((*attempts) == 1) {
				printf("      _______\n");
		printf("     |/      |\n");
		printf("     |      (_)\n");
		printf("     |      \\|/\n");
		printf("     |       |\n");
		printf("     |      / \n");
		printf("     |\n");
		printf("    _|___\n\n");
	} else if((*attempts) == 0) {
		printf("      _______\n");
		printf("     |/      |\n");
		printf("     |      (X)\n");
		printf("     |      \\|/\n");
		printf("     |       |\n");
		printf("     |      / \\\n");
		printf("     |\n");
		printf("    _|___\n");
		printf("\n\n YOU LOSE HAHA!! \n The correct word is: %s", secretWord);
	} }

void printTrophy() {
	printf("\n\n     _______________\n");
	printf("    |@@@@|     |####|\n");
	printf("    |@@@@|     |####|\n");
	printf("    |@@@@|     |####|\n");
	printf("    \\@@@@|     |####/\n");
	printf("     \\@@@|     |###/\n");
	printf("      `@@|_____|##'\n");
	printf("          (O)\n");
	printf("        .-'''''-.\n");
	printf("      .'  * * *  `.\n");
	printf("     :  *       *  :\n");
	printf("    : ~  HANGMAN  ~ :\n");
	printf("    : ~ A W A R D ~ :\n");
	printf("     `.  * * *    .'\n");
	printf("       `-.. ...- '\n");}