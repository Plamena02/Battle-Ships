#include "Ship.h"

Ship::Ship(int lenght){
    this->lenght = lenght;
}

string Ship::getName(){

    if(this->lenght == 2)
        return "Destroyer";
    if(this->lenght == 3)
        return "Submarine";
    if(this->lenght == 4)
        return "Battleship";
    return "Carrier";

}
