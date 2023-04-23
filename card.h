#ifndef CARD_H
#define CARD_H

typedef struct card_s {
	char color[10];
	int value;
	char action[15];
	struct card_s* pt;
} card;

//Function Declarations
void display(card thisCard);
//int match() {} //This function needs to compare the centerline card value and color with the matched cards' sum and colors 
//return 0 if not a match|1 if a number match|2 if a number and color match

#endif