
#include "Haffman Algorithm.h"
#include <iostream>
#include <fstream>
#include <queue>

Node* addNode(char ch, int freq, Node* left, Node* right) {
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

int pack(std::string& name) {
	std::string text;
	if (!parse_file(name, text)) {
		std::cout << "\n Unable to open file ";
		return 0;
	}
	std::cout << "\n\n Source text:\n" << text << "\n";

	std::unordered_map<char, int> freq = find_frequency(text);
	std::cout << "\n Found characters frequency: ";
	for (auto& it : freq) {
		std::cout << "\n " << it.first;
		std::cout << " " << it.second;
	}

	Node* root = build_tree(freq);

	std::unordered_map<char, std::string> huffmanCode;
	encode(root, "", huffmanCode);
	std::cout << "\n\n Huffman Codes are: ";
	for (auto pair : huffmanCode)
		std::cout << "\n " << pair.first << " " << pair.second;

	std::string str;
	for (char ch : text)
		str += huffmanCode[ch];
	std::cout << "\n Binary code: " << str;

	std::ofstream outfile(gen_en_filename(name), std::ios::binary);

	insert_zeros_counter(outfile, str.size());

	std::string tree;
	writeBinaryTree(root, tree);
	std::cout << "\n Tree transcription: " << tree << std::endl;
	outfile << tree.size();
	outfile << "#";
	outfile << tree;

	writeBinaryString(outfile, str);
	outfile.close();
}

std::unordered_map<char, int> find_frequency(std::string& text) {
	std::unordered_map<char, int> freq;
	for (char character : text)
		freq[character]++;

	return freq;
}

Node* build_tree(std::unordered_map<char, int> freq) {
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
	return node_queue.top();
}

void encode(Node* root, std::string str, std::unordered_map<char, std::string>& huffmanCode) {
	if (root == nullptr)
		return;

	if (!root->left && !root->right)
		huffmanCode[root->ch] = str;

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}