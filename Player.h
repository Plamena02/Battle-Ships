#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using std::cout;

class Player{

    private:
        int const sunkCount = 0;
        Ship ships[numberOfShips];
        Board playerBoard, enemyBoard;
    public:
        Player();
        ~Player();

        void populateBoard();
        void makeMove();
        int getNumberOfShips(){
            return this->numberOfShips;
        }
        void sinkShip(){
            this->sunkCount++;
        }
        int getSunkShips(){
            return this->sunkCount;
        }

}

#endif