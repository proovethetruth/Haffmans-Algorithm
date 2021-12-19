
#include "Haffman Algorithm.h"
#include <iostream>

void decode(Node* root, int& index, std::string str) {
	if (root == nullptr)
		return;

	if (!root->left && !root->right) {
		std::cout << root->ch;
		return;
	}
	index++;

	if (str[index] == '0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}