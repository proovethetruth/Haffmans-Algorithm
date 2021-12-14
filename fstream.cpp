
#include "Haffman Algorithm.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>


int parse_file(std::string& name, std::string& text) {
    std::string tmp = "";
    std::ifstream myfile(name);
    if (myfile.is_open()) {
        while (getline(myfile, tmp))
            text += tmp;
        myfile.close();
    }
    else
        return 0;
    return 1;
}

int parse_tree(std::string& name, std::string& text) {
    std::string tmp = "";
    std::ifstream myfile(name, std::ios::binary);
    if (myfile.is_open()) {
        while (getline(myfile, tmp))
            text += tmp;
        myfile.close();
        tmp = "";
        for (int i = 0; text[i] != '#'; i++)
            tmp += text[i];
        text = tmp;
    }
    else
        return 0;
    return 1;
}

int parse_binary_text(std::string& name, std::string& text) {
    std::ifstream myfile(name, std::ios::binary);

    unsigned int tmp = 0;
    std::stringstream input;
    if (myfile.is_open()) {
        while (tmp != '#')
            tmp = myfile.get();
        while (input) {
            tmp = myfile.get();
            if (tmp == UINT_MAX)
                break;
            input << std::hex << tmp;
        }
        text = input.str();
    }
    else
        return 0;
}

std::string gen_filename(std::string original) {
    for (int i = 0; i < 4; i++)
        original.pop_back();

    return original + " - encoded.txt";
}

void save_in_binary(std::string& str, std::ofstream& outfile) {
    char buf[3];
    buf[2] = 0;

    std::stringstream input(str);
    input.flags(std::ios_base::hex);
    while (input) {
        input >> buf[0] >> buf[1];
        long val = strtol(buf, nullptr, 16);
        outfile << static_cast<unsigned char>(val & 0xff);
    }
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

Node* readBinaryTree(std::string& str, int& index) {
    if (str[index] == '1') {
        return addNode(str[++index], 0, nullptr, nullptr);
    }
    else {
        Node* leftChild = readBinaryTree(str, ++index);
        Node* rightChild = readBinaryTree(str, ++index);
        return addNode('0', 0, leftChild, rightChild);
    }
}
