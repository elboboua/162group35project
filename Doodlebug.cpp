/**
 * Author: Eben Wight
 * Date: 2018/11/01
 * Description: Dooodle bug is the predator, he moves and, if possible,
 * his first move priority is to eat an ant in an adjacent cell
 *
 * inherits from Critter just like Ant does
 **/

#include "DoodleBug.hpp"
#include <cstdlib>
#include <iostream>
// The ant construct
Doodlebug::Doodlebug() : Critter() {
}

// This function returns true if the ant can breed and false if not
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
}