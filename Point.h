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

#ifndef POINT_H
#define POINT_H
#include <utility>

using std::pair;

class Point
{

public:
    int x, y;
    Point() {}
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    ~Point() {}
    static bool isHorizontal(pair<Point, Point> a)
    {
        return a.first.y == a.second.y;
    }
};

#endif
