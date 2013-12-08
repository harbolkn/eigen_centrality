#include "include/tree.h"

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

char** get_name(){
	char **name = (char**)malloc(sizeof(char*) * 2);
	
	name[0] = (char*)malloc(sizeof(char) * MAX_WORD);
	name[1] = (char*)malloc(sizeof(char) * MAX_WORD);
	
	printf("Enter Name: ");
	scanf("%s %s", name[0], name[1]);

	return name;
}

Tree* get_leaf(){
	Tree *temp;
	temp = (Tree*)malloc(sizeof(Tree));

	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void fill_leaf(Tree* leaf, char** name){
	leaf->name = name;
}


// Hash ID for each leaf
void insert_leaf(Tree* root, Tree* add){
	if( strcmp(add->name[1], root->name[1]) < 0){
		if(root->left == NULL)
			root->left = add;
		else
			insert_leaf(root->left, add);
	}

	if( strcmp(add->name[1], root->name[1]) > 0){
		if(root->right == NULL)
			root->right = add;
		else
			insert_leaf(root->right, add);
	}
}


Tree* search_leaf(Tree* root, char** name, Tree** parent){
	Tree* temp = (Tree*)malloc(sizeof(Tree));
	temp = root;

	while(temp != NULL){
		if(strcmp(name[1], temp->name[1]) == 0){
			return temp;	
		}	
		*parent = temp;

		if(strcmp(name[1], temp->name[1]) < 0)
			temp = temp->left;
		else
			temp = temp->right;
	}

	free(temp);
	return NULL;
}

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

		if(remove->left == temp)
			remove->left = NULL;

		free(temp);
	}
}

void view_leaf(Tree* ref){
	if(ref != NULL){
		view_leaf(ref->left);
		printf("%s %s\n", ref->name[0], ref->name[1]);
		view_leaf(ref->right);
	}
}
