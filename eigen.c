#include "include/eigen.h"

void eig_cent(float** eig, int** A, int m){
    int i, j;

    int** I = identity(m); // Identity matrix
    int* x = ones(m); // 1xm vecotr of ones

    // Increment Matrix Diagonal
    A = add_matrix(A, I, m, m); 

    int** B = pow_matrix(A, m, LIM-1); // B = A^(LIM)

    // Number of paths of length LIM originating from each node
    int* d = (int*)malloc(sizeof(int)*m);
    col_sum(m, B, x, &d);

    float mag = matrix_mag(d, m); // Magnitude of Vector

    // Eigenvector centrality
    float* v = (float*)malloc(sizeof(float)*m);
    for(i=0; i<m; i++){
        v[i] = (float)d[i]/mag;
    }

    *eig = v;
}

/*****
*   Print Eigenvecotr Array 
*/
void print_eigen(float* eig, int m){
    int i;
    for(i=0; i<m; i++)
        printf("%0.4f ", eig[i]);
    printf("\n");
}



/*****
*   Merge Sort
*
*   Sort Float* array in decending value
*   Sort UIDs list along with eigen array
*/
void merge_sort(float* list, int* label, int size){
    divide(list, label, 0, size-1);
}
void divide(float* list, int* label, int low, int high){
    int mid;

    if(low < high){
        mid = (high+low)/2;
        divide(list, label, low, mid);
        divide(list, label, mid+1, high);

        merge(list, label, low, mid, high);
    }
}
void merge(float* list, int* label, int low, int mid, int high){
    float* temp_val = (float*)malloc(sizeof(float)*high-low);
    int* temp_lab = (int*)malloc(sizeof(int)*high-low);

    int i = low, 
        j = mid+1, 
        k = 0;

    while( i <= mid && j <= high){
        if( list[i] >= list[j] ){
            temp_val[k] = list[i];
            temp_lab[k++] = label[i++];
        }
        else{
            temp_val[k] = list[j];
            temp_lab[k++] = label[j++];
        }
    }
    while(i <= mid){
        temp_val[k] = list[i];
        temp_lab[k++] = label[i++];
    }

    while(--k >= 0){
        list[low + k] = temp_val[k];
        label[low + k] = temp_lab[k];
        k--;
    }
}


/*****
*   Place Ads to top node
*
*   For user specified number of ads
*   Sort eigenvector array
*   Print UID and eigenvector values 
*/
void place_ad(float* eig, int* uid, int m, int ads){
    int i;

    //sort eig & uid together decending order
    merge_sort(eig, uid, m);

    //print UID and eigen value for number of ads specified
    for(i=0; i<ads; i++)
        printf("%d - %0.4f\n", uid[i], eig[i]);
}
