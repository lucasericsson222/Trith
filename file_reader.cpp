#include "file_reader.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
room* file_reader::read_room(room* room_read, string file_name)
{
	ifstream room_file;
	room_file.open(file_name);
	int section = 0;
	room_read->description = "";
	room_read->name = "";
	while(!room_file.eof()) {
		string current_line;
		getline(room_file, current_line);
		if (current_line == "###") {
			++section;
			continue;
		}
		switch(section) {
			case 0:
				room_read->name += current_line;
				break;
			case 1:
				room_read->description += current_line;
				room_read->description += "\n";
				break;
			case 2:
				auto current_line_stream = stringstream(current_line);
				for (int i = 0; i < 3; ++i)
				{
					current_line_stream >> room_read->coord[i];
				}
				break;
		}
	}

	return room_read;
}