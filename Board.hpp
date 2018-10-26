/********************************************************************* 
** Description: The specification file for the Board class
*********************************************************************/

#include <string>


class Board {

private:
	int rows;
	int columns;
	char ** space;
public:
	Board();

	int getWidth();
	int getHeight();

	void setWidth(int);
	void setHeight(int);

	void createBoard();
	void displayBoard();

	void changeSpace(int x, int y, char c);
	bool isCharX(int x, int y, char c);

	~Board();
}; 
