#include "Player.h"

Player::Player(){

    this->ships = new Ship[Constants::totalShipCount];

    for(int i = 0; i < Constants::smallShips; i++)
        this->ships[i] = Ship(2);
    for(int i = Constants::smallShips; i < Constants::smallShips + Constants::mediumShips; i++)
        this->ships[i] = Ship(3);
    for(int i = Constants::smallShips + Constants::mediumShips; i < Constants::smallShips + Constants::mediumShips + Constants::bigShips; i++)
        this->ships[i] = Ship(4);
    for(int i = Constants::smallShips + Constants::mediumShips + Constants::bigShips; i < Constants::smallShips + Constants::mediumShips + Constants::bigShips + Constants::largeShips; i++)
        this->ships[i] = Ship(6);

}

void Player::populateBoard(){

    pair<Point, Point> coordinates[Constants::totalShipCount];
    cout << "Available ships:\n";
    for(int i = 0; i < Constants::totalShipCount; i++){

        cout << "Ship -> " << ships[i].getName() << " with lenght " << ships[i].getLenght() << '\n';
        bool vertical;
        cout << "Vertical or Horizontal: ";
        cin >> vertical;

        int index = 0;

        while(true){

            cout << "Input x: ";
            cin >> coordinates[index].first.x;
            cout << "Input y: ";
            cin >> coordinates[index].first.y;

            if(vertical){
                coordinates[index].second.y = coordinates[index].first.y + ships[i].getLenght();
                coordinates[index].second.x = coordinates[index].first.x;
            }
            else{
                coordinates[index].second.x = coordinates[index].first.x + ships[i].getLenght();
                coordinates[index].second.y = coordinates[index].first.y;
            }

            if(this->playerBoard.checkIfShipFits(coordinates, index + 1))
                break;

            cout << "Move is invalid!\n";

        }

        index++;

    }

    this->playerBoard.placeShips(coordinates);

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
