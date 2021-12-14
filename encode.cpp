
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

	std::cout << "\n\n Source text:\n" << text << "\n";

	std::ofstream outfile(gen_filename(name), std::ios::binary);
	std::string str = "";

	writeBinaryTree(root, str);
	std::cout << "\n Tree transcription: " << str;
	str = str + "#";
	outfile << str;

	str = "";
	for (char ch : text)
		str += huffmanCode[ch];

	std::cout << "\n Binary code: " << str;

	str = bin_to_hex(str);
	std::cout << "\n\n Hex code: " << str;

	save_in_binary(str, outfile);
	outfile.close();
}

void encode(Node* root, std::string str, std::unordered_map<char, std::string>& huffmanCode) {
	if (root == nullptr)
		return;

	if (!root->left && !root->right)
		huffmanCode[root->ch] = str;

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

std::string bin_to_hex(std::string& str) {
	reverse(str.begin(), str.end());
	while (str.size() % 4 != 0)
		str = "0" + str;

	std::stringstream tmp;
	std::bitset<4> set;
	while (str.size() != 0) {
		for (std::size_t i = 0; i < 4; i++)
			set[i] = str[i] - '0';

		tmp << std::hex << set.to_ulong();
		str.erase(0, 4);
	}
	std::string res = tmp.str();
	reverse(res.begin(), res.end());

	if (res.length() % 2 != 0)
		res.insert(0, "0");
	return res;
}