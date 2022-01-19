#ifndef SHIP_H
#define SHIP_H

class Ship{

    private:
        int lenght;
    public:
        Ship(int lenght);
        ~Ship();
        int getLenght(){
            return this -> lenght;
        }

}

#endif