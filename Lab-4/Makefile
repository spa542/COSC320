main: main.o matrix.o
	g++ -o main -g main.o matrix.o -std=c++11
main.o: main.cpp matrix.h
	g++ -c main.cpp -std=c++11 -g
matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp -std=c++11 -g
clean:
	rm -f *.o main
