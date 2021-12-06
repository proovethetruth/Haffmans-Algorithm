
#include "Haffman Algorithm.h"
#include <fstream>

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