#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int placar(int scoreboardPoints, int try);

int main () {
	int segundos = time(0);
	srand(segundos);

	int secretNumber, userNumber;
	int difficultyNumber = 0;
	int try = 1;
	int points;


	printf("   ___                             ___                  \n");    
	printf("  / __|  _  _   ___   ___  ___    / __|  __ _   _ __    ___ \n");
	printf(" | (_ | | || | / -_) (_-< (_-<   | (_ | / _` | | '  \\  / -_)\n");
	printf("  \\___|  \\_,_| \\___| /__/ /__/    \\___| \\__,_| |_|_|_| \\___|\n\n");


	while(difficultyNumber != 1 && difficultyNumber != 2 && difficultyNumber != 3 && difficultyNumber != 4) {
		printf("\n> What's difficulty level.\n");
		printf("\n(1) Easy (between 1 and 100)\n(2) Medium (between 1 and 10000)\n(3) Hard (between 1 and 1000000)\n(4) Quit\n > ");
		scanf("%d", &difficultyNumber);
	}

	switch(difficultyNumber) {
		case 1:
			secretNumber = rand()%100;
			points = 1000;
			break;
		case 2:
			secretNumber = rand()%10000;
			points = 10000;
			break;
		case 3:
			secretNumber = rand()%1000000;
			points = 100000;
			break;
		case 4:
			return 0;
			break;
	}

	placar(points, try);
	printf("\nTry to guess the secret number... Tell me a number: ");
	scanf("%d", &userNumber);


	while(userNumber != secretNumber) {

		try++;
		points = points - abs((secretNumber - userNumber)/2);

		if(points <= 0) {
			printf("Oh oh... You lose :(.");
			return 1;
			break;
		}

		placar(points, try);
		printf("\nOps... wrong number. Try again.");
		if(userNumber > secretNumber) {
			printf("\nThe number is less than %d.\n ", userNumber);
			scanf("%d", &userNumber);
		} else if (userNumber < secretNumber) {
			printf("\nThe number is higher than %d.\n ", userNumber);
			scanf("%d", &userNumber);
		}
	}

	if(userNumber == secretNumber) {
		printf("\nCONGRATULATIONS USER, YOU DISCOVERED THE NUMBER IN THE <%d> TRY !!!\n THE NUMBER: <%d>\n", try, secretNumber);
		printf("\nTOTAL POINTS: %d\nTOTAL TRIES: %d\n", points, try);
		return 1;
	}
}

int placar(int scoreboardPoints, int try) {
	printf("\n[ Points: %d ]", scoreboardPoints);
	printf("\n[ Try: <%d> ]", try);
	return 1;
}