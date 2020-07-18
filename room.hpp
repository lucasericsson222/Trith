#ifndef ROOM_H
#define ROOM_H

#include <string>

class room
{
public:
	int id = 0;
	std::string name = "default_name";
	std::string description = "default_description \n";
	int coord[3] = {0,0,0};
	void print_description();
	
};
#endif