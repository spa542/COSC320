main: main.o HeapQ.o
	g++ -o main -g main.o HeapQ.o -std=c++11
main.o: HeapQ.h main.cpp
	g++ -c main.cpp -std=c++11
HeapQ.o: HeapQ.h HeapQ.cpp
	g++ -c HeapQ.cpp
clean:
	rm -f *.o main
