#ifndef matrix_h
#define matrix_h

#include <stdlib.h>
#include <math.h>

void init_matrix(int***, int, int);

int** identity(int);
int* ones(int);

int** add_matrix(int**, int**, int, int);
void col_sum(int, int**, int*, int**);

void multiply(int, int, int**, int**, int***);
int** pow_matrix(int**, int, int);
int** transpose(int, int, int**);

float matrix_mag(int*, int);

#endif
