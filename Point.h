#ifndef POINT_H
#define POINT_H
#include <utility>

using std::pair;

class Point{

    public:
        int x, y;
        Point(){}
        Point(int x, int y){
            this -> x = x;
            this -> y = y;
        }
        ~Point(){}
        static bool isHorizontal(pair<Point,Point> a){
            return a.first.y == a.second.y;
        }
};

#endif
