/*********************************************************************
** Author: Group 35
** Date: 11-4-2018
** Description: The main file for the 162 Group Project 
*********************************************************************/
#include "Ant.hpp"
#include "Board.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main () {

	srand(time(NULL));

	Board * board = new Board;
	Ant ant;
	
	for (int i = 0; i < 5; i++) {
		
		ant.move(board);
		board->displayBoard();
	}

	return 0;
}
