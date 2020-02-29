#include <iostream>
#include <stdio.h>
#include "HeapQ.cpp"

int main() {
	
	HeapQ<int> intQ;

	std::cout << "Quick test of empty print:" << std::endl;
	intQ.print();

	std::cout << "Testing Enqueue Function:" << std::endl;
	intQ.enqueue(25, 10);
	intQ.enqueue(23, 55);
	intQ.enqueue(25, 100);
	intQ.print();
	
	std::cout << "Testing Copy Constructor: (should match above output)" << std::endl;
	HeapQ<int> intQ2(intQ);
	intQ2.print();

	std::cout << "Testing Overloaded Assignment: (should match above)" << std::endl;
	HeapQ<int> intQ3 = intQ2;
	intQ3.print();
	std::cout << "Preventing self assignment" << std::endl;
	intQ3 = intQ3;

	std::cout << "Testing Enqueueing over and resizing array:" << std::endl;
	intQ.enqueue(87, 40);
	intQ.enqueue(67,90);
	intQ.enqueue(14, 125);
	intQ.enqueue(-40, 500);
	intQ.enqueue(222, 32);
	intQ.enqueue(40, 88);
	intQ.enqueue(4, 2);
	intQ.print();

	std::cout << "Testing peek Function:" << std::endl;
	HeapQ<int> intQ4;
	intQ4.enqueue(20, 1);
	intQ4.enqueue(25, 90);
	intQ4.enqueue(10, 3);
	std::cout << "Working queue..." << std::endl;
	intQ4.print();
	std::cout << "Peeking off the top..." << std::endl;
	intQ4.peek();

	std::cout << "Testing Dequeue Function:" << std::endl;
	std::cout << "Working queue" << std::endl;
	intQ.print();
	int returned = intQ.dequeue();
	std::cout << "Number that was returned..." << std::endl;
	std::cout << returned << std::endl;
	std::cout << "Resulting queue after clean up" << std::endl;
	intQ.print();
	std::cout << "Running some more dequeues and then enqueueing..." << std::endl;
	int returned2 = intQ.dequeue();
	int returned3 = intQ.dequeue();
	int returned4 = intQ.dequeue();

	std::cout << "Numbers returned from three dequeues..." << std::endl;
	std::cout << returned2 << ", " << returned3 << ", " << returned4 << std::endl;
	std::cout << "Current queue..." << std::endl;
	intQ.print();

	std::cout << "Enqueueing a couple numbers..." << std::endl;
	intQ.enqueue(5, 1);
	intQ.enqueue(23, 62);
	std::cout << "Resulting queue..." << std::endl;
	intQ.print();

	std::cout << "All queue related functions (except print() for testing purposes)" <<
			" will throw an error (string) and will display an error message if" <<  
			" caught properly" << std::endl;

	return 0;
}
