#include "matrix.h"

/*
 * Default Constructor:
 * Initializes the matrix and uses a fill function to fill the matrix completely
 */
Matrix::Matrix() {
	arr = new double*[2];
	for (int i = 0; i < 2; i++) {
		arr[i] = new double[2];
	}
	rowLength = 2;
	columnLength = 2;
	fillMatrix();
	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < columnLength; j++) {
			if (i == j) {
				arr[i][j] = 4;
			} else if (i > j) {
				arr[i][j] = 2;
			} else {
				arr[i][j] = 3;
			}
		}
	}
}

/*
 * Overloaded Constructor:
 * Initializes the matrix to specified row and column values and fills the matrix 
 */
Matrix::Matrix(int r, int c) {
	if (r < 1 || c < 1) {
		throw "Dimensions are not positive real numbers!";	
	}
	arr = new double*[r];
	for (int i = 0; i < r; i++) {
		arr[i] = new double[c];
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
 * fillMatrixDiagonal Function:
 * Creates a diagonal matrix
 */
void Matrix::fillMatrixDiagonal() {
	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < columnLength; j++) {
			if (i == j) {
				arr[i][j] = 0;
			} else {
				arr[i][j] = 1 + rand() % 5;
			}
		}
	}
}

/*
 * fillMatrixTriangle Function:
 * Takes a bool to determine if the matrix will be an upper or lower triangle matrix
 * and then creates that type of matrix accordingly
 */
void Matrix::fillMatrixTriangle(bool isUpper) {
	if (isUpper) {
		for (int i = 0; i < rowLength; i++) {
			for (int j = 0; j < columnLength; j++) {
				if (j >= i) {
					arr[i][j] = 1 + rand() % 5;
				} else {
					arr[i][j] = 0;
				}
			}
		}
	} else {
		for (int i = 0; i < rowLength; i++) {
			for (int j = 0; j < columnLength; j++) {
				if (j <= i) {
					arr[i][j] = 1 + rand() % 5;
				} else {
					arr[i][j] = 0;
				}
			}
		}
	}
}

/*
 * fillMatrixIdentity Function:
 * Creates an identity matrix
 */
void Matrix::fillMatrixIdentity() {
	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < columnLength; j++) {
			if (i == j) {
				arr[i][j] = 1;
			} else {
				arr[i][j] = 0;
			}
		}
	}
}

/*
 * Copy Constructor:
 * Performs deep copy on matrix
 */
Matrix::Matrix(const Matrix& rhs) {
	arr = new double*[rhs.rowLength];
	for (int i = 0; i < rhs.rowLength; i++) {
		arr[i] = new double[rhs.columnLength];
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

		arr = new double*[rhs.rowLength];
		for (int i = 0; i < rhs.rowLength; i++) {
			arr[i] = new double[rhs.columnLength];
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
 * transpose Function:
 * Takes the matrix of the specified class and finds the tranpose and then returns 
 * a new matrix that is the transpose of the passed matrix
 */
Matrix Matrix::transpose() {	
	Matrix trans(columnLength, rowLength);	
	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < columnLength; j++) {
			trans.arr[j][i] = arr[i][j];	
		}
	}
	return trans;
}

/*
 * isSymmetric Function:
 * Checks to see if the matrix is symmetric or not
 */
bool Matrix::isSymmetric() {
	Matrix tmp1 = *this;
	Matrix tmp2 = tmp1.transpose();

	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < columnLength; j++) {
			if (tmp1.arr[i][j] != tmp2.arr[i][j]) {
				return false;
			}
		}
	}
	return true;
}

/*
 * pad Function:
 * Pads the matrix to become a power of 2
 */
Matrix Matrix::pad(int dimension) {
	int count = 0;	
	while (log2(dimension + count) - (int)log2(dimension + count) != 0) {
		count++;
	}
	Matrix rtnMe(dimension + count, dimension + count);
	Matrix identity(count, count);
	identity.fillMatrixIdentity();
	for (int i = 0; i < rtnMe.rowLength; i++) {
		for (int j = 0; j < rtnMe.columnLength; j++) {
			if (i < dimension && j < dimension) {
				rtnMe.arr[i][j] = arr[i][j];
			}
			if (i >= dimension && j >= dimension) {
				rtnMe.arr[i][j] = identity.arr[i - dimension][j - dimension]; 
			}
			if ((i >= dimension && j < dimension) || (i < dimension && j >= dimension)) {
				rtnMe.arr[i][j] = 0;
			}	
		}
	}
	rtnMe.printMatrix();	
	return rtnMe;
}

/*
 * inverse Function:
 * Finds the inverse of the function and then returns a matrix with that is the inverse
 */
