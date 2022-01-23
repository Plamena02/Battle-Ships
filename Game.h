/**
*  
* Solution to course project #8
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Plamena Nikolova
* @idnumber 1MI0600031
* @compiler gcc
*
* <file with helper functions>
*
*/

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <iostream>

using std::cin;
using std::cout;

class Game
{

private:
    const int smallShips = 4,
              mediumShips = 3,
              bigShips = 2,
              largeShips = 1,
              totalShipCount = smallShips +
                               mediumShips +
                               bigShips +
                               largeShips;
    Player players[2] = {Player(smallShips, mediumShips, bigShips, largeShips), Player(smallShips, mediumShips, bigShips, largeShips)};

public:
    Game();
    ~Game() {}

    bool turn(const bool player);
    bool winCondition(const bool checkForFirstPlayer);
    void printBoards(const int playerIndex);
};

#endif
