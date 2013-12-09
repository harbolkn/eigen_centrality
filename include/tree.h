#ifndef tree_h
#define tree_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hashtable.h"

#define MAX_WORD 20

typedef struct Tree{
    char **name;
    int uid;
    
    struct Tree* left;
    struct Tree* right;    
}Tree;

/*****
*   General Functions
*/
// Menu function for calling all other tree functions
Tree* Tree_init(Tree*, char**, int);

// Get a 2D char array holding a first and last name
char** get_name();

// Allocate memory for a Tree node (leaf)
Tree* get_leaf();

// Fill leaf with necessary information 
void fill_leaf(Tree*, char**);


/*****
*   Tree manipulations
*/
// Add a node into the tree
void insert_leaf(Tree*, Tree*);

// Delete node from the tree
void delete_leaf(Tree*, Tree*);

// Search for a node in the tree
Tree* search_leaf(Tree*, char**, Tree**);




/*****
*   Print Tree
*/
void view_leaf(Tree*);

#endif
