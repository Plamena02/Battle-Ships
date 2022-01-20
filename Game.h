#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game{

    private:
        const int smallShips = 4, mediumShips = 3, bigShips = 2, largeShips = 1;
        Player players[2];
    public:
        Game();
        ~Game();

        void turn();
        bool winCondition();
        int totalNumberOfShips(){
            return this->smallShips + this->mediumShips + this->bigShips + this->largeShips;
        }

}

#endif