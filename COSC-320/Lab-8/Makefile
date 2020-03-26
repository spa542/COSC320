main: main.o BinaryTree.o
	g++ -o main main.o BinaryTree.o -g -std=c++11
main.o: main.cpp BinaryTree.h
	g++ -c main.cpp -g -std=c++11
BinaryTree.o: BinaryTree.h BinaryTree.cpp
	g++ -c BinaryTree.cpp -g -std=c++11
clean:
	rm -f *.o main
