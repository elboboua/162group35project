/********************************************************************* 
** Description: The specification for the Game class
*********************************************************************/ 

#ifndef GAME_H
#define GAME_H

#include "Ant.hpp"
#include "Board.hpp"

#include <iostream>

class Game {

private:
	Ant * ant;
	int antNum;
	Board * board;
	
public: 
	Game();
	void loop();
	void breedAnt();

	// breedDoodlebug
	// killDoodlebug
	// killAnt
};

#endif // GAME_H
