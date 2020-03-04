#include <iostream>
#include <stdio.h>
#include "matrix.h"
#include <fstream>

Matrix calculateData(Matrix&, Matrix&); // Does necessary calculations for problem

int main() {
	srand(time(NULL));	
/*	
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
*/
	/*
	std::ifstream infile;
	infile.open("data.txt");
	
	std::string names[3];
	int dimensions = 0;
	Matrix* matArr;
	Matrix demand;
	while (infile.peek() != EOF) {
		for (int i = 0; infile.peek() != "---"; i++) {
			infile >> names[i];
			dimensions++;
		}
		infile.ignore(3, "\n");
		matArr = new Matrix[1];
		Matrix insertMe(dimensions, dimensions);
		for (int i = 0; i < dimensions; i++) {
			for (int j = 0; j < dimensions; j++) {
				infile >> matArr[0].arr[i][j]; 
			}
		}
		infile.ignore(3, "\n");
		Matrix insertDemand(dimensions, 1);
		for(int i = 0; i < dimensions; i++) {
			infile >> insertDemand.arr[i][0];
		}
		demand = insertDemand;
	}
	infile.close();

	matArr[0].printMatrix();
	demand.printMatrix();
	*/
	Matrix m;
	Matrix d(3,1);
	std::cout << "Matrix orignially being worked on" << std::endl;
	m.printMatrix();
	std::cout << "original demand vector " << std::endl;
	d.printMatrix();
	Matrix tmp = m.inverse();
	Matrix identity = m * tmp;
	std::cout << "Should be identity matrix!" << std::endl;
	identity.printMatrix();
	Matrix result;
	try {
	result = calculateData(m, d);
	} catch (const char* n) {
		std::cout << n;
	}
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
