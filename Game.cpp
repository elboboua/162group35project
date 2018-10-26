/********************************************************************* 
** Description: The implementation file for the Game class
*********************************************************************/ 

#include "Game.hpp"

Game::Game() {

	antNum=100;
	ant = new Ant[antNum];

	board = new Board;
	
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
		
		for (int j = 0; j < antNum; j++) {
			ant[j].move(board);
		}		
		board->displayBoard();
	}	
}

