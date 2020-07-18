#ifndef MAP_H
#define MAP_H

#include "room.hpp"
#include <vector>


class map
{
public:
    static const int X_SIZE = 30;
    static const int Y_SIZE = 10;
    static const int Z_SIZE = 30;
    room map_array[X_SIZE][Y_SIZE][Z_SIZE];

    map();
    void display_map(int y);
};

#endif