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

#ifndef CONSTANTS_H
#define CONSTANTS_H

class Constants{

    public:
        static const int smallShips = 4,
            mediumShips = 3,
            bigShips = 2,
            largeShips = 1,
            totalShipCount = smallShips +
                            mediumShips +
                            bigShips +
                            largeShips;

};

#endif
