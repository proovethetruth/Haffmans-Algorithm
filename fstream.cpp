
#include "Haffman Algorithm.h"
#include <fstream>
#include <iostream>

int parse_file(std::string& name, std::string& text, int task) {
    std::string tmp = "";

    if (task == 1) {
        std::ifstream myfile(name);
        if (myfile.is_open()) {
            while (getline(myfile, tmp))
                text += tmp;
            myfile.close();
        }
        else
            return 0;
    }
    else {
        std::ifstream myfile(name, std::ios::binary);
        if (myfile.is_open()) {
            std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(myfile), {});

            std::string str = "";
            for (unsigned char j : buffer)
                str += j;
            std::cout << "\n STR: "<< str << "\n";

            std::string tmp = "";
            for (std::size_t i = 0; i < str.length() - 1; ++++i)
                tmp += static_cast<char>(str[i] / 16 - str[i + 1]);
                

            std::cout << "\n tmp: " << tmp << "\n";
        }
        else
            return 0;
    }
    return 1;
}

std::string gen_filename(std::string original) {
    for (int i = 0; i < 4; i++)
        original.pop_back();

    return original + " - encoded.txt";
}

void save_in_binary(std::string& str, std::ofstream& outfile) {

    for (std::size_t i = 0; i < str.length() - 1; ++++i)
        outfile << static_cast<char>(str[i] * 16 + str[i + 1]);
}

void writeBinaryTree(Node* node, std::string& result) {
    if (!node->left && !node->right) {
        result += "1";
        result += node->ch;
    }
    else {
        result += "0";
        writeBinaryTree(node->left, result);
        writeBinaryTree(node->right, result);
    }
}

Node readBinaryTree(std::string& str, int& index) {
    if (str[index] == 1) {
        return Node(str[++index], nullptr, nullptr);
    }
    else {
        Node leftChild = readBinaryTree(str, ++index);
        Node rightChild = readBinaryTree(str, ++index);
        return Node('0', &leftChild, &rightChild);
    }
}