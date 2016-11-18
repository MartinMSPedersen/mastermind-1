all: 
	g++ board.cpp userline.cpp main.cpp -o mastermind

run: all 
	./mastermind
