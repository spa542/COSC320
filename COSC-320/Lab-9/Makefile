main: main.o RBTree.o
	g++ -o main main.o RBTree.o -g -std=c++11
main.o: main.cpp RBTree.h
	g++ -c main.cpp -g -std=c++11
RBTree.o: RBTree.h RBTree.cpp
	g++ -c RBTree.cpp -g -std=c++11
clean:
	rm -f *.o main
