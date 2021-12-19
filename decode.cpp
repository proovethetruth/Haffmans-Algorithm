
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
    std::cout << "\n Tree origin: " << tree;
    std::cout << "\n Binary text: " << text;

    int index = 0;
    Node* root = readBinaryTree(tree, index);

    std::ofstream outfile(gen_de_filename(name));
    std::cout << "\n\n Decoded text:\n";
    index = -1;
    while (index < (int)text.size() - 1)
        decode(root, index, text, outfile);
}

void decode(Node* root, int& index, std::string str, std::ofstream& outfile) {
	if (root == nullptr)
		return;

	if (!root->left && !root->right) {
		outfile << root->ch;
		return;
	}
	index++;

	if (str[index] == '0')
		decode(root->left, index, str, outfile);
	else
		decode(root->right, index, str, outfile);
}