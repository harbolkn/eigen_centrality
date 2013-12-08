#ifndef tree_h
#define tree_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORD 20

typedef struct Tree{
    char **name;
    int id;
    
    struct Tree* left;
    struct Tree* right;    
}Tree;

Tree* Tree_init(Tree*, char**, int);

char** get_name();
Tree* get_leaf();
void fill_leaf(Tree*, char**);

void insert_leaf(Tree*, Tree*);
Tree* search_leaf(Tree*, char**, Tree**);
void delete_leaf(Tree*, Tree*);
void view_leaf(Tree*);

#endif
