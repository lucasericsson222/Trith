#include "map.hpp"
#include <iostream>
map::map()
{
    for (int x = 0; x < map::X_SIZE; ++x)
    {
        for (int y = 0; y < map::Y_SIZE; ++y)
        {
            for (int z = 0; z < map::Z_SIZE; ++z)
            {
                room coord_room;
                coord_room.coord[0] = x;
                coord_room.coord[1] = y;
                coord_room.coord[2] = z;
                map_array[x][y][z] = coord_room;
            }
        }
    }
}

void map::display_map(int y)
{
    for (int x = 0; x < map::X_SIZE; ++x)
    {
        for (int z = 0; z < map::Z_SIZE; ++z)
        {
            if (map_array[x][y][z].name == "default_name")
            {
                std::cout << "=";
            } else
            {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
}