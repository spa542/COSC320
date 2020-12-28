#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream> // cout, endl
#include <stdio.h> // printf
#include <math.h> // log

class Matrix {
	private:
		double** arr;
		int rowLength;
		int columnLength;
	
		void fillMatrix(); // Fills the matrix with random values
	public:
		Matrix(); // Default constructor
		Matrix(int, int); // Overloaded constructor that takes a length and width
		Matrix(const Matrix&); // Copy constructor
		~Matrix(); // Destructor
		Matrix& operator=(const Matrix&); // Overloaded assignment
	
		void setElement(int, int, double); // Sets a cell to a specified element
		double getElement(int, int); // Gets an element at a specifed cell
		bool isSymmetric(); // Checks for symmetry 
		Matrix pad(int); // Pads the matrix to be a power of 2
		Matrix inverse(); // Finds the inverse of the function and returns it
		Matrix transpose(); // Returns a matrix that is the transpose of it
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
