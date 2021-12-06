
// �� ���� ��������(���� ��� ���������) ������� � �������� ������ �������� � ��������� �����.
// ��������� ����� ����� ������� � �������� ������ �� ��������� ������.
// ���������� ������������ STL ����������

// ����������� �������� ��������. ������ ������ ������������ ����������.
// ��������� ������ ����� ������������ � ��������������� ��������� �����.

#include "Haffman Algorithm.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (!argv[1] || !argv[2] || argv[1] == 0 || argv[2] == 0) {
        std::cout << "\n Usage: ";
        return -1;
    }
    std::cout << "\n\t HAFFMAN'S CODE";

    std::string name(argv[1]);
    std::string text;
    if (!parse_file(name, text)) {
        std::cout << "\n Unable to open file ";
        return -2;
    }

    if (strcmp(argv[2], "-en") == 0)
        build_tree(text, name);
    /*if (strcmp(argv[2], "-de") == 0)
        decode_tree(text, name);*/
	return 0;
}