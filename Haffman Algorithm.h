#ifndef HAFFMAN_ALGORITHM_H
#define HAFFMAN_ALGORITHM_H

#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

struct Node {
	char ch;
	int freq;
	Node* left, * right;
};

struct comp
{
	bool operator()(Node* l, Node* r)
	{
		return l->freq > r->freq;
	}
};

Node* addNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

#endif
