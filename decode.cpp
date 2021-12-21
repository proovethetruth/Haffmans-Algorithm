
/*!
    \file
    \brief Файл, содержащий основные функции разархивации.
*/

#include "Haffman Algorithm.h"
#include <iostream>
#include <fstream>

int unpack(std::string& name) {
    std::ifstream infile(name, std::ios::binary);
    if (!infile.is_open()) {
        std::cout << "\n Unable to open binary file ";
        return 0;
    }
    int zeros = infile.get() - '0';

    std::string tree;
    int tree_size = parse_tree(infile, tree);
    std::string text;
    parse_binary_text(infile, text, tree_size, zeros);
    infile.close();
    //std::cout << "\n Tree origin: " << tree;
    //std::cout << "\n Binary text: " << text;

    int index = 0;
    Node* root = readBinaryTree(tree, index);

    std::ofstream outfile(gen_de_filename(name));
    std::cout << "\n\n File is being decoded...\n";
    decode(root, text, outfile);
    outfile.close();
}

void decode(Node* root, std::string& str, std::ofstream& outfile) {
    Node* tree_head = root;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] - '0')
            root = root->right;
        else
            root = root->left;

        if (!root->left && !root->right) {
            outfile << root->ch;
            root = tree_head;
        }
    }
}