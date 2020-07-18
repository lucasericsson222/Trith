#ifndef FILE_READER_H
#define FILE_READER_H
#include <string>
#include "room.hpp"


class file_reader
{
public:
	room* read_room(room* room_read, string file_name);
};



#endif