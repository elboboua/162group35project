/********************************************************************* 
** Description: The specification file for the Critter base class
*********************************************************************/ 

class Critter {

protected:
	int xLoc,yLoc;
	int turnsSinceBreeding;
	

public:
	int getXLoc();
	int getYLoc();

	void setXLoc(int);
	void setYLoc(int);


	virtual void move() = 0;
};

