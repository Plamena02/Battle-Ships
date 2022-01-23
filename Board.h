#ifndef BOARD_H
#define BOARD_H

#include "Constants.h"
#include "Point.h"
#include <windows.h>
#include <string>
#include <utility>

using std::string;
using std::pair;

class Board{

    private:
        // Includes the number colomn and letter row
        const int boardDimensions = 11;
        const string shipSymbol = " @", missSymbol = " *", hitSymbol = " X";
        string **board;
    public:
        Board();
        ~Board(){}
        bool checkIfShipFits(pair<Point,Point> arr[], int index);
        bool moveIsValid(Point coordinates);
        void placeShips(pair<Point, Point> coordinates[]);
        bool hitOrMiss(Point point);

};

#endif
