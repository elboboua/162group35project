/*********************************************************************
** Description: The implementation file for the Ant derived class
*********************************************************************/

#include "Ant.hpp"
#include <cstdlib>
#include <iostream>
// The ant construct
Ant::Ant() : Critter() {
}

// This function returns true if the ant can breed and false if not
bool Ant::canBreed() {

    if (turnsSinceBreeding == 3) {

        turnsSinceBreeding = 0;
        return true;
    } else {

        return false;
    }
}

// This function moves the ant
void Ant::move(Board *board) {
    // clear Previous location
    board->changeSpace(xLoc, yLoc, ' ');

    // gets random num 1-4
    // depending on this, the direction is chosen.

    // once the place is changed, the previous place needs to be cleared.

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

    // place ant in new location
    board->changeSpace(xLoc, yLoc, Board::ANT);

    // age the ant
    turnsSinceBreeding++;
}

// Places the ant in a random open location
void Ant::randomPlacement(Board *board) {

    bool placed = false;
    int x, y;

    while (!placed) {
        x = rand() % board->getRows();
        y = rand() % board->getColumns();

        if (board->isCharX(x, y, ' ')) {
            xLoc = x;
            yLoc = y;
            board->changeSpace(xLoc, yLoc, Board::ANT);
            placed = true;
        }
    }
}
