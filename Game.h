#ifndef GAME_H
#define GAME_H

#include "Constants.h"
#include "Player.h"
#include <iostream>

class Game{

    private:
        Player players[2] = { Player(), Player() };
    public:
        Game();
        ~Game(){}

        void turn(int player);
        bool winCondition(const bool checkForFirstPlayer=true);

};

#endif
