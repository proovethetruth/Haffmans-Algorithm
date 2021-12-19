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
std::string gen_filename(std::string original);
void insert_zeros_counter(std::ofstream& outfile, int bits);

void writeBinaryTree(Node* node, std::string& result);
Node* readBinaryTree(std::string& str, int& index);

int parse_file(std::string& name, std::string& text);
int parse_tree(std::ifstream& infile, std::string& text);
void parse_binary_text(std::ifstream& infile, std::string& text, int tree_size, int zeros);

// encode.cpp
void WriteBit(int bit, std::ostream& outfile);
void Flush_Bits(std::ostream& outfile);

Node* addNode(char ch, int freq, Node* left, Node* right);
int pack(std::string& name);
void encode(Node* root, std::string str, std::unordered_map<char, std::string>& huffmanCode);

std::unordered_map<char, int> find_frequency(std::string& text);
Node* build_tree(std::unordered_map<char, int> freq);

// decode.cpp
int unpack(std::string& name);
void decode(Node* root, int& index, std::string str);

#endif
