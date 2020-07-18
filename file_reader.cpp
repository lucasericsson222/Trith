#include "file_reader.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <experimental/filesystem>

room& file_reader::read_room(room& room_read, std::string file_name)
{
	std::ifstream room_file;
	room_file.open(file_name);
	int section = 0;
	room_read.description = "";
	room_read.name = "";
	while(!room_file.eof()) {
		std::string current_line;
		getline(room_file, current_line);
		if (current_line == "###") {
			++section;
			continue;
		}
		switch(section) {
			case 0:
				room_read.name += current_line;
				break;
			case 1:
				room_read.description += current_line;
				room_read.description += "\n";
				break;
			case 2:
				auto current_line_stream = std::stringstream(current_line);
				for (int i = 0; i < 3; ++i)
				{
					current_line_stream >> room_read.coord[i];
				}
				break;
		}
	}

	return room_read;
}

map& file_reader::read_map(map& map_read, std::string folder)
{
	// ignore following error, program compiles with it, becuase everything is correct. Some problem with intellisense on vscode
	for (auto & entry : std::filesystem::directory_iterator(folder)) 
	{
		std::cout << entry.path() << std::endl; 
		room new_room;
		new_room = read_room(new_room, (entry.path()));
		map_read.map_array[new_room.coord[0]][new_room.coord[1]][new_room.coord[2]] = new_room;
	}
	return map_read;
}