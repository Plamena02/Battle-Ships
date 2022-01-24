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
* <functions for player>
*
*/

#include "Player.h"

Player::Player(const int smallShips, const int mediumShips, const int bigShips, const int largeShips){

    const int totalShipCount = smallShips + mediumShips + bigShips + largeShips;
    this->ships = new Ship[totalShipCount];

    for(int i = 0; i < smallShips; i++)
        this->ships[i] = Ship(2);
    for(int i =  smallShips; i <  smallShips +  mediumShips; i++)
        this->ships[i] = Ship(3);
    for(int i =  smallShips +  mediumShips; i <  smallShips +  mediumShips +  bigShips; i++)
        this->ships[i] = Ship(4);
    for(int i =  smallShips +  mediumShips +  bigShips; i <  smallShips +  mediumShips +  bigShips +  largeShips; i++)
        this->ships[i] = Ship(6);

    this->populateBoard();

}

void Player::populateBoard(){
    const int totalShipCount = 10;
    pair<Point, Point> coordinates[totalShipCount];
    ifstream myInput("input.txt");
    int index = 0, addedShips = 0;
    bool temp = true;
    
    cout << "Do you want to use board template for ships (0/1) ?  ";
    cin >> temp;

    for(int i = 0; i < totalShipCount; i++){

        this->playerBoard.printBoard();

        if(i > 0){

            bool choice;
            if(temp)
                myInput >> choice;
            else{

                cout << "0.Add new\n1.Replace\nChoice: ";
                cin >> choice;

            }

            if(choice){

                if(temp)
                    myInput >> choice;
                else{
                    
                    cout << "Select ship to edit(1," << i << "): ";
                    cin >> index;

                }
                index--;
                i--;

            }

        }

        cout << "Ship -> " << ships[i].getName() << " with lenght " << ships[i].getLenght() << '\n';
        bool vertical;
        if(temp)
            myInput >> vertical;
        else{
            
            cout << "Vertical or Horizontal(1/0): ";
            cin >> vertical;

        }

        pair<Point, Point> newCoords;

        while(true){

            if(temp)
                myInput >> newCoords.first.x;
            else{
                
                cout << "Input x: ";
                cin >> newCoords.first.x;

            }
            if(temp)
                myInput >> newCoords.first.y;
            else{

                cout << "Input y: ";
                cin >> newCoords.first.y;
            
            }

            if(vertical){
                newCoords.second.y = newCoords.first.y + ships[i].getLenght() - 1;
                newCoords.second.x = newCoords.first.x;
            }
            else{
                newCoords.second.x = newCoords.first.x + ships[i].getLenght() - 1;
                newCoords.second.y = newCoords.first.y;
            }

            if(this->playerBoard.checkIfShipFits(coordinates, i, newCoords))
                break;

            cout << "Move is invalid!\n";

        }

        coordinates[index] = newCoords;
        index = i + 1;

        this->playerBoard.placeShips(coordinates, i + 1);
    }

    myInput.close();

}

Point Player::makeMove(){

    Point coordinates;

    while(true){

        cout << "Input x: ";
        cin >> coordinates.x;
        cout << "Input y: ";
        cin >> coordinates.y;

        if(this->enemyBoard.isInsideBoard(coordinates))
            break;

        cout << "Move is invalid!\n";

    }

    return coordinates;

}
