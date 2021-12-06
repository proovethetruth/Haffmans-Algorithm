
#include "Haffman Algorithm.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <bitset>

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
	for (char ch : text) {
		freq[ch]++;
	}

	std::cout << "\n\n Found characters frequency: ";
	for (auto& it : freq) {
		std::cout << "\n " << it.first;
		std::cout << " " << it.second;
	}

	std::priority_queue<Node*, std::vector<Node*>, comp> pq;
	for (auto pair : freq) {
		pq.push(addNode(pair.first, pair.second, nullptr, nullptr));
	}

	while (pq.size() != 1) {
		Node* left = pq.top();
		pq.pop();
		Node* right = pq.top();
		pq.pop();

		pq.push(addNode('\0', (left->freq + right->freq), left, right));
	}

	Node* root = pq.top();

	std::unordered_map<char, std::string> huffmanCode;
	encode(root, "", huffmanCode);

	std::cout << "\n\n Huffman Codes are :";
	for (auto pair : huffmanCode) {
		std::cout << "\n " << pair.first << " " << pair.second;
	}

	std::string str = "";
	for (char ch : text) {
		str += huffmanCode[ch];
	}

	std::string base_name;
	base_name = name + " - encoded.txt";
	std::ofstream outfile(base_name);

	while (str.size() % 8 != 0) {
		str = "0" + str;
	}

	reverse(str.begin(), str.end());
	std::bitset<4> set;
	std::string tmp;
	while (str.size() != 0) {
		for (std::size_t i = 0; i < 4; i++) {
			set[i] = str[i] - '0';
			std::cout << set[i];
		}
		outfile << " - " << std::hex << set.to_ulong() << std::endl;
		str.erase(0, 4);
	}
	outfile.close();

	//base_name = name + "'s tree.txt";
	//std::fstream outfile(base_name);
	//outfile.open();
	//save_tree(outfile, root);
	//outfile.close();
}

void encode(Node* root, std::string str, std::unordered_map<char, std::string>& huffmanCode) {
	if (root == nullptr)
		return;

	// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}
