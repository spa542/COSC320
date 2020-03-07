#include <iostream>
#include <stdio.h>
#include "matrix.h"
#include <fstream>

Matrix calculateData(Matrix&, Matrix&); // Does necessary calculations for problem

int main(int argc, char** argv) {
	srand(time(NULL));	
	
	int argCount = argc;
	if (argCount != 2) {
		std::perror("Cannot Execute Program: Error Code\n\t--Amount of arguments incorrect");
		exit(1);
	} 
	std::ifstream inFile;
	try {
		inFile.open(argv[1]);
	} catch (...) {
			std::perror("Error: File input not found");
			exit(1);
	}

	int companyCount = 0;
	std::string* compNames = new std::string[50]; // Company limit of 50

	while (inFile.peek() != EOF) {
		for (int i = 0; inFile.peek() != '-'; i++) {
			std::getline(inFile, compNames[i]);
			companyCount++;
		}
		inFile.ignore(3,'\n');
		Matrix sample(companyCount, companyCount);
		double num = 0;
		for (int i = 0; i < companyCount; i++) {
			for (int j = 0; j < companyCount; j++) {
				inFile >> num;
				sample.setElement(i, j, num); 
			}
		}
		inFile.ignore(5, '\n');
		inFile.ignore(5, '\n');
		Matrix demand(companyCount, 1);
		for (int i = 0; i < companyCount; i++) {
			inFile >> num; 
			demand.setElement(i, 0, num);
		}
		Matrix result = calculateData(sample, demand);
		std::cout << "Amount of each product needed: " << std::endl;
		for (int i = 0; i < companyCount; i++) {
			std::cout << compNames[i] << ": " << result.getElement(i, 0) << " units" <<
					std::endl;
		}
		inFile.ignore(5, '\n');
		inFile.ignore(5, '\n');
	}

	inFile.close();
	/*
	Matrix m;
	Matrix d(3,1);
	std::cout << "Matrix orignially being worked on" << std::endl;
	//m.fillMatrixWIW();
	m.printMatrix();
	std::cout << "original demand vector " << std::endl;
	//d.fillVector();
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
*/
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
