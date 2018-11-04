/*********************************************************************
** Description: The implementation file for the Board class
*********************************************************************/

#include "Board.hpp"
#include <ctime>
#include <iostream>
#include <thread>

Board::Board(int rows, int columns) {

    // the base dimensions of the board
    this->rows = rows;
    this->columns = columns;

    // create the dynamic 2d string array
    space = new char *[rows];
    for (int i = 0; i < rows; i++) {
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
            for (int k = 0; k < (columns * 2 + 2); k++) {
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
        if (i == (rows - 1)) {
            for (int l = 0; l < (columns * 2 + 2); l++) {
                std::cout << '-';
            }
            std::cout << std::endl;
        }
    }
}

// This functions prints the board to the user
void Board::prettyDisplayBoard(std::vector<std::string> messages) {

    int msgSize = messages.size();
    int msgCount = 0;

    bool white = false;
    for (int i = 0; i < rows; i++) {

        // goes through the elements and makes the board
        for (int j = 0; j < columns; j++) {

            white = ((i + j) % 2) == 1;
            if (white) {
                std::cout << "\033[22;100m";
            } else {
                std::cout << "\033[51;40m";
            }
            char thisChar = space[i][j];
            if (thisChar == ANT)
                std::cout << "\033[34m";
            if (thisChar == BUG)
                std::cout << "\033[31m";
            std::cout << thisChar;
            std::cout << ' ';
            std::cout << reset;

            if ((j == (columns - 1)) && (i < (rows - 1))) {
                std::cout << reset;
                if (msgCount < msgSize) {
                    std::cout << "\033[0J" << offsetToInfoArea << messages[msgCount];
                    msgCount++;
                }
                std::cout << "\n";
            }
        }
    }
    std::cout << "\033[" << (rows - 1) << "A"
              << "\033[" << (columns * 2) << "D";

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

// changes the space char
void Board::changeSpace(int x, int y, char c) {

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

EntityTypes Board::checkSpace(int x, int y) {

    //if (((x < this->columns) || (x > this->columns)) || ((y < this->rows) || (y > this->rows))) {
    if (((x < 0) || (x >= this->columns)) || ((y < 0) || (y >= this->rows))) {
        return EntityTypes::OUT_OF_BOUNDS;
        std::cout << "hey, one of your x (" << x << "  ), or y( " << y << " )  values is OOB!: [ 0 =< x =< " << (this->columns - 1)
                  << "][0 <= y <= " << (this->rows - 1) << "]!" << std::endl;
    } else {

        switch (space[x][y]) {
            case Board::ANT:
                return EntityTypes::ANT;
                break;
            case Board::BUG:
                return EntityTypes::BUG;
                break;
            case Board::SPACE:
                return EntityTypes::EMPTY;
                break;

            default:
                break;
        }
    }
}

// deallocated 2d character array
Board::~Board() {

    for (int i = 0; i < rows; i++) {
        delete[] space[i];
    }

    delete[] space;

    space = nullptr;
}
