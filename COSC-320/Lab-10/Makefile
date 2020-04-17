main: main.o Graph.o
	g++ -o main main.o Graph.o -g -std=c++11
main.o: main.cpp Graph.h
	g++ -c main.cpp -g -std=c++11
Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp -g -std=c++11
clean:
	rm -f *.o main
