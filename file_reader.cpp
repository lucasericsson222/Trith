#include "file_reader.hpp"
#include <fstream>
#include <iostream>

using namespace std;
room* file_reader::read_room(room* room_read, string file_name)
{
	ifstream room_file;
	room_file.open(file_name);
	int section = 0;
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
			case 3:
				break;
		}
	}

	return room_read;
}