#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using std::cout;

class Player{

    private:
        Ship ships[6];
    public:
        Player();
        ~Player();

        void populateBoard();
        void makeMove();

}

#endif