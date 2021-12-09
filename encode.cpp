
#include "Haffman Algorithm.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <bitset>
#include <sstream>

Node* addNode(char ch, int freq, Node* left, Node* right) {
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

void build_tree(std::string& text, std::string& name) {
	std::unordered_map<char, int> freq;
	for (char character : text)
		freq[character]++;

	std::cout << "\n Found characters frequency: ";
	for (auto& it : freq) {
		std::cout << "\n " << it.first;
		std::cout << " " << it.second;
	}

	std::priority_queue<Node*, std::vector<Node*>, comp> node_queue;
	for (auto pair : freq)
		node_queue.push(addNode(pair.first, pair.second, nullptr, nullptr));

	while (node_queue.size() != 1) {
		Node* left = node_queue.top();
		node_queue.pop();
		Node* right = node_queue.top();
		node_queue.pop();

		node_queue.push(addNode('\0', (left->freq + right->freq), left, right));
	}
	Node* root = node_queue.top();

	std::unordered_map<char, std::string> huffmanCode;
	encode(root, "", huffmanCode);

	std::cout << "\n\n Huffman Codes are: ";
	for (auto pair : huffmanCode)
		std::cout << "\n " << pair.first << " " << pair.second;
	std::cout << "\n\n Source text:\n" << text;

	std::string str = "";
	for (char ch : text)
		str += huffmanCode[ch];

	std::cout << "\n Binary code: " << str;

	int index = -1;
	std::cout << "\n\n Decoded text is:\n";
	while (index < (int)str.size() - 1)
		decode(root, index, str);

	std::ofstream outfile(gen_filename(name));

	str = bin_to_hex(outfile, str);
	reverse(str.begin(), str.end());

	std::cout << "\n Hex code: " << str;
	outfile << str;
	outfile.close();

	std::cout << "\n Algorithm efficiency: " << show_efficiency((float)text.size(), (float)str.size());

	/*base_name = name + "'s tree.txt";
	std::ofstream outfile2(base_name);
	writeBinaryTree(outfile2, root);
	outfile2.close();*/
}

float show_efficiency(float before, float after) {
	return (before / after * 100) / 100.;
}

void encode(Node* root, std::string str, std::unordered_map<char, std::string>& huffmanCode) {
	if (root == nullptr)
		return;

	if (!root->left && !root->right)
		huffmanCode[root->ch] = str;

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

std::string bin_to_hex(std::ofstream& file, std::string& str) {
	std::stringstream tmp;
	while (str.size() % 4 != 0)
		str = "0" + str;
	reverse(str.begin(), str.end());

	std::bitset<4> set;
	while (str.size() != 0) {
		for (std::size_t i = 0; i < 4; i++)
			set[i] = str[i] - '0';

		tmp << std::hex << set.to_ulong();
		str.erase(0, 4);
	}
	return tmp.str();
}

void writeBinaryTree(std::ofstream& out, Node* curr) {
	if (curr == NULL) {
		out << "#";
		return;
	}
	out << curr->ch;
	writeBinaryTree(out, curr->left);
	writeBinaryTree(out, curr->right);
}
