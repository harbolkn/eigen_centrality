#include "include/tree.h"


/*****
*   Tree initialization
*
*   Accessor function for creating and managing a BST 
*   Give the root node, reference name and opt
*   Return root of newly altered tree
*/
Tree* Tree_init(Tree* root, char** name, int opt){
	Tree* parent = NULL;
	Tree* ref = NULL;
	char** search_name;

    switch(opt){
		case 1: // Add Node
			ref = get_leaf();
			fill_leaf(ref, name);

			if(root == NULL) root = ref;
			else insert_leaf(root, ref);

            break;
		case 2: // Delete Node
			ref = search_leaf(root, get_name(), &parent);

			if(ref != NULL) delete_leaf(parent, ref); 
			else printf("Node not found\n");

            break;
		case 3: 
			view_leaf(root); 
			break;

        default: printf("Invalid Menu Option\n");
    }

    return root;
}

/*****
*   Get 2D char array
*
*   Hold First and Last name
*/
char** get_name(){
	char **name = (char**)malloc(sizeof(char*) * 2);
	
	name[0] = (char*)malloc(sizeof(char) * MAX_WORD);
	name[1] = (char*)malloc(sizeof(char) * MAX_WORD);
	
	printf("Enter Name: ");
	scanf("%s %s", name[0], name[1]);

	return name;
}


/*****
*   Get leaf
*
*   Allocate memory for a new Tree node   
*/
Tree* get_leaf(){
	Tree *new= (Tree*)malloc(sizeof(Tree));;

	new->left = NULL;
	new->right = NULL;
	return new;
}

/*****
*   Fill Leaf
*
*   Fill leaf with name and uid
*/
void fill_leaf(Tree* leaf, char** name){
	leaf->name = name;

    char* temp = (char*)malloc(sizeof(char)*2*MAX_WORD);
    strncpy(temp, leaf->name[0], strlen(leaf->name[0]));
    strcat(temp, leaf->name[1]);
    leaf->uid = string_hash(temp);
}


/*****
*   Insert Node Into BST
*
*   Use UID for each node to decide where leaf goes
*/
void insert_leaf(Tree* root, Tree* add){
	if( add->uid < root->uid ){
		if(root->left == NULL)
			root->left = add;
		else
			insert_leaf(root->left, add);
	}

	if( add->uid > root->uid ){
		if(root->right == NULL)
			root->right = add;
		else
			insert_leaf(root->right, add);
	}
}

/*****
*   Delete Tree Node
*
*   Delete and reorganize tree
*/
void delete_leaf(Tree* parent, Tree* remove){
	Tree* temp;

	if(remove->left == NULL && remove->right == NULL){
		if(parent->right == remove)
			parent->right = NULL;
		else
			parent->left = NULL;

		free(remove);
		return;
	}
	else if(remove->left == NULL || remove->right == NULL){
		if(remove->left != NULL)
			temp = remove->left;
		else
			temp = remove->right;

		if(parent->right == remove)
			parent->right = temp;
		else
			parent->left = temp;

		free(remove);
	}
	else{
		temp = remove->right;
		while(temp->left != NULL)
			temp = temp->left;

		remove->name = temp->name;
        remove->uid = temp->uid;

		if(remove->left == temp)
			remove->left = NULL;

		free(temp);
	}
}

/*****
*   Search for Leaf in Tree
*
*   Search using hashed UID
*/
Tree* search_leaf(Tree* root, char** name, Tree** parent){
    char* name_t = (char*)malloc(sizeof(char)*2*MAX_WORD);
    strncpy(name_t, name[0], strlen(name[0]));
    strcat(name_t, name[1]);
    
    int uid_comp = string_hash(name_t);
	Tree* temp = root;

	while(temp != NULL){
		if( uid_comp == temp->uid ){
			return temp;	
		}
		*parent = temp;

		if( uid_comp < temp->uid )
			temp = temp->left;
		else
			temp = temp->right;
	}

	return NULL;
}

/*****
*   Print Nodes in BST
*
*   Inorder Traversal for printing
*/
void view_leaf(Tree* ref){
	if(ref != NULL){
		view_leaf(ref->left);
		printf("%s %s - %d\n", ref->name[0], ref->name[1], ref->uid);
		view_leaf(ref->right);
	}
}
