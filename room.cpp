#include "room.hpp"
#include <iostream>

void room::print_description(){
    std::cout << name << std::endl << std::endl;
    std::cout << description << std::endl;
    for(int i = 0; i < 3; i++) {
        std::cout << coord[i] << " ";
    }
    std::cout << std::endl << std::endl;
}