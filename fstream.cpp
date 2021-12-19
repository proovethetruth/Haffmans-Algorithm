
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
        int index = 0;
        for (; text[index] != '#'; index++);
        for (index++; text[index] != '#'; index++);
        for(index++; index < text.size(); index++)
            tmp += text[index];
        text = tmp;
    }
    else
        return 0;
    return 1;
}

int parse_binary_text(std::string& name, std::string& text) {
    std::ifstream myfile(name, std::ios::binary);
    std::stringstream input;
    if (myfile.is_open()) {
        char c;
        while (myfile.get(c)) {
            if (c == '#')
                break;
            for (int i = 7; i >= 0; i--)
                input << ((c >> i) & 1);
        }
        text = input.str();

        myfile.get(c);
        for (int i = 0; i < c - '0'; i++)
            text.pop_back();
        return 1;
    }
    else
        return 0;
}

std::string gen_filename(std::string original) {
    for (int i = 0; i < 4; i++)
        original.pop_back();

    return original + " - encoded.txt";
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