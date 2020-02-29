#include <iostream>
#include <stdio.h>
#include "HeapQ.cpp"

int main() {
	
	HeapQ<int> intQ;

	HeapObj<int> t1(5, 25);
	HeapObj<int> t2(7, 78);
	HeapObj<int> t3(90, 4);
	HeapObj<int> t4(1456, 120);
	HeapObj<int> t5(-15, 90);
	HeapObj<int> t6(23, 52);
	
	std::cout << "Quick test of empty print: " << std::endl;
	intQ.print();

	std::cout << "Testing Enqueue Function: " << std::endl;
	intQ.enqueue(t1);
	
	
	return 0;
}
