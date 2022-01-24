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
* <functions for game>
*
*/

#include "Game.h"

Game::Game()
{

    bool running = true;
    while (running)
    {

        cout << "First Player turn\n";
        printBoards(0);
        while (turn(0))
        {
            printBoards(0);
            if (winCondition(true))
            {
                cout << "Player 1 win!";
                running = false;
                break;
            }
        }
        if (!running)
            break;
        cout << "Second Player turn\n";
        printBoards(1);
        while (turn(1))
        {
            printBoards(1);
            if (winCondition(false))
            {
                cout << "Player 2 win!";
                running = false;
                break;
            }
        }
    }
}

bool Game::turn(const bool player)
{

    Point point;
    cout << "Coordinats where you think there is a ship.\n";
    cout << "Input x: ";
    cin >> point.x;
    cout << "Input y: ";
    cin >> point.y;

    //validate point
    while (!(this->players[player].getEnemyBoard().moveIsValid(point)))
    {
        cout << "Invalid point. Try again: \n";
        cout << "Input x: ";
        cin >> point.x;
        cout << "Input y: ";
        cin >> point.y;
    }

    const bool hit = this->players[!player].getPlayerBoard().hitOrMiss(point);
    this->players[player].getEnemyBoard().placeOnBoard(point, hit);

    if (hit)
    {
        cout << "You hit a ship.\n";
        if (this->players[!player].getPlayerBoard().shipHasSunk(point))
        {
            this->players[!player].sinkShip();
            cout << "You have sunk a ship!\n";
        }
        return true;
    }
    cout << "You miss.\n";
    return false;
}

bool Game::winCondition(const bool checkForFirstPlayer)
{
    if (checkForFirstPlayer)
        return this->players[1].getSunkShips() == this->totalShipCount;
    return this->players[0].getSunkShips() == this->totalShipCount;
}

void Game::printBoards(const int playerIndex)
{

    cout << "My board:\n";
    this->players[playerIndex].getPlayerBoard().printBoard();
    cout << "\nEnemy board:\n";
    this->players[playerIndex].getEnemyBoard().printBoard();

}
