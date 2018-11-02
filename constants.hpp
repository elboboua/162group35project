/**
 * Program name: survival of the fittest
 * Author: Eben Wight
 * Date: 2018/11/01
 * Description: storage for globally defined constants used in multiple classes
 *
 * that is to say, for globals who's ownership can't be logically pinned down to
 * jus one class
 **/

#ifndef CONSTANTS_H

#define CONSTANTS_H

// some reliable constants to use for describing facts about the board
enum Direction : int { UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3 };

// all the things that a cell next to your cell can be.
enum EntityTypes : int { ANT = 0, BUG = 1, EMPTY = 2, OUT_OF_BOUNDS = 3 };

#endif // CONSTANTS_H
