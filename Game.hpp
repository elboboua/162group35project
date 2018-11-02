/*********************************************************************
** Description: The specification for the Game class
*********************************************************************/

#ifndef GAME_H
#define GAME_H

#include "Ant.hpp"
#include "Board.hpp"
#include "Doodlebug.hpp"

#include <iostream>

class Game {

  private:
    Ant *ant;
    int antNum;
    Doodlebug *bugs;
    int bugNum;
    Board *board;

  public:
    Game();
    void loop();
    void breedAnts();

    // breedDoodlebug
    // killDoodlebug
    // killAnt
};

#endif // GAME_H
