#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include "card.c"

void createDeck(card deck[]);

int main(void) {

	//initializes deck
	card deck[108];

	//Gives each card a value, color, and pointer (I don't know what the action string is for yet)
	createDeck(deck);

	//Display deck to ensure everything is correct
	for (int i = 0; i < 108; i++) {
		display(deck[i]);
	}

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
		}
		start += 24;
		end += 24;
	}

	end -= 12;

	for (int i = start; i < end; i++) {
		deck[i].value = 2;
		strcpy(deck[i].color, "wild");
	}
}