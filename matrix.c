#include "include/matrix.h"

/*****
*   Initialize Matrix
*
*   Allocate memory for a mxn matrix
*/
void init_matrix(int*** matrix, int m, int n){
    int** temp = (int**)calloc(m, sizeof(int*));
    int i;
    for(i=0; i<m; i++){
        temp[i] = (int*)calloc(n, sizeof(int));
    }

    *matrix = temp;
}

/*****
*   Identity Matrix
*
*   Returns an identity matrix of size dxd
*/
int** identity(int d){
    int** temp = (int**)calloc(d, sizeof(int*));
    int i;

    for(i=0; i<d; i++){
        temp[i] = (int*)calloc(d,sizeof(int));
        temp[i][i] = 1;
    }

    return temp;
}

/*****
*   Ones
*
*   Returns a matrix of 1xm matrix filled with 1
*/
int* ones(int m){
    int* x = (int*)calloc(m, sizeof(int));
    int i;

    for(i=0; i<m; i++)
        x[i] = 1;

    return x;
}

/*****
*   Add Matricies
*
*   Adds to matricies of same size
*/
int** add_matrix(int** A, int** B, int m , int n){
    int i, j, **res;
    init_matrix(&res, m, n);

    for(i=0; i<m; i++){
        for(j=0; j<n; j++)
            res[i][j] = A[i][j] + B[i][j];
    }

    return res;
}

/****
*   Multiply 1xm and mxn dimensional matrices
*
*   Could have just made 1xm matricies 2D
*/
void col_sum(int m, int** A, int* x, int** sim){
    int i, j;
    int* res = (int*)calloc(m,sizeof(int));

    for(i=0; i<m; i++){
        for(j=0; j<m; j++){
            res[i] += A[j][i] * x[i]; 
        }
    }

    *sim = res;
}

/*****
*   Multiply Matricies
*
*   Multiplies an mxn matrix by a nxp matrix
*   Result is a mxp matrix
*/
void multiply(int m, int p, int** A, int** B, int*** sim){
    int i, j, k, **res;
    init_matrix(&res, m, m);

    for(i=0; i<m; i++){
        for(j=0; j<m; j++){
            res[i][j] = 0;
            for(k=0; k<p; k++){
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    *sim = res;
}

int** pow_matrix(int** matrix, int m, int pow){
    int i, j, **res;
    init_matrix(&res, m, m);
    
    for(i=0; i<m; i++){
        for(j=0; j<m; j++)
            res[i][j] = matrix[i][j];
    }

    for(i=0; i<pow; i++)
        multiply(m, m, res, matrix, &res);

    return res;
}

/*****
*   Transpose Matrix
*
*   Flips matrix about it's diagonal
*   Takes an mxn matrix
*       makes each A[i,j] element become A[j,i]
*   Returns nxm matrix
*/
int** transpose(int row, int col, int** edges){
   int i, j, temp, **res; 
   init_matrix(&res, col, row);

    for(i=0; i<col; i++){
       for(j=0; j<row; j++)
           res[i][j] = edges[j][i];
    }

    return res;
}


/*****
*   Matrix Magnitude
*
*   Find the magnitude of 1xm matric (vector)
*/
float matrix_mag(int* matrix, int m){
    float mag = 0;
    int i;

    for(i=0; i<m; i++){
        mag += (float)pow(matrix[i],2);
    }
    mag = sqrt(mag);

    return mag;
}
