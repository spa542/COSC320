#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>
#include <stdio.h>

class Matrix {
	private:
		int** arr;
		int rowLength;
		int columnLength;
	
		void fillMatrix(); // Fills the matrix with random values
	public:
		Matrix(); // Default constructor
		Matrix(int, int); // Overloaded constructor that takes a length and width
		Matrix(const Matrix&); // Copy constructor
		~Matrix(); // Destructor
		Matrix& operator=(const Matrix&); // Overloaded assignment
		
		void fillMatrixDiagonal(); // Creates a diagonal matrix
		void fillMatrixTriangle(bool); // Creates a upper/lower triangular matrix
		void fillMatrixIdentity(); // Creates an identity matrix

		Matrix addMatrices(Matrix&); // Adds two matrices together
		Matrix subtractMatrices(Matrix&); // Subtracts two matrices from each other
		Matrix multMatrices(Matrix&); // Multiplies two matrices together
		
		Matrix operator*(int); // Used for multiplying a matrix by a scalar
		Matrix operator*(Matrix&); // Used for multiplying matrices together
		Matrix operator+(Matrix&); // Used for more simple adding of two matrices
		Matrix operator-(Matrix&); // Used for more simple subtracting of two matrices

		void printMatrix(); // Prints out the corresponding matrix
};


#endif
