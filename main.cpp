/*********************************************************************
** Author: Group 35
** Date: 11-4-2018
** Description: The main file for the 162 Group Project 
*********************************************************************/
#include "Game.hpp"


#include <cstdlib>
#include <ctime>
#include <iostream>

int main () {

	srand(time(NULL));

	Game game;
	game.loop();	

	return 0;
}
