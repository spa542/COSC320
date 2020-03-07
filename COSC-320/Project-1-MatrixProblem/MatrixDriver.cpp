#include <iostream> // cout, endl
#include <stdio.h> // printf
#include "matrix.h" // Matrix class

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

	std::cout << "Testing the transpose function" << std::endl;
	std::cout << "Current working matrix: " << std::endl;
	Matrix norm(4,4);
	norm.printMatrix();
	std::cout << "Transpose is..." << std::endl;
	Matrix trans = norm.transpose();
	trans.printMatrix();

	std::cout << "Testing inverse function" << std::endl;
	std::cout << "Current working matrix..." << std::endl;
	Matrix m(2,2);
	m.printMatrix();
	std::cout << "Inverse of matrix..." << std::endl;
	Matrix inv = m.inverse();
	inv.printMatrix();
	std::cout << "Multiplied should be identity matrix..." << std::endl;
	(m * inv).printMatrix();

	return 0;
}
