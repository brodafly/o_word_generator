#include <iostream>
#include "Generator.h"
#include "PureTrie.h"

int main()
{	
	Generator putka("bg_parsed.txt");
	putka.input_board();
	putka.print_board();
	putka.win();
	return 0;
}
