
// Во всех заданиях(если нет уточнений) входные и выходные данные хранятся в текстовом файле.
// Программы берут имена входных и выходных файлов из командной строки.
// Необходимо использовать STL контейнеры

// Реализовать алгоритм Хаффмана. Дерево должно передаваться эффективно.
// Программа должна уметь архивировать и разархивировать одиночные файлы.

#include <iostream>
#include <string>
#include <fstream>
#include "Haffman Algorithm.h"

int main(int argc, char* argv[]) {
    if (!argv[1] || !argv[2] || argv[1] == 0 || argv[2] == 0) {
        std::cout << "\n Usage: ";
        return -1;
    }

    std::string name(argv[1]);
    std::ifstream myfile(name);
    std::string text;

    if (myfile.is_open()) {
        std::cout << "\n Input text: ";
        while (getline(myfile, text))
            std::cout << text << '\n';
        myfile.close();
    }
    else
        std::cout << "\n Unable to open file ";

    if (strcmp(argv[2], "-en") == 0)
        encode(text);
    if (strcmp(argv[2], "-de") == 0)
        encode(text);
	return 0;
}