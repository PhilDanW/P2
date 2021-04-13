
CXX = g++
CXXFLAGS = -std=c++0x -Wall -g -w

P2: main.cpp scanner.cpp parseTree.cpp
	$(CXX) $(CXXFLAGS) -o frontEnd main.cpp parseTree.cpp scanner.cpp

clean:
	rm -f frontEnd *.o stdin.temp keyboard_input.txt
