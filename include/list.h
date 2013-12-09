#ifndef linkedlist_h
#define linkedlist_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tree.h"
#include "hashtable.h"

typedef struct node{
	char** name;
    int uid;
    Tree* root;
	struct node* next;
}node;

/*****
*   General Functions
*/
// Allocate space for node
node* get_node();

// Fill node memory
void fill_node(node*,char**);

// Find length of linked list
int list_length(node*);

// Convert list to array
// UID array: mx1 made up of hashed UIDs
void to_array(node*, int**);




/*****
*   List manipulation
*/
// Add node to Linked List
node* add_node(node*, node*);

// Delete Node from Linked List
void delete_node(node*, node*);

// Search for Node in Linked List
node* search(node*, char**, node**);

// Add Friend to Friend Tree
void add_friend(node*,char**);

// Delete All Nodes from Linked List
void destroy_list(node*);




/*****
*   Print Linked List 
*/
void print_list(node*);


#endif
