#ifndef matrix_h
#define matrix_h

#include <stdlib.h>
#include <math.h>


/*****
*   Basic matrix generators
*/
// Initialize 2D array
void init_matrix(int***, int, int);

// Create identity matrix of size mxm
int** identity(int);

// Creates a vector of ones, size 1xm
int* ones(int);




/*****
*   Matrix Arithmatic
*/
// Adds two matricies of the same size
int** add_matrix(int**, int**, int, int);

// Multiply matrix by a vector
void col_sum(int, int**, int*, int**);

// Multiply two matricies
void multiply(int, int, int**, int**, int***);

// Raise a matrix to a power (A^6)
int** pow_matrix(int**, int, int);

// Transpose a matrix (flip about it's diagonal
int** transpose(int, int, int**);

// Find the magnitude of a vector
float matrix_mag(int*, int);

#endif
