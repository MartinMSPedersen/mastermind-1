all: 
	g++ -Wall -Wextra -std=c++11 board.cpp userline.cpp main.cpp -o mastermind

run: all 
	./mastermind

zip: all
	zip -r mastermind.zip . -x .\*

clean:
	rm mastermind
	rm mastermind.zip
