#ifndef HAFFMAN_ALGORITHM_H
#define HAFFMAN_ALGORITHM_H

#include <string>
#include <unordered_map>

void encode(std::string& text) {
	std::unordered_map<char, int> freq;
	for (char ch : text) {
		freq[ch]++;
	}

	std::cout << "\n Found characters frequency: ";
	for (auto& it : freq) {
		std::cout << "\n "<< it.first;
		std::cout << " " << it.second;
	}


}

void decode(std::string& text) {

}

#endif
