#include <iostream>
#include "Generator.h"
#include "Generator.cpp"
#include "PureTrie.h"
#include "PureTrie.cpp"

int main()
{	
	Generator putka("bg_parsed.txt");
	putka.input_board();
	putka.print_board();
	putka.win();
	return 0;
}
