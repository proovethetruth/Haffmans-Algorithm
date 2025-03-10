
/*!
    \file
    \brief ����, ���������� �������� ������� ��� ������ � �������
*/

#include "Haffman Algorithm.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

std::string gen_en_filename(std::string original) {
    original.insert(original.size() - 4, " - encoded");
    return original;
}

//input6 - encoded.txt
std::string gen_de_filename(std::string original) {
    std::string extension;
    for (int i = original.size() - 4; i < original.size(); i++)
        extension += original[i];

    for (int i = 0; i < 14; i++)
        original.pop_back();

    return original + " - decoded" + extension;
}

int check_extension(std::string& name) {
    std::string extension;
    for (int i = name.size() - 4; i < name.size(); i++)
        extension += name[i];
    return extension == ".txt" ? 1 : 0;
}

void insert_zeros_counter(std::ofstream& outfile, int bits) {
    bits = 8 - (bits % 8);
    if (bits == 8)
        bits = 0;
    std::cout << "\n '0'-bits added: " << bits;
    outfile << bits;
}

void writeBinaryString(std::ofstream& outfile, std::string& str) {
    std::vector<unsigned char> output;
    unsigned char bit_buffer = 0;
    int current_bit = 0;
    for (int i = 0; i < str.size(); i++) {
        bit_buffer <<= 1;
        if ((int)(str[i] - '0'))
            bit_buffer |= 0x1;

        current_bit++;
        if (current_bit == 8) {
            outfile.put(bit_buffer);
            current_bit = 0;
            bit_buffer = 0;
        }
    }
    if (current_bit != 0) {
        while (current_bit < 8) {
            bit_buffer <<= 1;
            current_bit++;
        }
        outfile.put(bit_buffer);
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


int parse_file(std::string& name, std::string& text) {
    std::string tmp = "";
    if(check_extension(name)) {
        std::ifstream myfile(name);
        if (myfile.is_open()) {
            while (getline(myfile, tmp))
                text += tmp + '\n';
            text.pop_back();
            myfile.close();
        }
        else
            return 0;
    }
    else {
        std::ifstream myfile(name, std::ios::binary);
        if (myfile.is_open()) {
            while (getline(myfile, tmp))
                text += tmp + '\n';
            text.pop_back();
            myfile.close();
        }
        else
            return 0;
    }
    return 1;
}

int parse_tree(std::ifstream& infile, std::string& text) {
	std::string tmp;
	while (getline(infile, tmp))
		text += tmp + '\n';
	tmp.clear();

    for (int i = 0; text[i] != '#'; i++)
        tmp += text[i];
    int tree_size = stoi(tmp);
    int index = tmp.size() + 1;
    tmp.clear();

	for(int i = 0; i < tree_size; i++)
		tmp += text[index++];
	text = tmp;
    infile.clear();
    infile.seekg(0, std::ios::beg);
    return tree_size;
}

void parse_binary_text(std::ifstream& infile, std::string& text, int tree_size, int zeros) {
	std::stringstream input;
	char c;
    while (infile.get(c)) {
        if (c == '#')
            break;
    }
    for (int i = 0; i < tree_size; i++)
        infile.get(c);
	while (infile.get(c)) {
		for (int i = 7; i >= 0; i--)
			input << ((c >> i) & 1);
	}
	text = input.str();
	for (int i = 0; i < zeros; i++)
		text.pop_back();
}