#ifndef ROOM_H
#define ROOM_H

#include <string>

using namespace std;
class room
{
public:
	int id = 0;
	string name = "default_name";
	string description = "default_description \n";
	int coord[3] = {0,0,0};
	void print_description();
	
};
#endif