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

	bool madeBaby = false;
	bool triedUp= false;
	bool triedDown = false;
	bool triedRight = false;
	bool triedLeft = false;
			do {
				
				int direction = rand()%4;

				switch (direction) {
					//UP
					case 0:
						{
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

									std::cout << "Baby born up." << std::endl;
									madeBaby=true;
								}
							}
						triedUp = true;
						break;
						}
					//DOWN
					case 1:
						{
							// checks if there is a lower space
							if (ant[i].getXLoc() < board->getRows()-1) {
								// checks if that space is clear
								if (board->isCharX(ant[i].getXLoc()+1,ant[i].getYLoc(), ' ')) {
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
									ant[antNum-1].setXLoc(ant[i].getXLoc()+1);
									ant[antNum-1].setYLoc(ant[i].getYLoc());

									std::cout << "Baby born down." << std::endl;
									madeBaby = true;
								}

							}
						triedDown = true;
						break;
						}
					//RIGHT
					case 2:
						{
							// checks if there is a right space
							if (ant[i].getYLoc() < board->getColumns()-1) {
								// checks if that space is clear
								if (board->isCharX(ant[i].getXLoc(),ant[i].getYLoc()+1, ' ')) {
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
									ant[antNum-1].setXLoc(ant[i].getXLoc());
									ant[antNum-1].setYLoc(ant[i].getYLoc()+1);
									std::cout << "Baby born right." << std::endl;
									madeBaby = true;
								}
							}
						triedRight = true;
						break;
						}
					//LEFT
					case 3:
						{
							// checks if there is a left space
							if (ant[i].getYLoc() > 0) {
								// checks if that space is clear
								if (board->isCharX(ant[i].getXLoc(),ant[i].getYLoc()-1, ' ')) {
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
									ant[antNum-1].setXLoc(ant[i].getXLoc());
									ant[antNum-1].setYLoc(ant[i].getYLoc()-1);
									std::cout << "Baby born left." << std::endl;
									madeBaby = true;
								}
							}		
						triedLeft = true;
						break;
						}
				}
				
		
				
			} while (!madeBaby && !(triedUp&&triedDown&&triedRight&&triedLeft));
		}
	}
}
