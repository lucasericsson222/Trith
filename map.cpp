#include "map.hpp"

map::map()
{
    for(int x = 0; x < map::X_SIZE; ++x ) 
    {
        for (int y = 0; y < map::Y_SIZE; ++y) 
        {
            for (int z = 0; z < map::Z_SIZE; ++z) 
            {
                map_array[x][y][z] = room();
            }
        }
    }
}