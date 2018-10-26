/********************************************************************* 
** Description: The specification file for the Critter base class
*********************************************************************/ 

#ifndef CRITTER_H
#define CRITTER_H


#include "Board.hpp"

class Critter {

protected:
	int xLoc,yLoc;
	int turnsSinceBreeding;
	

public:
	Critter();	

	int getXLoc();
	int getYLoc();

	void setXLoc(int);
	void setYLoc(int);


	virtual void move(Board * board) = 0;
	virtual bool canBreed() = 0;
};

#endif // CRITTER_H
