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

#ifndef BOARD_H
#define BOARD_H

#include "Point.h"
#include <windows.h>
#include <string>
#include <utility>
#include <iostream>

using std::cout;
using std::pair;
using std::string;

class Board
{

private:
    // Includes the number colomn and letter row
    const int boardDimensions = 11;
    const string shipSymbol = " @", missSymbol = " *", hitSymbol = " X";
    string **board;

public:
    Board();
    ~Board() {}
    string **getBoard()
    {
        return board;
    }
    bool checkIfShipFits(pair<Point, Point> arr[], int index, pair<Point, Point> ship);
    bool isInsideBoard(Point coordinates);
    void placeShips(pair<Point, Point> coordinates[], const int index);
    bool hitOrMiss(Point point);
    bool moveIsValid(Point point);
    void placeOnBoard(Point point, const bool hit);
    bool shipHasSunk(Point point);
    void printBoard();
};

#endif
