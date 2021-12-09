
// �� ���� ��������(���� ��� ���������) ������� � �������� ������ �������� � ��������� �����.
// ��������� ����� ����� ������� � �������� ������ �� ��������� ������.
// ���������� ������������ STL ����������

// ����������� �������� ��������. ������ ������ ������������ ����������.
// ��������� ������ ����� ������������ � ��������������� ��������� �����.

#include "Haffman Algorithm.h"
#include <iostream>
#include <fstream>

int check_task(char* argv[]) {
    if (!argv[1] || !argv[2] || argv[1] == 0 || argv[2] == 0)
        return 0;
    else {
        if (strcmp(argv[2], "-en") == 0 || strcmp(argv[2], "-encode") == 0)
            return 1;
        else {
            if ((strcmp(argv[2], "-de") == 0 || strcmp(argv[2], "-decode") == 0) && argv[3] != NULL)
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
    std::string text;
    if (!parse_file(name, text)) {
        std::cout << "\n Unable to open file ";
        return -2;
    }

    if (task_id == 1)
        build_tree(text, name);
    if (strcmp(argv[2], "-de") == 0) {
        //int index = 0;
        //std::string tree_transcription = "";
        //for(int i = 0; text[i] !)
        //readBinaryTree(text, index);
    }
	return 0;
}