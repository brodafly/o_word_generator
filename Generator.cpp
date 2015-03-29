#include "Generator.h"

std::string Generator::invalid = "0";
//Trie Generator::dictionary = Trie();

Generator::Generator(std::string filedir) {
	for (int i = 0; i < 36; i++) {
		if (i < 6 or i >= 30 or i % 6 == 0 or i % 6 == 5) {
			board[i] = invalid;
		}
		else
			board[i] = 'Y';
	}
	load_dictionary(filedir);
}

void Generator::print_board() const {
	for (int i = 0; i < 36; i++) {
		if (i % 6 == 0)
			std::cout << "\n";
		std::cout << board[i] << " ";
	}
}

//HANDLE LONGER THAN ONE CHAR STRING INPUT
void Generator::input_board() {
	int next_tile = 7; //7 is the first real board index
	for (int i = 0; i < 16; i++) {
		std::string in;
		std::cin >> in;
		if (next_tile % 6 == 0)
			next_tile++;
		if (next_tile % 6 == 5)
			next_tile += 2;
		board[next_tile] = in;
		next_tile++;
	}
}

void Generator::win() {
	std::string copy_board[36];
	
	std::unordered_set<std::string> combinations;	
	std::vector<int> valid_blocks;
	
	valid_blocks.resize(36);
	for (int i = 0; i < 36; i++) {
		if (i < 6 or i >= 30 or i % 6 == 0 or i % 6 == 5) {
			valid_blocks[i] = 0;
		}
		else
			valid_blocks[i] = 1;
	}
	//generate_moves(8, 25, board[25], combinations, valid_blocks);
	for (int i = 0; i < 36; i++) {
		if (i > 6 and i < 30 and i % 6 != 0 and i % 6 != 5) {
			generate_moves(8, i, board[i], combinations, valid_blocks);
		}
	}
	
	for (auto i : combinations) {
		if (dictionary.searchWord(i) and i.length() > 4)	//length is x2 cuz of utf16
			std::cout << i << "\n";
	}
}

void Generator::load_dictionary(std::string filedir) {
	std::ifstream file (filedir);
	std::string line;	
	if (file.is_open() ) {
		while(getline(file, line)) {
			line.pop_back(); // remove \r end of line char
			dictionary.addWord(line);
		}
		file.close();
	}
	std::cout << "Dictionary initialized.\n";	
}

void Generator::generate_moves(const int& depth, const int& start, std::string first_letter, std::unordered_set<std::string>& words, std::vector<int> valid_blocks) {
	if (depth == 0)
		return;
	valid_blocks[start] = 0;
	//add an array with valid spots to proceed and put it as an argument to generate_moves, so that each step 
	//of recursion tracks it's own spaces
	if (valid_blocks[start + Up] != 0) {
		//can check if it is a word and only then push it
		words.insert(first_letter + board[start + Up]);
		generate_moves(depth - 1, start + Up, first_letter + board[start + Up], words, valid_blocks);
	}
	if (valid_blocks[start + Down] != 0) {
		words.insert(first_letter + board[start + Down]);
		generate_moves(depth - 1, start + Down, first_letter + board[start + Down], words, valid_blocks);		
	}
	if (valid_blocks[start + Left] != 0) {
		words.insert(first_letter + board[start + Left]);
		generate_moves(depth - 1, start + Left, first_letter + board[start + Left], words, valid_blocks);
	}
	if (valid_blocks[start + Right] != 0) {
		words.insert(first_letter + board[start + Right]);
		generate_moves(depth - 1, start + Right, first_letter + board[start + Right], words, valid_blocks);
	}
	if (valid_blocks[start + Up_Right] != 0) {
		words.insert(first_letter + board[start + Up_Right]);
		generate_moves(depth - 1, start + Up_Right, first_letter + board[start + Up_Right], words, valid_blocks);
	}
	if (valid_blocks[start + Up_Left] != 0) {
		words.insert(first_letter + board[start + Up_Left]);
		generate_moves(depth - 1, start + Up_Left, first_letter + board[start + Up_Left], words, valid_blocks);
	}
	if (valid_blocks[start + Down_Right] != 0) {
		words.insert(first_letter + board[start + Down_Right]);
		generate_moves(depth - 1, start + Down_Right, first_letter + board[start + Down_Right], words, valid_blocks);
	}
	if (valid_blocks[start + Down_Left] != 0) {
		words.insert(first_letter + board[start + Down_Left]);
		generate_moves(depth - 1, start + Down_Left, first_letter + board[start + Down_Left], words, valid_blocks);
	}
	return;
}
