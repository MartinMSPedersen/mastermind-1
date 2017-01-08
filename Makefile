CXXFLAGS = -Wall -Wextra -std=c++11
OBJECTS = board.cpp userline.cpp main.cpp

all:	mastermind

mastermind: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ 

%.c.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: run zip clean

run: all 
	./mastermind

zip: all
	cd .. && zip -r mastermind.zip mastermind -x mastermind/.\* && mv mastermind.zip mastermind/

clean:
	rm -f mastermind
	rm -f mastermind.zip

