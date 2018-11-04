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

    checkSurroundings(board);
    // clear Previous location
    board->changeSpace(xLoc, yLoc, ' ');

    // gets random num 1-4
    // depending on this, the direction is chosen.

    // once the place is changed, the previous place needs to be cleared.

    // this is the special code for hunting ants
    int direction = direction = rand() % 4;
    ;
    for (int s = 0; s < 4; s++) {
        if (surroundings[s] == EntityTypes::ANT) {
            direction = s;
        }
    }

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