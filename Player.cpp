#include "Player.h"
#include "Board.h"
#include "Point.h"
#include <utility>

using std::pair;

Player::Player(){

    this->playerBoard = Board();
    this->enemyBoard = Board();

    const int smallShips = 4, mediumShips = 3, bigShips = 2, largeShips = 1;
    for(int i = 0; i < smallShips; i++)
        this->ships[i] = Ship(2);
    for(int i = smallShips; i < smallShips + mediumShips; i++)
        this->ships[i] = Ship(3);
    for(int i = smallShips + mediumShips; i < smallShips + mediumShips + bigShips; i++)
        this->ships[i] = Ship(4);
    for(int i = smallShips + mediumShips + bigShips; i < smallShips + mediumShips + bigShips + largeShips; i++)
        this->ships[i] = Ship(6);
    
}

Player::~Player(){}

void Player::populateBoard(){

    cout << "Available ships:\n";
    for(Ship ship : this->ships){

        cout << "Ship -> " << ship.getName() << " with lenght " << ship.getLenght() << '\n';
        bool vertical;
        cout << "Vertical or Horizontal: ";
        cin >> vertical;

        pair<Point> coordinates[this->numberOfShips];
        int index = 0;

        while(true){

            cout << "Input x: ";
            cin >> coordinates[index].first.x;
            cout << "Input y: ";
            cin >> coordinates[index].first.y;

            if(vertical){
                coordinates[index].second.y = coordinates[index].first.y + ship.getLenght();
                coordinates[index].second.x = coordinates[index].first.x;
            }
            else{
                coordinates[index].second.x = coordinates[index].first.x + ship.getLenght();
                coordinates[index].second.y = coordinates[index].first.y;
            }

            if(this->playerBoard.checkIfShipFits(coordinates, index + 1))
                break;
            
            cout << "Move is invalid!\n";
            
        }

        index++;
        
    }

    this -> playerBoard.placeShips(coordinates);

}

Point Player::makeMove(){

    Point coordinates;

    while(true){

        cout << "Input x: ";
        cin >> coordinates.x;
        cout << "Input y: ";
        cin >> coordinates.y;

        if(this->enemyBoard.moveIsValid(coordinates))
            break;

        cout << "Move is invalid!\n";

    }

    return coordinates;

}