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
    //Menu menu;

    srand(time(NULL));

    game.loop();

    return 0;
}
