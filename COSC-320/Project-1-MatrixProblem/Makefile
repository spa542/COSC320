main: matrix.o main.o
	g++ -o iomodel main.o matrix.o -g -std=c++11
main.o: main.cpp matrix.h
	g++ -c main.cpp -g -std=c++11
matrix.o: matrix.h matrix.cpp
	g++ -c matrix.cpp -g -std=c++11
clean:
	rm -f *.o iomodel
