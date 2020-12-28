iomodel: matrix.o iomodel.o MatrixDriver.o driver data.txt
	g++ -o iomodel iomodel.o matrix.o -g -std=c++11
driver: matrix.o MatrixDriver.o iomodel.o
	g++ -o driver MatrixDriver.o matrix.o -g -std=c++11
iomodel.o: iomodel.cpp matrix.h data.txt
	g++ -c iomodel.cpp -g -std=c++11
MatrixDriver.o: MatrixDriver.cpp matrix.h
	g++ -c MatrixDriver.cpp -g -std=c++11
matrix.o: matrix.h matrix.cpp
	g++ -c matrix.cpp -g -std=c++11
clean:
	rm -f *.o iomodel driver
