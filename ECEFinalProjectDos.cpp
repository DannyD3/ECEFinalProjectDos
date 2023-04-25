#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "card.c"

void createDeck(card deck[]);
void shuffleDeck(card deck[]);
void deal(card deck[]);
void draw(card deck[], int player);

int main(void) {

	//initializes deck
	card deck[108];

	//Gives each card a value, color, and pointer (I don't know what the action string is for yet)
	createDeck(deck);

	//Display deck to ensure everything is correct (display() is defined in card.c)
	for (int i = 0; i < 108; i++) {
	//	display(deck[i]);
	}

	shuffleDeck(deck);

	printf("SHUFFLED\n");

	//Display deck to ensure deck is shuffled
	for (int i = 0; i < 108; i++) {
	//	display(deck[i]);
	}

	deal(deck);

	printf("DEALT\n");

	//Display deck to ensure players have hands
	for (int i = 0; i < 108; i++) {
		display(deck[i]);
	}

	/*END OF SETUP*/


	return 0;

}

void createDeck(card deck[]) {

	int start = 0;
	int end = 24;

	while (end <= (24 * 4)) {
		for (int i = start; i < end; i++) {
			//Assign Value
			if (i < 3 + start) {
				deck[i].value = 1;
			} else if (i < 6 + start) {
				deck[i].value = 3;
			} else if (i < 9 + start) {
				deck[i].value = 4;
			} else if (i < 12 + start) {
				deck[i].value = 5;
			} else if (i < 14 + start) {
				deck[i].value = 6;
			} else if (i < 16 + start) {
				deck[i].value = 7;
			} else if (i < 18 + start) {
				deck[i].value = 8;
			} else if (i < 20 + start) {
				deck[i].value = 9;
			} else if (i < 22 + start) {
				deck[i].value = 10;
			} else if (i < 24 + start) {
				deck[i].value = '#';
			}
			//Assign Color
			if (start == 0) {
				strcpy(deck[i].color, "yellow");
			} else if (start == 24) {
				strcpy(deck[i].color, "red");
			} else if (start == 48) {
				strcpy(deck[i].color, "green");
			} else if (start == 72) {
				strcpy(deck[i].color, "blue");
			}
			//Assign Pointer
			deck[i].pt = &deck[i];
			//Assign Action
			strcpy(deck[i].action, "draw");
		}
		start += 24;
		end += 24;
	}

	end -= 12;

	for (int i = start; i < end; i++) {
		deck[i].value = 2;
		strcpy(deck[i].color, "wild");
		strcpy(deck[i].action, "draw");
	}

}

void shuffleDeck(card deck[]) {

	srand(time(NULL));   //Seed randomizer function
	int rA;
	int rB;
	card tempCard;

	//FOR loop swaps 1000 pairs of cards in the deck at random
	for (int i = 0; i < 1000; i++) {
		rA = rand() % 108;
		rB = rand() % 108;

		tempCard = deck[rA];
		deck[rA] = deck[rB];
		deck[rB] = tempCard;
	}

}

void deal(card deck[]) {
	int numCards = 7; //Number of cards dealt to each player in the beginning of the game

	for (int i = 1; i <= numCards * 2; i++) {
		if (i % 2 == 0) {
			draw(deck, 2);
		} else {
			draw(deck, 1);
		}
	}

	strcpy(deck[numCards * 2].action, "centerline");
	strcpy(deck[numCards * 2 + 1].action, "centerline");

}

void draw(card deck[], int player) {

	for (int i = 0; i < 108; i++) {
		if (strcmp(deck[i].action, "draw") == 0) {
			if (player == 1) {
				strcpy(deck[i].action, "player1");
			} else {
				strcpy(deck[i].action, "player2");
			}
			break;
		}
	}

}
