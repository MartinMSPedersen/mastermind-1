all: 
	g++ -Wall -Wextra -std=c++11 board.cpp userline.cpp main.cpp -o mastermind

run: all 
	./mastermind

zip: all
	cd .. && zip -r mastermind.zip mastermind -x mastermind/.\*

clean:
	rm mastermind
	rm mastermind.zip
