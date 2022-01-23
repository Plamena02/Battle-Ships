#ifndef POINT_H
#define POINT_H

class Point{

    public:
        int x, y;
        Point(){}
        Point(int x, int y){
            this -> x = x;
            this -> y = y;
        }
        ~Point(){}
        static bool areHorizontal(Point a, Point b){
            return a.y == b.y;
        }



};

#endif
