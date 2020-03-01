#include <iostream> // cout, endl
#include <stdio.h> // printf
#include "HeapQ.cpp" // HeapQ class and HeapObj struct
#include <string> // std::string class/data type

int main() {

	std::cout << "Testing HeapQ of integers:" << std::endl;
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

	std::cout << "Testing HeapQ of doubles:" << std::endl;
	HeapQ<double> doubQ;

	std::cout << "Quick test of empty print:" << std::endl;
	doubQ.print();
	
	std::cout << "Testing Enqueue Function:" << std::endl;
	doubQ.enqueue(4.555, 7);
	doubQ.enqueue(78.3, 67);
	doubQ.enqueue(67.111, 78);
	doubQ.print();

	std::cout << "Testing Copy Constructor: (should match above output)" << std::endl;
	HeapQ<double> doubQ2(doubQ);
	doubQ2.print();

	std::cout << "Testing Overloaded Assignment: (should match above)" << std::endl;
	HeapQ<double> doubQ3 = doubQ2;
	doubQ3.print();
	std::cout << "Preventing self assignment" << std::endl;
	doubQ3 = doubQ3;

	std::cout << "Testing Enqueueing over and resizing array:" << std::endl;
	doubQ.enqueue(78.456, 9);
	doubQ.enqueue(98.27529, 90);
	doubQ.enqueue(879.45, 1000);
	doubQ.enqueue(729, 78);
	doubQ.enqueue(89, 909);
	doubQ.enqueue(67.5666, 900);
	doubQ.enqueue(75.6545, 234);
	doubQ.print();

	std::cout << "Testing peek Function:" << std::endl;
	HeapQ<double> doubQ4;
	doubQ4.enqueue(54.4, 90);
	doubQ4.enqueue(43.567, 80);
	doubQ4.enqueue(78.54, 22);
	std::cout << "Working queue..." << std::endl;
	doubQ4.print();
	std::cout << "Peeking off the top..." << std::endl;
	doubQ4.peek();

	std::cout << "Testing Dequeue Function:" << std::endl;
	std::cout << "Working queue" << std::endl;
	doubQ.print();
	double ret = doubQ.dequeue();
	std::cout << "Number that was returned..." << std::endl;
	std::cout << ret << std::endl;
	std::cout << "Resulting queue after clean up" << std::endl;
	doubQ.print();

	std::cout << "Testing HeapQ of strings" << std::endl;
	HeapQ<std::string> strQ;

	std::cout << "Quick test of empty print:" << std::endl;
	strQ.print();

	std::cout << "Testing Enqueue Function:" << std::endl;
	strQ.enqueue("jarvis", 80);
	strQ.enqueue("james", 90);
	strQ.enqueue("Ryan", 100);
	strQ.print();

	std::cout << "Testing Copy Constructor: (should match above output)" << std::endl;
	HeapQ<std::string> strQ2(strQ);
	strQ2.print();

	std::cout << "Testing Overloaded Assignment: (should match above)" << std::endl;
	HeapQ<std::string> strQ3 = strQ2;
	strQ3.print();
	std::cout << "Preventing self assignment" << std::endl;
	strQ3 = strQ3;

	std::cout << "Testing Enqueueing over and resizing array:" << std::endl;
	strQ.enqueue("ricky", 91);
	strQ.enqueue("skylar", 30);
	strQ.enqueue("jiminy", 9000);
	strQ.enqueue("erika", 101);
	strQ.enqueue("Gerald", 900);
	strQ.enqueue("Hailey", 80);
	strQ.enqueue("ariela", 566);
	strQ.print();

	std::cout << "Testing peek Function:" << std::endl;
	HeapQ<std::string> strQ4;
	strQ4.enqueue("armaya", 90);
	strQ4.enqueue("jakob", 900);
	strQ4.enqueue("harold", 55);
	std::cout << "Working queue..." << std::endl;
	strQ4.print();
	std::cout << "Peeking off the top..." << std::endl;
	strQ4.peek();

	std::cout << "Testing Dequeue Function:" << std::endl;
	std::cout << "Working queue" << std::endl;
	strQ.print();
	std::string ret1 = strQ.dequeue();
	std::cout << "Value that was returned..." << std::endl;
	std::cout << ret1 << std::endl;
	std::cout << "Resulting queue after clean up" << std::endl;
	strQ.print();

	std::cout << "Quick note! All functions except print() will throw a string " <<
			"error if out of bounds of something is not correct. Everything " <<
			"else works in accordance with the rules of a priority queue." << std::endl;


	return 0;
}
