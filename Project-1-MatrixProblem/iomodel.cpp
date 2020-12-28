#include <iostream> // cout, endl
#include <stdio.h> // printf 
#include "matrix.h" // Matrix class
#include <fstream> // ifstream

Matrix calculateData(Matrix&, Matrix&); // Does necessary calculations for problem

int main(int argc, char** argv) {
	srand(time(NULL));	
	
	int argCount = argc;
	if (argCount != 2) { // Error Code for incorrect arguments
		std::perror("Cannot Execute Program: Error Code\n\t--Amount of arguments incorrect");
		exit(1);
	} 
	std::ifstream inFile;
	try {
		inFile.open(argv[1]);
	} catch (...) {
			std::perror("Error: File input not found"); // Error Code for incorrect file
			exit(1);
	}

	int companyCount = 0;
	std::string* compNames = new std::string[50]; // Company limit of 50

	std::cout << "Leontif Economic I/O Model Calculations" << std::endl;
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
		std::cout << "===========================" << std::endl;
		std::cout << "Amount of each product needed: " << std::endl;
		for (int i = 0; i < companyCount; i++) {
			std::cout << compNames[i] << ": " << result.getElement(i, 0) << " units" <<
					std::endl;
		}
		std::cout << "===========================" << std::endl;
		inFile.ignore(5, '\n');
		inFile.ignore(5, '\n');
		num = 0;
		companyCount = 0;
	}

	delete [] compNames;

	inFile.close();

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
