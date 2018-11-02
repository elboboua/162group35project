/*********************************************************************
** Description: The specification file for the Board class
*********************************************************************/

#ifndef BOARD_H
#define BOARD_H

#include "constants.hpp"
#include <string>

class Board {

  private:
    int rows;
    int columns;
    char **space;

  public:
    Board(int, int);

    // char constants for the string representations on the board
    static constexpr char ANT = 'O';
    static constexpr char BUG = 'X';
    static constexpr char SPACE = ' ';

    int getRows();
    int getColumns();

    void setRows(int);
    void setColumns(int);

    void createBoard();
    void displayBoard();

    void changeSpace(int x, int y, char c);
    bool isCharX(int x, int y, char c);
    EntityTypes checkSpace(int x, int y);
    ~Board();
};

#endif // BOARD_H
