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
};

struct comp
{
	bool operator()(Node* l, Node* r) {
		return l->freq > r->freq;
	}
};

int check_task(char* argv[]);

Node* addNode(char ch, int freq, Node* left, Node* right);

int parse_file(std::string& name, std::string& text);

void build_tree(std::string& text, std::string& name);
void encode(Node* root, std::string str, std::unordered_map<char, std::string>& huffmanCode);
std::string bin_to_hex(std::ofstream& file, std::string& str);

void writeBinaryTree(std::ofstream& out, Node* p);
void readBinaryTree(std::ifstream& fin, Node*& p);



#endif
