#ifndef HAFFMAN_ALGORITHM_H
#define HAFFMAN_ALGORITHM_H

#include <string>
#include <unordered_map>

struct Node {
	char ch = 0;
	int freq = 0;
	Node* left = nullptr, * right = nullptr;

	Node() {}
	Node(char val) {
		ch = val;
	}

	Node(char character, Node* left, Node* right) {
		Node* node = new Node();

		ch = character;
		freq = 0;
		left = left;
		right = right;
	}
};

struct comp {
	bool operator()(Node* l, Node* r) {
		return l->freq > r->freq;
	}
};

// main.cpp
int check_task(char* argv[]);

// fstream.cpp
int parse_file(std::string& name, std::string& text);
int parse_tree(std::string& name, std::string& text);
int parse_binary_text(std::string& name, std::string& text);
std::string gen_filename(std::string original);
void save_in_binary(std::string& str, std::ofstream& outfile);
void writeBinaryTree(Node* node, std::string& result);
Node* readBinaryTree(std::string& str, int& index);

// encode.cpp
Node* addNode(char ch, int freq, Node* left, Node* right);
void build_tree(std::string& text, std::string& name);
void encode(Node* root, std::string str, std::unordered_map<char, std::string>& huffmanCode);


// decode.cpp
void decode(Node* root, int& index, std::string str);

void WriteBit(int bit, std::ostream& outfile);
void Flush_Bits(std::ostream& outfile);
#endif
