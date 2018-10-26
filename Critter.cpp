/********************************************************************* 
** Description: The implementation file for the Critter base class
*********************************************************************/ 

#include "Critter.hpp"

Critter::Critter() {

	this->xLoc = 0;
	this->yLoc = 0;
	this->turnsSinceBreeding = 0;

}

int Critter::getXLoc() {

	return xLoc;

}


int Critter::getYLoc() {

	return yLoc;

}

void Critter::setXLoc(int xLoc) {

	this->xLoc = xLoc;

}


void Critter::setYLoc(int yLoc) {

	this->yLoc = yLoc;

}
