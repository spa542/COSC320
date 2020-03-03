#include <iostream>
#include <stdio.h>
#include "matrix.h"

int main() {
	
	std::cout << "Hello" << std::endl;



	return 0;
}

/*
 * calculateData Function:
 * Does the necessary calculations to get the output for the given problem, returns
 * a matrix
 */
Matrix calculateData(Matrix& input, int demand) {
	Matrix identity = input;
	identity.fillMatrixIdentity();

	Matrix rtnMe = (identity - input).inverse() * demand;

	return rtnMe;
}
