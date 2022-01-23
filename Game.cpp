#include "Game.h"

Game::Game(){

    while(true){

        turn(0);
        if(winCondition(true))
       {
           /// Player 1 wins
           break;
       }
        turn(1);
        if(winCondition(false)){
            /// Player 2 wins
            break;
        }
    }

}

void Game::turn(int player)
{
    Point point;
    cout << "Coordinats where you think there is a ship.\n";
    cout << "Input x: "
    cin >> point.x;
    cout << "Input y: "
    cin >> point.y;

    //validate point

    this->players[player].playerBoard.placeOnBoard(point);

    if(this->players[player].playerBoard.hitOrMiss)
    {
        this->players[player].sinkShip();
        cout << "You hit a ship."
        return;
    }
    cout << "You miss."
    return;
}

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
