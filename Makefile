all: 
	g++ -std=c++11 board.cpp userline.cpp main.cpp -o mastermind

run: all 
	./mastermind
