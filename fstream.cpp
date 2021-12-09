
#include "Haffman Algorithm.h"
#include <fstream>
#include <iostream>

int parse_file(std::string& name, std::string& text) {
    std::ifstream myfile(name);
    std::string tmp = "";

    if (myfile.is_open()) {
        while (getline(myfile, tmp))
            text += tmp;
        myfile.close();
    }
    else
        return 0;

    return 1;
}

std::string gen_filename(std::string original) {
    for (int i = 0; i < 4; i++)
        original.pop_back();

    return original + " - encoded.txt";
}