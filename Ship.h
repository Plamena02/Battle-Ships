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
* <file with helper functions>
*
*/

#ifndef SHIP_H
#define SHIP_H

#include <string>
using std::string;

class Ship
{

private:
    int lenght;

public:
    Ship(int lenght);
    Ship() {}
    ~Ship() {}
    int getLenght()
    {
        return this->lenght;
    }
    string getName();
};

#endif
