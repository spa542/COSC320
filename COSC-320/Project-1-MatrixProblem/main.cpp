#include <iostream>
#include <stdio.h>
#include "matrix.h"

Matrix calculateData(Matrix&, Matrix&); // Does necessary calculations for problem

int main() {
	
	
	Matrix m(3,3);
	Matrix d(3,1);
	Matrix result;
	
	try {
	result = calculateData(m,d);
	} catch (std::string n) {
		std::cout << n;
	} catch (char const* n) {
		std::cout << n;	
	}
	std::cout << "Original" << std::endl;
	m.printMatrix();
	Matrix inv = m.inverse();
	std::cout << "Inverse of Original" << std::endl;
	inv.printMatrix();
	Matrix res = m.inverse() * m;
	std::cout << "Check for correctness" << std::endl;
	res.printMatrix();
	result.printMatrix();

	return 0;
}

/*
 * calculateData Function:
 * Does the necessary calculations to get the output for the given problem, returns
 * a matrix
 */
Matrix calculateData(Matrix& input, Matrix& demand) {
	Matrix identity = input;
	identity.fillMatrixIdentity();

	Matrix rtnMe = (identity - input).inverse() * demand;

	return rtnMe;
}
