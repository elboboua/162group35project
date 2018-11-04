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
    int rounds;
    std::vector<std::string> messages;

  public:
    Game(int antNum = 100, int bugNum =5);
    void addBugsRandomly();
    Ant *getAnt(int index);
    Doodlebug *getBug(int index);
    void loop();
    void breedAnts();
	void breedDoodlebugs();
    int getAntNum();
    void setAntNum(int antNum);
    int getBugNum();
    void setBugNum(int bugNum);
	void removeDeadAnt(Board *board);
    void removeStarvedDoodlebug(Board * board);
};

#endif // GAME_H
