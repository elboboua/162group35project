/*********************************************************************
** Description: The implementation file for the Game class
*********************************************************************/

#include "Game.hpp"
#include <vector>

void Game::addRandomAnts(int antNum) {
    setAntNum(antNum);
    for (int i = 0; i < antNum; i++) {
        ant[i].randomPlacement(board);
    }
}
Game::Game() {

    antNum = 1;
    ant = new Ant[100];
    bugs = new Doodlebug[100];

    board = new Board(20, 20);
}

int Game::getBugNum() {
    return bugNum;
}

void Game::setBugNum(int bugNum) {
    this->bugNum = bugNum;
}

int Game::getAntNum() {
    return antNum;
}

void Game::setAntNum(int antNum) {
    this->antNum = antNum;
}

void Game::loop() {

    int rounds = 100;
    // std::cout << "Initial placement:" << std::endl;
    board->prettyDisplayBoard(messages);
    // std::cout << "Movements:" << std::endl;
    messages.clear();

    for (int i = 0; i < rounds; i++) {
        messages.push_back("Round " + std::to_string(i + 1) + ".");
        breedAnts();
        for (int j = 0; j < antNum; j++) {
            ant[j].move(board);
        }
        board->prettyDisplayBoard(messages);
        messages.clear();
    }
}

// This functions checks if an ant can breed and if there is available space. If there is if makes an ant.
void Game::breedAnts() {
    // loops through all the ants

    // creates a temp number to iterate through all old ants
    int tempAntNum = antNum;
    int babycount = 0;

    for (int i = 0; i < tempAntNum; i++) {
        // Checks if ant can breed
        if (ant[i].canBreed()) {

            bool madeBaby = false;
            bool triedUp = false;
            bool triedDown = false;
            bool triedRight = false;
            bool triedLeft = false;
            do {

                int direction = rand() % 4;

                switch (direction) {
                    // UP
                    case 0: {
                        // checks if there is an upper space
                        if (ant[i].getXLoc() > 0) {
                            // checks if that space is clear
                            if (board->isCharX(ant[i].getXLoc() - 1, ant[i].getYLoc(), ' ')) {
                                // resize dynamic array
                                antNum++;
                                Ant *temp = new Ant[antNum];
                                for (int i = 0; i < antNum - 1; i++) {
                                    temp[i] = ant[i];
                                }

                                // clear old array, give ant the bigger array, delete the temp array
                                delete[] ant;
                                ant = temp;

                                // put the new ant in its right place
                                ant[antNum - 1].setXLoc(ant[i].getXLoc() - 1);
                                ant[antNum - 1].setYLoc(ant[i].getYLoc());

                                // std::cout << "Baby born up." << std::endl;
                                madeBaby = true;
                            }
                        }
                        triedUp = true;
                        break;
                    }
                    // DOWN
                    case 1: {
                        // checks if there is a lower space
                        if (ant[i].getXLoc() < board->getRows() - 1) {
                            // checks if that space is clear
                            if (board->isCharX(ant[i].getXLoc() + 1, ant[i].getYLoc(), ' ')) {
                                // resize dynamic array
                                antNum++;
                                Ant *temp = new Ant[antNum];
                                for (int i = 0; i < antNum - 1; i++) {
                                    temp[i] = ant[i];
                                }

                                // clear old array, give ant the bigger array, delete the temp array
                                delete[] ant;
                                ant = temp;

                                // put the new ant in its right place
                                ant[antNum - 1].setXLoc(ant[i].getXLoc() + 1);
                                ant[antNum - 1].setYLoc(ant[i].getYLoc());

                                // std::cout << "Baby born down." << std::endl;
                                madeBaby = true;
                            }
                        }
                        triedDown = true;
                        break;
                    }
                    // RIGHT
                    case 2: {
                        // checks if there is a right space
                        if (ant[i].getYLoc() < board->getColumns() - 1) {
                            // checks if that space is clear
                            if (board->isCharX(ant[i].getXLoc(), ant[i].getYLoc() + 1, ' ')) {
                                // resize dynamic array
                                antNum++;
                                Ant *temp = new Ant[antNum];
                                for (int i = 0; i < antNum - 1; i++) {
                                    temp[i] = ant[i];
                                }

                                // clear old array, give ant the bigger array, delete the temp array
                                delete[] ant;
                                ant = temp;

                                // put the new ant in its right place
                                ant[antNum - 1].setXLoc(ant[i].getXLoc());
                                ant[antNum - 1].setYLoc(ant[i].getYLoc() + 1);
                                // std::cout << "Baby born right." << std::endl;
                                madeBaby = true;
                            }
                        }
                        triedRight = true;
                        break;
                    }
                    // LEFT
                    case 3: {
                        // checks if there is a left space
                        if (ant[i].getYLoc() > 0) {
                            // checks if that space is clear
                            if (board->isCharX(ant[i].getXLoc(), ant[i].getYLoc() - 1, ' ')) {
                                // resize dynamic array
                                antNum++;
                                Ant *temp = new Ant[antNum];
                                for (int i = 0; i < antNum - 1; i++) {
                                    temp[i] = ant[i];
                                }

                                // clear old array, give ant the bigger array, delete the temp array
                                delete[] ant;
                                ant = temp;

                                // put the new ant in its right place
                                ant[antNum - 1].setXLoc(ant[i].getXLoc());
                                ant[antNum - 1].setYLoc(ant[i].getYLoc() - 1);
                                // std::cout << "Baby born left." << std::endl;
                                madeBaby = true;
                            }
                        }
                        triedLeft = true;
                        break;
                    }
                }

                if (madeBaby) {
                    babycount++;
                }

            } while (!madeBaby && !(triedUp && triedDown && triedRight && triedLeft));
        }
    }
    if (babycount > 0) {
        messages.push_back("There were " + std::to_string(babycount) + " baby ants produced this round");
    }
}
