#include "graph.h"

int graph_size(FILE* fp, char* file_name){
    fp = fopen(file_name, "r");

    int m = 0;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    if( fp == NULL ){
        printf("Error: File not opened\n");
        exit(EXIT_FAILURE);
    }
    else{
        while((read = getline(&line, &len, fp)) != -1){
            m++;
        }
    }

    fclose(fp);

    return m;
}

int* get_uid(FILE *fp, char* file_name, int m){
    fp = fopen(file_name, "r");

    int i = 0;

    char* line = NULL;
    char* subtoken;
    size_t len = 0;
    ssize_t read;

    int* ids = (int*)calloc(m,sizeof(int));

    if( fp == NULL){
        printf("Error: File not opened\n");
        exit(EXIT_FAILURE);    
    }
    else{
        while((read = getline(&line, &len, fp)) != -1){
            subtoken = strtok(line, " "); 
            ids[i] = atoi(subtoken); 
            i++;
        }
    }

    fclose(fp);
    return ids;
}

/*****
*   Giver interests to each user in the graph
*
*   Generate between 0-5 interests per user
*   Put into User X Interest matrix
*/
void assign_interests(int m, int*** interests, int num){
    int i, j, temp;
    int num_int = random()%5; // 0-5 interests per node
    int** array;
    init_matrix(&array, m, num);

    for(i=0; i<m; i++){
        for(j=0; j<num_int; j++){
            // Genderate random interest
            temp = random()%num;
            array[i][temp] = 1;
        }
    }

    *interests = array;
}


int search_array(int* uid, int size, int token){
    int i;
    for(i=0; i<size; i++){
        if(token == uid[i])
            return i;
    }
    return INT_MIN;
}

/*****
*   Depricated - Read Graph Edges from file
*
*   For reading in friend for a user
*   Creates a User X User matrix showing friend relationships
*/
void read_edges(FILE* fp, char* file_name, int m, int* uid, int*** edges){
    fp = fopen(file_name, "r");

    int i = 0, j = -2, place;

    char *line = NULL, *subtoken;
    size_t len = 0;
    ssize_t read;

    int** edge;
    init_matrix(&edge, m, m);

    i = 0;
    if( fp == NULL ){
        printf("Error: File not opened\n");
        exit(EXIT_FAILURE);
    }
    else{
        while((read = getline(&line, &len, fp)) != -1){
            subtoken = strtok(line, " ");

            while( subtoken != NULL ){
                if( j >= 0 ){
                    place = search_array(uid, m, atoi(subtoken));

                    if(place != INT_MIN){
                        edge[i][place] = 1;
                        edge[place][i] = 1;
                    }
                }

                subtoken = strtok(NULL, " ");
                j++;
            }
            i++; j=-2;
        }
    }

    fclose(fp);
    *edges = edge;
}
