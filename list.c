#include "include/list.h"

/*****
*   Get Node
*
*   Allocate Memory for a new linked list node
*/
node* get_node(){
    node* new = (node*)malloc(sizeof(node));

    new->root = NULL;
    new->next = NULL;
    return new;
}

/*****
*   Fill Node
*
*   Fill node with essential information
*   Initialize information in node
*/
void fill_node(node* fill, char** name){
    //Name
    fill->name = name;

    //UID
    char* temp = (char*)malloc(sizeof(char)*2*MAX_WORD);
    strncpy(temp, fill->name[0], strlen(fill->name[0]));
    strcat(temp, fill->name[1]);
    fill->uid = string_hash(temp);
}

/*****
*   List Length
*
*   Find the length of a linked list
*/
int list_length(node* head){
    node* ref = head;
    int len = 0;

    while(ref != NULL){
        len++;
        ref = ref->next;
    }

    return len;
}

/*****
*   To Array
*
*   Convert Linked List to an array
*/
void to_array(node* head, int** uid){
    int i = 0;
    int* res = (int*)calloc(list_length(head),sizeof(int));    
    node* ref = head;

    while(ref != NULL){
        res[i] = ref->uid;
        i++;
        ref = ref->next;
    }

    *uid = res;
}

/*****
*   Add Node
*
*   Add node to head of linked list
*/
node* add_node(node* head, node* add){
    if(head == NULL) // First node
        head = add;
    else{
        add->next = head;
        head = add;
    }

    return head;
}

/*****
*   Delete Node
*
*   Deletes a given node from the linked list
*/
void delete_node(node* parent, node* remove){
    parent->next = remove->next;
    free(remove);
}

/*****
*   Search
*
*   Finds if a given node is in the linked list
*/
node* search(node* head, char** name, node** parent){
    if(head == NULL){
        printf("No friends to search\n");
        return NULL;
    }

    node* temp = head;

    char* name_t = (char*)malloc(sizeof(char)*2*MAX_WORD);
    strncpy(name_t, name[0], strlen(name[0]));
    strcat(name_t, name[1]);

    int uid = string_hash(name_t);

    while(temp != NULL){
        if(uid == temp->uid)
            return temp;

        *parent = temp;
        temp = temp->next;
    }

    return NULL;
}

/*****
*   Destroy List
*
*   Free all memory allocated for a linked list
*/
void destroy_list(node* head){
    node* ref = head;

    while(ref != NULL){
        head = ref->next;
        free(ref);
        ref = head;
    }
}

/*****
*   Print List
*
*   Print name - uid for all nodes in list
*/
void print_list(node* head){
    node* ref = head;

    if(ref == NULL){
        printf("No friends in list\n");
        return;
    }

    while(ref != NULL){
        printf("%s %s - %d\n", ref->name[0], ref->name[1], ref->uid);
        ref = ref->next;
    }
    printf("\n");
}

/*****
*   Add Friend
*
*   Insert Friend in BST
*/
void add_friend(node* cur, char** name){
    cur->root = Tree_init(cur->root, name, 1);
}
