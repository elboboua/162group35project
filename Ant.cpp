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
			if (xLoc > 0 && board->isCharX(xLoc-1, yLoc, ' ')) {
				xLoc--;
			}
			std::cout << "UP" << std::endl;
			break;

		// RIGHT
		case 1:
			if (yLoc < board->getColumns() && board->isCharX(xLoc, yLoc+1, ' ')) {
				yLoc++;
			}
			std::cout << "RIGHT" << std::endl;
			break;
		// DOWN
		case 2:
			if (xLoc < board->getRows() && board->isCharX(xLoc+1,yLoc, ' ')) {
				xLoc++;
			}
			std::cout << "DOWN" << std::endl;
			break;
		// LEFT
		case 3:
			if (yLoc > 0 && board->isCharX(xLoc, yLoc-1, ' ')) {
				yLoc--;
			}
			std::cout << "LEFT" << std::endl;
			break;

	}

	// place ant in new location	
	board->changeSpace(xLoc,yLoc, 'X');


}

