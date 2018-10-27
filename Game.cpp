/********************************************************************* 
** Description: The implementation file for the Game class
*********************************************************************/ 

#include "Game.hpp"

Game::Game() {

	antNum=1;
	ant = new Ant[antNum];

	board = new Board(20,20);
	
	for (int i = 0; i < antNum; i++) {
	ant[i].randomPlacement(board);
	}
}

void Game::loop() {

	int rounds = 100;
	
	std::cout << "Initial placement:" << std::endl;
	board->displayBoard();
	std::cout << "Movements:" << std::endl;
	
		
	for (int i =0; i<rounds; i++) {
		std::cout << "Round " << i+1 << "." << std::endl;		
		breedAnts();
		for (int j = 0; j < antNum; j++) {
			ant[j].move(board);
		}		
		board->displayBoard();
	}	

	
}

// This functions checks if an ant can breed and if there is available space. If there is if makes an ant. 
void Game::breedAnts() {
	// loops through all the ants

	// creates a temp number to iterate through all old ants
	int tempAntNum = antNum;

	for (int i = 0; i < tempAntNum; i++) {
		// Checks if ant can breed
		if (ant[i].canBreed()) {

			// UP
			// checks if there is an upper space
			if (ant[i].getXLoc() > 0) {
				// checks if that space is clear
				if (board->isCharX(ant[i].getXLoc()-1,ant[i].getYLoc(), ' ')) {
					// resize dynamic array
					antNum++;
					Ant * temp = new Ant[antNum];
					for (int i = 0; i < antNum-1; i++) {
						temp[i] = ant[i];
					}
					
					// clear old array, give ant the bigger array, delete the temp array
					delete[] ant;
					ant = temp;
					
					// put the new ant in its right place
					ant[antNum-1].setXLoc(ant[i].getXLoc()-1);
					ant[antNum-1].setYLoc(ant[i].getYLoc());
				}

			}
	

		}
	}
}


