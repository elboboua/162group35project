/*********************************************************************
** Description: The specification file for the Board class
*********************************************************************/

#ifndef BOARD_H
#define BOARD_H

#include "constants.hpp"
#include <string>
#include <vector>

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
    const std::string inverted = "\033[7m";
    const std::string reset = "\033[0m";
    const std::string moveThismany = "\033[";
    const std::string rowsUp = "A";
    const std::string colsLeft = "D";
    const std::string rowsDown = "B";
    const std::string colsRight = "C";
    const std::string offsetToInfoArea = "          "; // that's 10 spaces, or 5 "columns"
    const int rowsOfInfo = 5;
    const std::string bugMove = "bug moves to ";
    const std::string antMove = "bug moves to ";

    int getRows();
    int getColumns();

    void setRows(int);
    void setColumns(int);

    void createBoard();
    void displayBoard();
    void prettyDisplayBoard(std::vector<std::string> messages);

    void changeSpace(int x, int y, char c);
    bool isCharX(int x, int y, char c);
    EntityTypes checkSpace(int x, int y);
    ~Board();
};

#endif // BOARD_H
