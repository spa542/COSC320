#include "matrix.h"

/*
 * Default Constructor:
 * Initializes the matrix and uses a fill function to fill the matrix completely
 */
Matrix::Matrix() {
	arr = new int*[3];
	for (int i = 0; i < 3; i++) {
		arr[i] = new int[3];
	}
	rowLength = 3;
	columnLength = 3;
	fillMatrix();
}

/*
 * Overloaded Constructor:
 * Initializes the matrix to specified row and column values and fills the matrix 
 */
Matrix::Matrix(int r, int c) {
	if (r < 1 || c < 1) {
		throw "Dimensions passed are not positive real numbers!";
	}
	arr = new int*[r];
	for (int i = 0; i < r; i++) {
		arr[i] = new int[c];
	}
	rowLength = r;
	columnLength = c;
	fillMatrix();
}

/*
 * fillMatrix Function:
 * Fills the matrix with values from 1 to 5 for testing purposes
 */
void Matrix::fillMatrix() {
	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < columnLength; j++) {
			arr[i][j] = 1 + rand() % 5;
		}
	}
}	

/*
 * Copy Constructor:
 * Performs deep copy on matrix
 */
Matrix::Matrix(const Matrix& rhs) {
	arr = new int*[rhs.rowLength];
	for (int i = 0; i < rhs.rowLength; i++) {
		arr[i] = new int[rhs.columnLength];
	}
	rowLength = rhs.rowLength;
	columnLength = rhs.columnLength;
	
	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < columnLength; j++) {
			arr[i][j] = rhs.arr[i][j];
		}
	}
}

/*
 * Destructor:
 * Performs memory deallocation
 */
Matrix::~Matrix() {
	for (int i = 0; i < rowLength; i++) {
		delete [] arr[i];
	}
	delete [] arr;
}

/*
 * Overloaded assignment operator:
 * Performs a deep copy of a matrix to another matrix
 */
Matrix& Matrix::operator=(const Matrix& rhs) {
		if (this == &rhs) {
			return *this;
		}

		for (int i = 0; i < rowLength; i++) {
			delete [] arr[i];
		}
		delete [] arr;

		arr = new int*[rhs.rowLength];
		for (int i = 0; i < rhs.rowLength; i++) {
			arr[i] = new int[rhs.columnLength];
		}
		rowLength = rhs.rowLength;
		columnLength = rhs.columnLength;

		for (int i = 0; i < rowLength; i++) {
			for (int j = 0; j < columnLength; j++) {
				arr[i][j] = rhs.arr[i][j];
			}
		}

		return *this;
}

/*
 * addMatrices Function:
 * Takes a matrix as an input and adds the two matrices together, returning a third matrix
 */
Matrix Matrix::addMatrices(Matrix& rhs) {
	if (rowLength != rhs.rowLength || columnLength != rhs.columnLength) {
		throw "Matrix dimensions aren't equal!";
	}
	
	Matrix rtnMe(rowLength, columnLength);
	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < columnLength; j++) {
			rtnMe.arr[i][j] = arr[i][j] + rhs.arr[i][j];
		}
	}
	
	return rtnMe;
}

/*
 * Overloaded addition operator:
 * Allows for easy addition instead of using matrix functions
 */
Matrix Matrix::operator+(Matrix& rhs) {
	return addMatrices(rhs);
}

/*
 * subtractMatrices Function:
 * Takes a matrix as an input and then subtracts it from the current class matrix
 */
Matrix Matrix::subtractMatrices(Matrix& rhs) {
	if (rowLength != rhs.rowLength || columnLength != rhs.columnLength) {
		throw "Matrix dimensions aren't equal!";
	}

	Matrix rtnMe(rowLength, columnLength);
	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < columnLength; j++) {
			rtnMe.arr[i][j] = arr[i][j] - rhs.arr[i][j];
		}
	}

	return rtnMe;
}

/*
 * Overloaded subtraction operator:
 * Allows for easy subtraction instead of using matrix functions
 */
Matrix Matrix::operator-(Matrix& rhs) {
	return subtractMatrices(rhs);
}

/*
 * multMatrices Function:
 * Takes a matrix as an input and then multipliese it with the current class matrix
 */
Matrix Matrix::multMatrices(Matrix& rhs) {
	if (columnLength != rhs.rowLength) {
		throw "Matrix dimensions incorrect for algorithm! NxM & MxK not satisfies";
	}

	Matrix rtnMe(rowLength, rhs.columnLength);
	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < rhs.columnLength; j++) {
			int sum = 0;
			for (int l = 0; l < columnLength; l++) {
				sum += arr[i][l] * rhs.arr[l][j];
			}
			rtnMe.arr[i][j] = sum;
		}
	}
	return rtnMe;
}

/*
 * Overloaded multiplication operator:
 * Takes a scalar (single int) and a matrix and multiplies them together 
 */
Matrix Matrix::operator*(int scalar) {
	Matrix rtnMe(rowLength, columnLength);
	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < columnLength; j++) {
			rtnMe.arr[i][j] = scalar * arr[i][j];
		}
	}

	return rtnMe;
}

/*
 * printMatrix Function:
 * Prints the current matrix of the class out to the screen
 */
void Matrix::printMatrix() {
	std::cout << std::endl;
	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < columnLength; j++) {
			std::cout << arr[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
