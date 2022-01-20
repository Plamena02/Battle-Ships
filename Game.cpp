#include "Game.h"

Game::Game(){
    this->player[0] = Player(this->smallShips, this->mediumShips, this->bigShips, this->largeShips);
    this->player[1] = Player(this->smallShips, this->mediumShips, this->bigShips, this->largeShips);
    while(!(winCondition(true) || winCondition(false))){
        turn();
    }
}

void Game::turn(){}

bool Game::winCondition(bool checkForFirstPlayer = true){
    if(checkForFirstPlayer)
        return this->player[1].getSunkShips() == totalNumberOfShips();
    return this->player[0].getSunkShips() == totalNumberOfShips();
}