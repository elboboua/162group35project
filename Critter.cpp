/*********************************************************************
** Description: The implementation file for the Critter base class
*********************************************************************/

#include "Critter.hpp"

Critter::Critter() {

    this->xLoc = 0;
    this->yLoc = 0;
    this->turnsSinceBreeding = 0;
}

int Critter::getXLoc() {

    return xLoc;
}

int Critter::getYLoc() {

    return yLoc;
}

void Critter::setXLoc(int xLoc) {

    this->xLoc = xLoc;
}

void Critter::setYLoc(int yLoc) {

    this->yLoc = yLoc;
}

void Critter::checkSurroundings(Board *board) {

	//starts making sure each surroundings  element is set to empty.
	//this is to ensure this code does no create a seg fault
	for (int i = 0; i < 4; i++) {
		surroundings[i] = EntityTypes::EMPTY;
	} 


    // when this loops throug 0 =3 those same index numbers refer to
    // the named enum's contained in board for UP, RIGHT, DOWN, LEFT,
    // it's just easier to write this way
    for (int i = 0; i < 4; i++) {

        int x = this->xLoc;
        int y = this->yLoc;
        switch (i) {
            case UP: {
				if (x > 0) {
					debug("critter.check Surroundings(), UP: ");
					x--;
					surroundings[UP] = board->checkSpace(x, y);
				}
            } break;

            case RIGHT: {
				if (y < board->getColumns()-1) {
					debug("critter.check Surroundings(), UP: ");
					y++;
					surroundings[RIGHT] = board->checkSpace(x, y);
				}
            } break;

            case DOWN: {
				if (x < board->getRows()-1) {
					debug("critter.check Surroundings(), UP: ");
					x++;
					surroundings[DOWN] = board->checkSpace(x, y);
				}
            } break;

            case LEFT: {
				if (y > 0) {	
					debug("critter.check Surroundings(), UP: ");
					y--;
					surroundings[LEFT] = board->checkSpace(x, y);
				}
            } break;

            default:
                break;
		
        }
    }
}
