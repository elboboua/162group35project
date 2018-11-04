/*********************************************************************
** Author: Group 35
** Date: 11-4-2018
** Description: The main file for the 162 Group Project
*********************************************************************/
#include "Game.hpp"
#include "inputHandler.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {

	bool quit = false;


	// simple menu loop for the one input we need to check
	while (!quit) {
			
		int input;

		Game game;
		srand(time(NULL));
		
		game.loop();

		// separate the boards
		for (int i = 0; i < 20; i ++) {
			std::cout << std::endl;
		}
		std::cout << "Would you like to run the simulation again?" << std::endl;
		std::cout << "Enter 1 for yes, 0 for no: " << std::endl;
		input = inputHandler::isIntBetweenXAndY(0,1);	

		if (input == 0) {
			quit = true;
		}
	}
    return 0;
}
