#include "Game.h"

Game::Game(){

    while(!(winCondition(true) || winCondition(false))){
        turn();
    }

}

void Game::turn(){}

bool Game::winCondition(const bool checkForFirstPlayer){
    if(checkForFirstPlayer)
        return this->players[1].getSunkShips() == Constants::totalShipCount;
    return this->players[0].getSunkShips() == Constants::totalShipCount;
}


void print(string board[11][11], HANDLE h)
{
    SetConsoleTextAttribute(h,63);

    for(int i = 0; i<11; i++)
    {
        for(int j = 0; j<11; j++)
        {
            if(board[i][j] == " *")// miss
            {
                SetConsoleTextAttribute(h,48); // blue and black
                cout << board[i][j];
                SetConsoleTextAttribute(h,63); // blue and white
                continue;
            }

            if(board[i][j] == " X") //hit
            {
                SetConsoleTextAttribute(h,60); // blue and red
                cout << board[i][j];
                SetConsoleTextAttribute(h,63); // blue and white
                continue;
            }

            if(board[i][j] == " @") //ship
            {
                SetConsoleTextAttribute(h,56); // blue and grey
                cout << board[i][j];
                SetConsoleTextAttribute(h,63); // blue and white
                continue;
            }

            cout << board[i][j];

        }
        cout << '\n';
    }

    SetConsoleTextAttribute(h,15);
}
