#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>
#include "OGenerator.cpp"
#include "PureTrie.cpp"

int main()
{	
	Generator putka("bg_parsed.txt");
	putka.input_board();
	putka.print_board();
	putka.win();
	return 0;
}
