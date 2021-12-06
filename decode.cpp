
// #include "Haffman Algorithm.h"

//void readBinaryTree(std::ifstream& in, Node*& p) {
//	char val;
//	if (!fscanf(in, "%d ", &val) || val == '#')
//		return;
//	
//	p = new Node(val);
//	readBinaryTree(in, p->left);
//	readBinaryTree(in, p->right);
//}
//
//void decode_tree(std::string& text, std::string& tree_name) {
//
//}

//
//void decode(Node* root, int& index, std::string str) {
//	if (root == nullptr) {
//		return;
//	}
//
//	 found a leaf node
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