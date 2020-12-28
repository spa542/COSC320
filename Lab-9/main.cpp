#include "RBTree.h" // Red Black tree class
#include <iostream>
#include <stdio.h>
#include <chrono> // chrono
#include <time.h> // srand, time

void timeInsert(RBTree&); // Times the insert property for binary trees
void timeSearch(RBTree&); // Times the search property for binary trees
void timeDelete(RBTree&); // Times the delete property for binary trees

int main() {
	srand(time(NULL));

	RBTree b;
	std::cout << "==============================================" << std::endl;
	std::cout << "Testing Insert Function: " << std::endl;
	std::cout << "Inserting in this order, 5,7,1,3,4,12,11" << std::endl;
	b.insert(5);
	b.insert(7);
	b.insert(1);
	b.insert(3);
	b.insert(4);
	b.insert(12);
	b.insert(11);
	std::cout << "Output in ascending order for values inserted..." << std::endl;
	b.inorder();
	std::cout << "Output in pre order format for values inserted..." << std::endl;
	b.print();
	std::cout << "==============================================" << std::endl;

	std::cout << "==============================================" << std::endl;
	std::cout << "Testing copy constructor..." << std::endl;
	std::cout << "Current working tree..." << std::endl;
	b.inorder();
	std::cout << "Should be the same tree..." << std::endl;
	RBTree t(b);
	t.inorder();
	std::cout << "Testing overloaded assignment operator..." << std::endl;
	std::cout << "Current working tree..." << std::endl;
	t.inorder();
	std::cout << "Should be the same tree..." << std::endl;
	RBTree s = t;
	s.inorder();
	std::cout << "==============================================" << std::endl;

	std::cout << "==============================================" << std::endl;
	std::cout << "Testing Search Function: " << std::endl;
	std::cout << "Current working tree..." << std::endl;
	b.inorder();
	std::cout << "Searching for 4... this is what is returned..." << std::endl;
	int rtnVal1 = b.search(4);
	std::cout << rtnVal1 << std::endl;
	std::cout << "Searching for 21... this is what is returned..." << std::endl;
	int rtnVal2 = b.search(21);
	std::cout << rtnVal2 << std::endl;
	std::cout << "==============================================" << std::endl;

	std::cout << "==============================================" << std::endl;
	std::cout << "Testing Minimum and Maximum Function: " << std::endl;
	std::cout << "Current Working tree..." << std::endl;
	b.inorder();
	std::cout << "The minimum of this tree is..." << b.minimum() << std::endl;
	std::cout << "The maximum of this tree is..." << b.maximum() << std::endl;
	RBTree c;
	std::cout << "Testing functions on an empty tree..." << std::endl;
	std::cout << "The minimum of this tree is..." << c.minimum() << std::endl;
	std::cout << "The maximum of this tree is..." << c.maximum() << std::endl;
	std::cout << "==============================================" << std::endl;

	std::cout << "==============================================" << std::endl;
	std::cout << "Testing Successor Function: " << std::endl;
	std::cout << "Current Working tree..." << std::endl;
	b.inorder();
	std::cout << "Successor of 7 is..." << b.successor(7) << std::endl;
	std::cout << "Successor of 1 is..." << b.successor(1) << std::endl;
	std::cout << "Successor of 12 is..." << b.successor(12) << std::endl;
	std::cout << "Testing on an empty tree..." << std::endl;
	std::cout << "Successor of 3 is..." << c.successor(3) << std::endl;
	std::cout << "Testing on a one element tree..." << std::endl;
	c.insert(5);
	std::cout << "Current Working tree..." << std::endl;
	c.inorder();
	std::cout << "Successor of 5 is..." << c.successor(5) << std::endl;
	std::cout << "==============================================" << std::endl;

	std::cout << "==============================================" << std::endl;
	std::cout << "Testing Delete Function: " << std::endl;
	std::cout << "Current Working tree..." << std::endl;
	b.insert(2);
	b.insert(6);
	b.inorder();
	std::cout << "Deleting 3..." << std::endl;
	b.deleteNode(3);
	std::cout << "New tree..." << std::endl;
	b.inorder();
	std::cout << "Deleting 5" << std::endl;
	b.deleteNode(5);
	std::cout << "New tree..." << std::endl;
	b.inorder();
	std::cout << "Deleting 11" << std::endl;
	b.deleteNode(11);
	std::cout << "New tree..." << std::endl;
	b.inorder();
	std::cout << "Deleting a node that is not in the tree..." << std::endl;
	b.deleteNode(25);
	std::cout << "Should be the same tree after (deleting) 25..." << std::endl;
	b.inorder();
	std::cout << "==============================================" << std::endl;

	RBTree send;
	timeInsert(send);
	RBTree send2;
	timeSearch(send2);
	RBTree send3;
	timeDelete(send3);

	return 0;
}

/*
   timeInsert Function:
   Times the binary tree insert function on a large amount of elements at a time
*/
void timeInsert(RBTree& b) {
	int tests[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
	int numOfTests = 10;
	for (int i = 0; i < numOfTests; i++) {
		std::cout << "Starting insert tests of size " << tests[i] << std::endl;
		auto start = std::chrono::system_clock::now();

		for (int j = 0; j < tests[i]; j++) {
			b.insert(1 + rand() % 10);
		}

		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: " << elapsed_seconds.count() << "s\n";
	}
}

/*
   timeSearch Function:
   Times the binary tree search function on a large amount of elements at a time
*/
void timeSearch(RBTree& b) {
	int tests[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
	int numOfTests = 10;
	for (int i = 0; i < numOfTests; i++) {
		std::cout << "Starting search tests of size " << tests[i] << std::endl;

		for (int j = 0; j < tests[i]; j++) {
			b.insert(1 + rand() % 100);
		}

		auto start = std::chrono::system_clock::now();

		std::cout << "Key returned: " << b.search(1 + rand() % 100) << std::endl;

		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: " << elapsed_seconds.count() << "s\n";
	}
}

/*
   timeDelete Function:
   Times the binary tree search function on a large amount of elements at a time
*/
void timeDelete(RBTree& b) {
	int tests[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
	int numOfTests = 10;
	for (int i = 0; i < numOfTests; i++) {
		std::cout << "Starting delete tests of size " << tests[i] << std::endl;

		for (int j = 0; j < tests[i]; j++) {
			b.insert(1 + rand() % 100);
		}
		
		auto start = std::chrono::system_clock::now();

		b.deleteNode(1 + rand() % 100);

		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: " << elapsed_seconds.count() << "s\n";		
	}
}
