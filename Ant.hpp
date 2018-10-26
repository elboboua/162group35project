/********************************************************************* 
** Description: This specification for the Ant derived class
*********************************************************************/ 

#ifndef ANT_H
#define ANT_H

#include "Critter.hpp"

class Ant: public Critter {


public:
	Ant();
	virtual void move(Board * board);
	virtual bool canBreed();

	void randomPlacement(Board * board);
};

#endif // ANT_H
