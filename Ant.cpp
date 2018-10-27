/********************************************************************* 
** Description: The implementation file for the Ant derived class
*********************************************************************/ 

#include "Ant.hpp"
#include <cstdlib>
#include <iostream>
// The ant construct
Ant::Ant(): Critter() {

}

// This function returns true if the ant can breed and false if not
bool Ant::canBreed() {

	if (turnsSinceBreeding ==3) {
		
		turnsSinceBreeding =0;
		return true;

	} else {

		return false;

	}

}

// This function moves the ant
void Ant::move(Board * board) {
	//clear Previous location
	board->changeSpace(xLoc,yLoc, ' ');

	// gets random num 1-4
	// depending on this, the direction is chosen. 

	// once the place is changed, the previous place needs to be cleared.

	int direction = rand()%4;

	switch (direction) {
		
		// UP
		case 0:
			if (xLoc > 0) {
				if (board->isCharX(xLoc-1, yLoc, ' ')) {
					xLoc--;
				}
			}
			break;

		// RIGHT
		case 1:
			if (yLoc < board->getColumns()-1) {
				if (board->isCharX(xLoc, yLoc+1, ' ')) {
					yLoc++;
				}
			}
			break;
		// DOWN
		case 2:
			if (xLoc < board->getRows()-1) {
				if (board->isCharX(xLoc+1,yLoc, ' ')) {
					xLoc++;
				}
			}
			break;
		// LEFT
		case 3:
			if (yLoc > 0) {
				if (board->isCharX(xLoc, yLoc-1, ' ')) {
					yLoc--;
				}
			}
			break;

	}

	// place ant in new location	
	board->changeSpace(xLoc,yLoc, 'X');

	// age the ant
	turnsSinceBreeding++;
}

// Places the ant in a random open location
void Ant::randomPlacement(Board * board) {

	bool placed = false;
	int x,y;	

	while (!placed) {
		x = rand()%board->getRows();
		y = rand()%board->getColumns();

		if (board->isCharX(x,y,' ')) {
			xLoc = x;
			yLoc = y;
			board->changeSpace(xLoc, yLoc, 'X');
			placed = true;
		}
	
	}
}
