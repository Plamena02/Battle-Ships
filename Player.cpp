#include "Player.h"
#include "Board.h"

Player::Player(){}

void Player::populateBoard(){

    cout << "Available ships:\n";
    for(Ship ship : this -> ships){

        cout << "Ship width is " << ship.getLenght() << '\n';
        bool vertical;
        cout << "Vertical or Horizontal: ";
        cin >> vertical;

        int x, y;
        do{

            cout << "Input x: ";
            cin >> x;
            cout << "Input y: ";
            cin >> y;

        }while(board.checkIfShipFits(x, y, vertical, ship.getLenght()));
        board.placeShip(x, y, vertical, ship);
        
    }

}

void Player::makeMove(){

    int x, y;
    cout << "Input x:"

}