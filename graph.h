#ifndef graph_h
#define graph_h

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

/*****
*   General Functions
*/

// Assign interests to each user at random
void assign_interests(int, int***,int);

// Seach Array for a uid
int search_array(int*, int, int);



/*****
* File Functions
*/

// Find Graph Size
int graph_size(FILE*, char*);

// Read UIDs
int* get_uid(FILE*, char*, int);

// Read edges in Social Network
void read_eges(FILE*, char*, int, int*, int***);

#endif
