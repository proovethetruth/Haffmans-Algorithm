
#include "Haffman Algorithm.h"
#include <fstream>
#include <iostream>
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

int parse_binary_file(std::string& name, std::string& text) {
    std::string tmp = "";
    std::ifstream myfile(name, std::ios::binary);
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

void save_in_binary(std::string& str, std::ofstream& outfile) {
    //std::basic_string<uint8_t> bytes;
    //for (size_t i = 0; i < str.length(); i += 2) {
    //    uint16_t byte;
    //    std::string nextbyte = str.substr(i, 2);
    //    std::istringstream(nextbyte) >> std::hex >> byte;

    //    bytes.push_back(static_cast<uint8_t>(byte));
    //}
    //std::string result(begin(bytes), end(bytes));
    outfile << str;
    //for (std::size_t i = 0; i < str.length() - 1; ++++i)
    //    outfile << static_cast<char>(str[i] + str[i + 1]);
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