Matrix Matrix::inverse() {
	if (rowLength == 1 || columnLength == 1) {
		Matrix rtnMe(1,1);
		if (arr[0][0] != 0) {	
			rtnMe.arr[0][0] = 1.0 / arr[0][0];
		} else {
			rtnMe.arr[0][0] = 0;
		}
		std::cout << "What am i returning?" << std::endl;
		rtnMe.printMatrix();
		return rtnMe;	
	}
	if (rowLength != columnLength) {
		throw "Matrix not square!";	
	}
	int originalRow = rowLength;	
	if (log2(rowLength) - (int)log2(rowLength) != 0) { // Checking for power of 2
		if (rowLength == 1) {
			Matrix newRtnMe(1,1);
			newRtnMe.arr[0][0] = arr[0][0];
			return newRtnMe;
		}
		Matrix fixCurr = pad(rowLength);
		std::cout << "Right after" << std::endl;
		fixCurr.printMatrix();
		Matrix rtnMe = fixCurr.inverse();
		Matrix newRtnMe(originalRow, originalRow);	
		std::cout << "FixCurr" << std::endl;
		fixCurr.printMatrix();
		std::cout << "Inverse of fixCurr" << std::endl;
		rtnMe.printMatrix();
		for (int i = 0; i < originalRow; i++) {
			for (int j = 0; j < originalRow; j++) {
				newRtnMe.arr[i][j] = rtnMe.arr[i][j];	
			}
		}
		return newRtnMe;	
	}
	if (!isSymmetric()) { // Checking for symmetry
		Matrix tmp = *this;
		std::cout << "Tmp is not symmetric right now " << std::endl;
		tmp.printMatrix();
		Matrix tmp2 = tmp.transpose();	
		std::cout << "Tmp 2 is tmp transpose" << std::endl;
		tmp2.printMatrix();
		Matrix tmp3 = tmp2 * tmp;
		std::cout << "tmp3 is : " << std::endl;
		tmp3.printMatrix();
		std::cout << "What is happening here? " << std::endl;
		(tmp3.inverse()).printMatrix(); 
		Matrix tmp4 = tmp3.inverse() * tmp2;
		std::cout << "Now symmetric!" << std::endl;
		tmp4.printMatrix();
		return tmp4;
	}
	std::cout << "now inverting ";
	this->printMatrix();
	std::cout << "Rowlength : " << rowLength << std::endl;
	std::cout << "columnlength : " << columnLength << std::endl;
	Matrix B(rowLength / 2, columnLength / 2);
	Matrix C(rowLength / 2, columnLength / 2);
	Matrix CT(rowLength / 2, columnLength / 2);
	Matrix D(rowLength / 2, columnLength / 2);
	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < columnLength; j++) {
			if (i < rowLength / 2 && j < columnLength / 2) {
				B.arr[i][j] = arr[i][j];
			}
			if (i < rowLength / 2 && j >= columnLength / 2) {
				CT.arr[i][j - columnLength / 2] = arr[i][j]; 
			}
			if (i >= rowLength / 2 && j < columnLength / 2) {
				C.arr[i - rowLength / 2][j] = arr[i][j]; 
			}
			if (i >= rowLength / 2 && j >= columnLength / 2) {
				D.arr[i - rowLength / 2][j - columnLength / 2] = arr[i][j];
			}	
		}
	}
	Matrix newB = B.inverse();
	std::cout << "B inverse" << std::endl;
	newB.printMatrix();
	Matrix W = C * newB;
	std::cout << "W" << std::endl;
	W.printMatrix();
	Matrix Wtrans = newB * CT;
	std::cout << "WTRANSPOSE" << std::endl;
	Wtrans.printMatrix();
	Matrix X = W * CT;
	std::cout << "X" << std::endl;
	X.printMatrix();
	Matrix S = D - X;
	std::cout << "S" << std::endl;
	S.printMatrix();
	Matrix V = S.inverse();
	std::cout << "V" << std::endl;
	V.printMatrix();
	Matrix Y = V * W;
	std::cout << "Y" << std::endl;
	Y.printMatrix();
	Matrix Ytrans = Y.transpose();
	std::cout << "YTRANSPOSE" << std::endl;
	Ytrans.printMatrix();
	Matrix T = Ytrans * -1;
	std::cout << "T" << std::endl;
	T.printMatrix();
	Matrix U = Y * -1;
	std::cout << "U" << std::endl;
	U.printMatrix();
	Matrix Z = Wtrans * Y;
	std::cout << "Z" << std::endl;
	Z.printMatrix();
	Matrix R = newB + Z;
	std::cout << "R" << std::endl;
	R.printMatrix();
	Matrix rtnMe(rowLength, columnLength);
	
	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < columnLength; j++) {
			if (i < rowLength / 2 && j < columnLength / 2) {
				rtnMe.arr[i][j] = R.arr[i][j];
			}
			if (i < rowLength / 2 && j >= columnLength / 2) {
				rtnMe.arr[i][j] = T.arr[i][j - columnLength / 2];
			}
			if (i >= rowLength / 2 && j < columnLength / 2) {
				rtnMe.arr[i][j] = U.arr[i - rowLength / 2][j];
			}
			if (i >= rowLength / 2 && j >= columnLength / 2) {
				rtnMe.arr[i][j] = V.arr[i - rowLength / 2][j - columnLength / 2];
			}	
		}
	}
	std::cout << "THis is before return" << std::endl;
	rtnMe.printMatrix();
	return rtnMe;
}

/*
 * TODO Delete this later
 */
void Matrix::fillMatrixWIW() {
	arr[0][0] = 0.6;
	arr[0][1] = 0.02;
	arr[0][2] = 0.1;
	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < columnLength; j++) {
			if (i == 2 && j == 0 || i == 1 && j == 1) {
				arr[i][j] = 0.2;
			}
			if (i == 2 && j == 1 || i == 1 && j == 2) {
				arr[i][j] = 0.4;
			}
			if (i == 1 && j == 0 || i == 2 && j == 2) {
				arr[i][j] = 0.3;
			}
		}
	}
}

/*
 * TODO Delete this later
 *
 */
void Matrix::fillVector() {
	arr[0][0] = 20;
	arr[1][0] = 34;
	arr[2][0] = 80;
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
 * Overloaded multiplication operator:
 * Takes a matrix and then multiplies the matrices together
 */
Matrix Matrix::operator*(Matrix& rhs) {
	return multMatrices(rhs);
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
