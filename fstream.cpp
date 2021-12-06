
#include "Haffman Algorithm.h"
#include <iostream>
#include <fstream>

int parse_file(std::string& name, std::string& text) {
    std::ifstream myfile(name);

    if (myfile.is_open()) {
        while (getline(myfile, text));
        myfile.close();
    }
    else
        return 0;

    return 1;
}

