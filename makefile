all: win

win: main.o Generator.o PureTrie.o
	g++ main.o Generator.o PureTrie.o -o win -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

Generator.o: Generator.cpp
	g++ -c Generator.cpp -std=c++11

PureTrie.o: PureTrie.cpp
	g++ -c PureTrie.cpp -std=c++11

clean:
	rm -rf *o win
