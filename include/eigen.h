#ifndef eigen_h
#define eigen_h

#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

#define LIM 10

// Eigenvector Centrality Calculator
void eig_cent(float**, int**, int);
void print_eigen(float*, int);

/*****
*   Merge Sort
*/
void merge_sort(float*, int*, int);
void divide(float*, int*, int, int);
void merge(float*, int*, int, int, int);

/*****
*   Select Nodes for Ad Placement
*/
void place_ad(float*, int*, int, int);

#endif
