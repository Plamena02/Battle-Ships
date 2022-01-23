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
* <functions for ship>
*
*/

#include "Ship.h"

Ship::Ship(int lenght)
{
    this->lenght = lenght;
}

string Ship::getName()
{

    if (this->lenght == 2)
        return "Destroyer";
    if (this->lenght == 3)
        return "Submarine";
    if (this->lenght == 4)
        return "Battleship";
    return "Carrier";
}
