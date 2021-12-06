
//#include "Haffman Algorithm.h"

//void decode_tree(std::string& text, std::string& tree_name) {
//
//	//int index = -1;
//	//std::cout << "\n Decoded string is: \n";
//	//while (index < (int)text.size() - 2) {
//	//	decode(root, index, text);
//	//}
//}

//void decode(Node* root, int& index, std::string str) {
//	if (root == nullptr) {
//		return;
//	}
//
//	// found a leaf node
//	if (!root->left && !root->right) {
//		std::cout << root->ch;
//		return;
//	}
//	index++;
//
//	if (str[index] == '0')
//		decode(root->left, index, str);
//	else
//		decode(root->right, index, str);
//}