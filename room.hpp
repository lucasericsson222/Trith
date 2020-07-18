#ifndef ROOM_H
#define ROOM_H

#include <string>

using namespace std;
class room
{
public:
	int id = 0;
	string name = "";
	string description = "";

	void print_description();
	
};
#endif