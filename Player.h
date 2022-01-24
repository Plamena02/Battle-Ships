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

#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"
#include "Ship.h"
#include "Board.h"
#include <iostream>
#include <utility>
#include <fstream>

using std::cin;
using std::cout;
using std::ifstream;
using std::pair;

class Player
{

private:
    int sunkCount = 0;
    Ship *ships;
    Board playerBoard = Board(), enemyBoard = Board();

public:
    Player(const int smallShips, const int mediumShips, const int bigShips, const int largeShips);
    ~Player() {}

    void populateBoard();
    Point makeMove();
    void sinkShip()
    {
        this->sunkCount++;
    }
    Board getPlayerBoard()
    {
        return this->playerBoard;
    }
    Board getEnemyBoard()
    {
        return this->enemyBoard;
    }
    int getSunkShips()
    {
        return this->sunkCount;
    }
};

#endif
