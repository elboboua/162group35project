/*********************************************************************
** Author: Group 35
** Date: 11-4-2018
** Description: The main file for the 162 Group Project
*********************************************************************/
#include "Game.hpp"
#include "Menu.hpp"
#include "inputHandler.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

// menu choice and prompt constants
const std::string HowManyAnts = "How Many Ants would you like to spawn?";
const std::string HowManBugs = "How Many Doodlebugs would you like to spawn?";
const std::string antNo = "Ant No. ";
const std::string bugNo = "Doodlebug No. ";
const std::string startingX = "'s starting X position";
const std::string startingY = "'s starting Y position";
int main() {

    Game game;
    Menu menu;

    int numAnts = 1;
    int nnumBugs = 1;
    menu.singleInteger(HowManyAnts, numAnts, false);

    for (int a = 0; a < numAnts; a++) {

        int startX = 3;
        menu.singleInteger(antNo + std::to_string(a) + startingX, startX, false);

        int startY = 3;
        menu.singleInteger(antNo + std::to_string(a) + startingY, startY, false);
    }

    // const std::string bugsStartingX = "Doodlebug's starting X position";
    // int bugX = 3;
    // menu.singleInteger(bugsStartingX, bugX, false);
    //
    // const std::string bugsStartingY = "Doodlebug's starting Y position";
    // int bugY = 3;
    // menu.singleInteger(bugsStartingY, bugY, false);
    srand(time(NULL));

    game.loop();

    return 0;
}
