#ifndef PLAYER_H
#define PLAYER_H

#include "Constants.h"
#include "Point.h"
#include "Ship.h"
#include "Board.h"
#include <iostream>
#include <utility>

using std::cin;
using std::cout;
using std::pair;

class Player{

    private:
        int sunkCount = 0;
        Ship *ships;
        Board playerBoard = Board(), enemyBoard = Board();
    public:
        Player();
        ~Player(){}

        void populateBoard();
        Point makeMove();
        void sinkShip(){
            this->sunkCount++;
        }
        int getSunkShips(){
            return this->sunkCount;
        }

};

#endif
