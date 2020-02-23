#include <iostream> // cout, endl
#include <stdio.h> // printf
#include "matrix.h" // Matrix class
#include <time.h> // time functions
#include <chrono> // chrono

void time(Matrix&, Matrix&, int, bool, bool); // Times the basic matrix arithmetic

int main() {
	srand(time(NULL));

	std::cout << "Testing printMatrix Function" << std::endl;
	Matrix test;
	test.printMatrix();
	(test * 2).printMatrix();

	std::cout << "Testing Overloaded Constructor" << std::endl;
	std::cout << "Creating 5x4 matrix" << std::endl;
	Matrix test2(5,4);
	test2.printMatrix();
	
	std::cout << "Testing Scalar multiplication overloaded multiplication (BONUS)" << std::endl;
	Matrix test3;
	Matrix test4;
	std::cout << "Test3\n";
	test3.printMatrix();
	std::cout << "Multiplying test3 by 4" << std::endl;
	(test3 * 4).printMatrix();


	std::cout << "Copy constructor" << std::endl;
	std::cout << "Test3" << std::endl;
	test3.printMatrix();
	std::cout << "Test5 copied over from test3" << std::endl;
	Matrix test5(test3);
	test5.printMatrix();
	
	std::cout << "Overloaded assignment" << std::endl;
	Matrix test6 = test5;
	std::cout << "test6 assigned as test5" << std::endl;
	test6.printMatrix();
	std::cout << "Preventing self assignment" << std::endl;
	test6 = test6;
	std::cout << "test6" << std::endl;
	test6.printMatrix();
	std::cout << "test2" << std::endl;
	test2.printMatrix();
	std::cout << "Copy test2 over to test6" << std::endl;
	test6 = test2;
	std::cout << "test6" << std::endl;
	test6.printMatrix();

	std::cout << "Testing overloaded addition" << std::endl;
	Matrix test7;
	std::cout << "test7" << std::endl;
	test7.printMatrix();
	Matrix test8;
	std::cout << "test8" << std::endl;
	test8.printMatrix();
	Matrix test9 = test7 + test8;
	std::cout << "Result" << std::endl;
	test9.printMatrix();

	std::cout << "Testing overloaded subtraction" << std::endl;
	std::cout << "test7" << std::endl;
	test7.printMatrix();
	std::cout << "test8" << std::endl;
	test8.printMatrix();
	test9 = test7 - test8;
	std::cout << "Result" << std::endl;
	test9.printMatrix();

	std::cout << "Testing overloaded multiplication" << std::endl;
	Matrix test10(2,2);
	Matrix test11(2,1);
	std::cout << "test10" << std::endl;
	test10.printMatrix();
	std::cout << "test11" << std::endl;
	test11.printMatrix();
	Matrix test12 = test10 * test11;
	std::cout << "Result" << std::endl;
	test12.printMatrix();

	std::cout << "Testing Diagonal Matrix creation" << std::endl;
	Matrix test13;
	test13.fillMatrixDiagonal();
	test13.printMatrix();

	std::cout << "Testing Triangle Matrix creation" << std::endl;
	std::cout << "Upper" << std::endl;
	test13.fillMatrixTriangle(true);
	test13.printMatrix();
	std::cout << "Lower" << std::endl;
	test13.fillMatrixTriangle(false);
	test13.printMatrix();

	std::cout << "Testing Identity Matrix creation" << std::endl;
	test13.fillMatrixIdentity();
	test13.printMatrix();

	int testCases[] = {1, 3, 4, 8, 10, 20, 50, 70, 150, 300, 700, 1000};
	int len = 12;
	std::cout << "Starting tests of Matrix addition" << std::endl;
	for (int i = 0; i < len; i++) {
		Matrix t1(testCases[i], testCases[i]);
		Matrix t2(testCases[i], testCases[i]);
		time(t1, t2, testCases[i], true, false);
	}

	std::cout << "Starting tests of Matrix subtraction" << std::endl;

	std::cout << "Starting tests of Matrix multiplication (Random Matrices)" << std::endl;

	std::cout << "Starting tests of Matrix multiplication (Diagonal Matrices)" << std::endl;

	std::cout << "Starting tests of Matrix multiplication (Triangular Matrices upper)" << std::endl;

	std::cout << "Starting tests of Matrix multiplication (Triangular Matrices lower)" << std::endl;

	std::cout << "Starting tests of Matrix multiplication (Identity Matrices)" << std::endl;

	std::cout << "Starting tests of Matrix multiplication (Vectors)" << std::endl;

	return 0;
}

void time(Matrix& lhs, Matrix& rhs, int size, bool isAdd, bool isMult) {
	Matrix result(size, size);
	auto start = std::chrono::system_clock::now();

	if (isAdd) {
		result = lhs + rhs;
	} else if (isMult) {
		result = lhs * rhs;
	} else {
		result = lhs - rhs;
	}
	
 	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << std::endl;
	std::cout << "Tests for Matrices of size " << size << std::endl;
	std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: " << elapsed_seconds.count() << "s\n";
	std::cout << std::endl;
}
