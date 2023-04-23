#include "card.h"

//Functions Definitions
void display(card thisCard) {
	printf("%s %d\n", thisCard.color, thisCard.value);
}
//int match() {} //This function needs to compare the centerline card value and color with the matched cards' sum and colors 
//return 0 if not a match|1 if a number match|2 if a number and color match
