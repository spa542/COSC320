main: main.o Graph.o
	g++ -o main main.o Graph.o -g -std=c++11
main.o: main.cpp Graph.h list.txt
	g++ -c main.cpp -g -std=c++11
Graph.o: Graph.h Graph.cpp
	g++ -c Graph.cpp -g -std=c++11
clean:
	rm -f *.o main
