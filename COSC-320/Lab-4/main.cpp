#include <iostream>
#include <stdio.h>
#include "matrix.h"

int main() {
	srand(time(NULL));

	Matrix test;

	test.printMatrix();
	(test * 2).printMatrix();

	Matrix test2(5,4);
	test2.printMatrix();
	(test2 * 3).printMatrix();
	
	Matrix test3;
	Matrix test4;
	std::cout << "Test3\n";
	test3.printMatrix();
	std::cout << "Test4\n";
	test4.printMatrix();
	std::cout << "Added\n";
	(test3.addMatrices(test4)).printMatrix();
	std::cout << "Subtracted\n";
	(test3.subtractMatrices(test4)).printMatrix();

	std::cout << "Test3" << std::endl;
	test3.printMatrix();
	std::cout << "Copy constructor" << std::endl;
	Matrix test5(test3);
	test5.printMatrix();
	
	std::cout << "Overloaded assignment" << std::endl;
	Matrix test6 = test5;
	test6.printMatrix();
	test6 = test6;
	test6.printMatrix();
	std::cout << "Copy test2 over to test6" << std::endl;
	test2.printMatrix();
	test6 = test2;
	test6.printMatrix();

	std::cout << "Testing overloaded addtion" << std::endl;
	Matrix test7;
	test7.printMatrix();
	Matrix test8;
	test8.printMatrix();

	Matrix test9 = test7 + test8;
	test9.printMatrix();

	std::cout << "Testing overloaded subtraction" << std::endl;
	test7.printMatrix();
	test8.printMatrix();

	test9 = test7 - test8;
	test9.printMatrix();

	std::cout << "Multiplication tests" << std::endl;
	Matrix test10(2,2);
	Matrix test11(2,1);
	test10.printMatrix();
	test11.printMatrix();
	Matrix test12 = test10.multMatrices(test11);
	test12.printMatrix();
	
	return 0;
}
