/**
 * Author: Eben Wight
 * Date: 2018/11/01
 * Description: Dooodle bug is the predator, he moves and, if possible,
 * his first move priority is to eat an ant in an adjacent cell
 *
 * inherits from Critter just like Ant does
 **/

#include "Doodlebug.hpp"
#include <cstdlib>
#include <iostream>
// The Doodlebug construct
Doodlebug::Doodlebug() : Critter() {
	
	turnsSinceEating = 0;

}

// This function returns true if the Doodlebug can breed and false if not
bool Doodlebug::canBreed() {

    if (turnsSinceBreeding >= 8) {

        turnsSinceBreeding = 0;
        return true;
    } else {

        return false;
    }
}

void Doodlebug::move(Board *board) {

	bool willEat = false;
	int direction;

    checkSurroundings(board);

    // clear Previous location
    board->changeSpace(xLoc, yLoc, ' ');


    // once the place is changed, the previous place needs to be cleared.

    // this is the special code for hunting ants

    for (int s = 0; s < 4; s++) {
        if (surroundings[s] == EntityTypes::ANT && !willEat) {
    		direction = s;
			willEat= true;
        }
	} 

	if (willEat) {

		switch (direction) {

			// UP
			case UP:
				xLoc--;
				break;

			// RIGHT
			case RIGHT:
				yLoc++;
				break;
			// DOWN
			case DOWN:
				xLoc++;
				break;
			// LEFT
			case LEFT:
				yLoc--;
				break;
		}


		turnsSinceEating = 0;

    } else if (!willEat) {
		// gets random num 1-4
		// depending on this, the direction is chosen.
		int direction = rand() % 4;

		switch (direction) {

			// UP
			case UP:
				if (xLoc > 0) {
					if (board->isCharX(xLoc - 1, yLoc, Board::SPACE)) {
						xLoc--;
					}
				}
				break;

			// RIGHT
			case RIGHT:
				if (yLoc < board->getColumns() - 1) {
					if (board->isCharX(xLoc, yLoc + 1, Board::SPACE)) {
						yLoc++;
					}
				}
				break;
			// DOWN
			case DOWN:
				if (xLoc < board->getRows() - 1) {
					if (board->isCharX(xLoc + 1, yLoc, Board::SPACE)) {
						xLoc++;
					}
				}
				break;
			// LEFT
			case LEFT:
				if (yLoc > 0) {
					if (board->isCharX(xLoc, yLoc - 1, Board::SPACE)) {
						yLoc--;
					}
				}
				break;
		}

		
		turnsSinceEating++;
	}

    // place bug in new location
    board->changeSpace(xLoc, yLoc, Board::BUG);

    // ages the bug
    turnsSinceBreeding++;
}

void Doodlebug::randomPlacement(Board *board) {

	bool placed = false;
	int x, y;

	while (!placed) {

		x = rand()%board->getRows();
		y = rand()%board->getColumns();

		if (board->isCharX(x, y, ' ')) {
			xLoc=x;
			yLoc=y;
			board->changeSpace(xLoc,yLoc, Board::BUG);
			placed = true;
		}
	}
}

bool Doodlebug::hasStarved() {

	if (turnsSinceEating >= 3) {
		return true;
	} else {
		return false;
	}


}
