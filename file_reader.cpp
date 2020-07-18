#include "file_reader.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <dirent.h>
#include <cstring>
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

room& file_reader::read_room(room& room_read, std::string file_name)
{
	std::ifstream room_file;
	room_file.open(file_name);
	std::cout << file_name << " room_read()" << std::endl ;
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
	std::string directory = get_current_dir() + "/" + folder;
	DIR *dir;
	struct dirent *ent;
	std::cout << folder << std::endl;
	if ((dir = opendir(directory.c_str())) != NULL) {
  		/* print all the files and directories within directory */
  		while ((ent = readdir (dir)) != NULL) {
			if(ent->d_name[0] == '.') {
			
			}else {
				std::cout << folder << "/" << ent->d_name << std::endl;
				room new_room;
				new_room = read_room(new_room, folder + "/" + std::string(ent->d_name));
				map_read.map_array[new_room.coord[0]][new_room.coord[1]][new_room.coord[2]] = new_room;
			}
  		}
  	closedir (dir);
	} else {
  		/* could not open directory */
  		std::cout << "ERROR" << std::endl;

	}


	return map_read;
}

std::string get_current_dir() {
   char buff[FILENAME_MAX]; //create string buffer to hold path
   GetCurrentDir( buff, FILENAME_MAX );
   std::string current_working_dir(buff);
   return current_working_dir;
}
