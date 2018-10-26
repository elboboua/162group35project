/********************************************************************* 
** Description: The implementation file for the Board class
*********************************************************************/ 

#include "Board.hpp"
#include <iostream>

Board::Board() {

	// the base dimensions of the board
	rows = 20;
	columns = 20;

	// create the dynamic 2d string array
	space = new char*[rows];
	for (int i =0; i < rows; i++) {
		space[i] = new char[columns];
	}

	
	// make all spaces blank to start
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			space[i][j] = ' ';
		}
	}

}

int Board::getRows() {
	return rows;
}


int Board::getColumns() {
	return columns;
}

// This functions prints the board to the user
void Board::displayBoard() {
     
   for (int i = 0; i < rows; i++) {
        
        // puts the top border
        if (i == 0) {
            for (int k = 0; k < (columns*2+2); k++) {
                std::cout << '-';
            }
            
            std::cout << std::endl;
        }
        
        // left border
        std::cout << '|';
        
        // goes through the elements and makes the board 
        for (int j = 0; j < columns; j++) {
			std::cout << space[i][j];
			std::cout << ' ';
        }

        // right border
        std::cout << '|' << std::endl;
        
        // puts the bottom border
        if (i == (rows-1)) {
            for (int l = 0; l < (columns*2+2); l++) {
                std::cout << '-';
            } 
            std::cout << std::endl;
        }
    }
}

// changes the space char 
void Board::changeSpace(int x, int y, char c){

	if (x >= 0 && x < rows && y >= 0 && y < columns) {
	space[x][y] = c;
	} else {
		std::cerr << "the x or y coordinates are incorrect" << std::endl;
	}


}


// This checks if the space at x and y is the character input as parameter 3
bool Board::isCharX(int x, int y, char c) {

	if (space[x][y] == c) {
		return true;
	} else {
		return false;
	}

}


// deallocated 2d character array
Board::~Board () {

	for (int i=0; i < rows; i++) {
		delete [] space[i];
	}

	delete [] space;

	space = nullptr;


}
