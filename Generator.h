#ifndef GENERATOR_H
#define GENERATOR_H
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include "PureTrie.h"

enum Direction {
	Up = -6,
	Down = 6,
	Left = -1,
	Right = 1,
	Up_Right = -5,
	Up_Left = - 7,
	Down_Right = 7,
	Down_Left = 5
};

class Generator { 	
public:
	Generator(std::string filedir);
	~Generator() {}
	void print_board() const;
	void input_board();	
	void win();
	void load_dictionary(std::string filedir);

private:
	void generate_moves(const int& depth, const int& start, std::string prefix, std::unordered_set<std::string>& combinations, std::vector<int> valid_blocks);
	static std::string invalid;
	Trie dictionary;
	std::string board[36]; // 4x4 with added invalid boundaries
};

#endif
