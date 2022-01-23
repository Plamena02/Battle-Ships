#ifndef SHIP_H
#define SHIP_H

#include <string>
using std::string;

class Ship{

    private:
        int lenght;
    public:
        Ship(int lenght);
        Ship(){}
        ~Ship(){}
        int getLenght(){
            return this -> lenght;
        }
        string getName();
};

#endif
