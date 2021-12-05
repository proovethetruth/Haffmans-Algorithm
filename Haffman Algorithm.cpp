
#include "Haffman Algorithm.h"
#include <iostream>

void encode(std::string& text) {
	std::unordered_map<char, int> freq;
	for (char ch : text) {
		freq[ch]++;
	}

	std::cout << "\n Found characters frequency: ";
	for (auto& it : freq) {
		std::cout << "\n " << it.first;
		std::cout << " " << it.second;
	}

	std::priority_queue<Node*, std::vector<Node*>, comp> pq;

	while (pq.size() != 1) {
		// Remove the two nodes of highest priority
		// (lowest frequency) from the queue
		Node* left = pq.top();
		pq.pop();

		Node* right = pq.top();
		pq.pop();

		// Create a new internal node with these two nodes
		// as children and with frequency equal to the sum
		// of the two nodes' frequencies. Add the new node
		// to the priority queue.
		int sum = left->freq + right->freq;
		pq.push(addNode('\0', sum, left, right));
	}

}

void decode(std::string& text) {

}
