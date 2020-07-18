#include "room.hpp"
#include <iostream>
using namespace std;

void room::print_description(){
    cout << name << endl << endl;
    cout << description << endl;
    for(int i = 0; i < 3; i++) {
        cout << coord[i] << " ";
    }
    cout << endl << endl;
}