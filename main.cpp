
/*!
    \file
    \brief Основной файл, содержащий main()
*/

#include "Haffman Algorithm.h"
#include <iostream>

int check_task(char* argv[]) {
    if (!argv[1] || !argv[2] || argv[1] == 0 || argv[2] == 0)
        return 0;
    else {
        if (strcmp(argv[2], "-en") == 0 || strcmp(argv[2], "-encode") == 0)
            return 1;
        else {
            if (strcmp(argv[2], "-de") == 0 || strcmp(argv[2], "-decode") == 0)
                return -1;
            else
                return 0;
        }
    }
}

int main(int argc, char* argv[]) {
    int task_id;
    if ((task_id = check_task(argv)) == 0) {
        std::cout << "\n Usage: HaffmansAlgorithm <filename> [-en | -encode | -de | -decode]\n";
        return -1;
    }

    std::cout << "\n\t HAFFMAN'S CODE";
    std::string name(argv[1]);

    if (task_id == 1) {
        if (!pack(name))
            return -2;
    }
    if (strcmp(argv[2], "-de") == 0) {
        if (!unpack(name))
            return -2;
    }
	return 0;
}