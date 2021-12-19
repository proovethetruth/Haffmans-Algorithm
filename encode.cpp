
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

	for (char ch : text) 
		str += huffmanCode[ch];

	for(int i = 0; i < str.size(); i++)
		WriteBit(str[i] - '0', outfile);
	int zeros = Flush_Bits(outfile);
	std::cout << "\n '0'-bits added: " << zeros;
	outfile << "#";
	outfile << zeros;

	std::cout << "\n Binary code: " << str;

	str = "";
	writeBinaryTree(root, str);
	std::cout << "\n Tree transcription: " << str;
	str = "#" + str;
	outfile << str;

	outfile.close();
}

int current_bit = 0;
void WriteBit(int bit, std::ostream& outfile) {
	static unsigned char bit_buffer;
	bit_buffer <<= 1; 
	if (bit)
		bit_buffer |= 0x1;

	current_bit++;
	if (current_bit == 8) {
		outfile.write((char*)&bit_buffer, sizeof(bit_buffer));
		current_bit = 0;
		bit_buffer = 0;
	}
}

int Flush_Bits(std::ostream& outfile) {
	int count = 0;
	while (current_bit) {
		WriteBit(0, outfile);
		count++;
	}
	return count;
}

void encode(Node* root, std::string str, std::unordered_map<char, std::string>& huffmanCode) {
	if (root == nullptr)
		return;

	if (!root->left && !root->right)
		huffmanCode[root->ch] = str;

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}