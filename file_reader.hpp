#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include "room.hpp"
#include "map.hpp"


class file_reader
{
public:
	room& read_room(room& room_read, std::string file_name);
	map& read_map(map& map_read, const char* folder);
};



#endif