/**
 * Author: Eben Wight
 * Date: 2018/11/01
 * Description: Dooodle bug is the predator, he moves and, if possible,
 * his first move priority is to eat an ant in an adjacent cell
 *
 * inherits from Critter just like Ant does
 **/

#ifndef DOODLEBUG
#define DOODLEBUG

#include "Critter.hpp"

class Doodlebug : public Critter {

  public:
    Doodlebug();
    virtual void move(Board *board);
    virtual bool canBreed();
    void spawn(Board *board);
    void eat(Board *board);
    void starve(Board *board);

    void randomPlacement(Board *board);
};

#endif // DOODLEBUG