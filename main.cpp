#include <iostream>
#include "room.hpp"
#include "file_reader.hpp"
#include "map.hpp"
using namespace std;

int main() 
{
	file_reader reader;
	room new_room;
	reader.read_room(&new_room, "rooms/my_first_room.txt");
	new_room.print_description();
	map world1;
	(world1.map_array[3][3][7]).print_description();
}