/*********************************************************************
** Author: Group 35
** Date: 11-4-2018
** Description: The main file for the 162 Group Project 
*********************************************************************/

#include "Board.hpp"
#include <iostream>

int main () {

	Board board;
	board.displayBoard();

	board.changeSpace(0,0,'X');

	if (board.isCharX(0,0,' ')) {
		std::cout << "It is blank" << std::endl;
	} else {
		std::cout << "ERROR" << std::endl;
	}

	board.displayBoard();
	return 0;
}
