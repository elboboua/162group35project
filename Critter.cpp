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

    // when this loops throug 0 =3 those same index numbers refer to
    // the named enum's contained in board for UP, RIGHT, DOWN, LEFT,
    // it's just easier to write this way
    for (int i = 0; i < 4; i++) {

        int x = this->xLoc;
        int y = this->yLoc;
        switch (i) {
            case UP: {
                debug("critter.check Surroundings(), UP: ");
                y--;
                surroundings[UP] = board->checkSpace(x, y);

            } break;

            case RIGHT: {
                debug("critter.check Surroundings(), UP: ");
                y--;
                surroundings[RIGHT] = board->checkSpace(x, y);

            } break;

            case DOWN: {
                debug("critter.check Surroundings(), UP: ");
                y--;
                surroundings[DOWN] = board->checkSpace(x, y);

            } break;

            case LEFT: {
                debug("critter.check Surroundings(), UP: ");
                y--;
                surroundings[LEFT] = board->checkSpace(x, y);

            } break;

            default:
                break;
        }
    }
}
