
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
//
//Node readBinaryTree(std::string& str) {
//    if (str == 1) {
//        return new Node(reader.ReadByte(), null, null);
//    }
//    else
//    {
//        Node leftChild = ReadNode(reader);
//        Node rightChild = ReadNode(reader);
//        return new Node(0, leftChild, rightChild);
//    }
//}