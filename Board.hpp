/********************************************************************* 
** Description: The specification file for the Board class
*********************************************************************/


#ifndef BOARD_H
#define BOARD_H

#include <string>


class Board {

private:
	int rows;
	int columns;
	char ** space;
public:
	Board(int,int);

	int getRows();
	int getColumns();

	void setRows(int);
	void setColumns(int);

	void createBoard();
	void displayBoard();

	void changeSpace(int x, int y, char c);
	bool isCharX(int x, int y, char c);

	~Board();
}; 

#endif // BOARD_H
