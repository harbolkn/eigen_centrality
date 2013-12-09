#include "include/util.h"

node* HEAD = NULL;

int main(){
    int opt, m;
    int **uu, **ii, **interests, *uid;
    float* eig;
    int i, j;

    while(1){
        printf(MENU);
        scanf("%d", &opt);

        switch(opt){
            case 0: 
                exit(EXIT_SUCCESS);
            case 1: 
                m = from_file(&uu, &ii, &interests, &uid); 
                eig_cent(&eig, uu, m);
                place_ad(eig, uid, m, num_ads());
                break;
            case 2: 
                m = build_graph(&uu, &ii, &interests, &uid); 
                eig_cent(&eig, uu, m);
                place_ad(eig, uid, m, num_ads());
                break;
            default: printf("Invalid Menu Option\n");
        }
    }

    return 0;
}



/*****
*   Print 1xm vector 
*/
void print_uid(int* uid, int m){
    int i;
    for(i=0; i<m; i++)
        printf("%d\n", uid[i]);
    printf("\n");
}

/*****
*   Print mxn matrix
*/
void print_matrix(int** matrix, int m, int n){
    int i, j;

    for(i=0; i<m; i++){
        for(j=0; j<n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

/*****
*   Determine Ads
*/
int num_ads(){
    int num;
    printf("Number of Ads to place: ");
    scanf("%d", &num);
    return num;

}

/*****
*   Similarity
*
*   Creates matrix similarities
*   User X User similarity
*   Interest X Interest similarity
*/
void similarity(int m, int** interests, int*** uu, int*** ii){
    int **int_T, **uu_temp, **ii_temp;

    int_T = transpose(m, END, interests);
    multiply(m, END, interests, int_T, &uu_temp);
    multiply(END, m, int_T, interests, &ii_temp);
    *uu = uu_temp;
    *ii = ii_temp;
}

/*****
*   Read Users from a File
*
*   Reads UIDs
*   Assigns interests at random
*   Creates similarity matricies
*/
int from_file(int*** uu, int*** ii, int*** interests, int** uid){
    int m, i, j;

    char* file_name = (char*)malloc(sizeof(char)*MAX_WORD); 
    printf("File name: "); scanf("%s", file_name);

    FILE* fp;
    int **int_temp, *uid_temp;

    m = graph_size(fp, file_name);

    // Get UIDs
    int* temp_ids = (int*)calloc(m, sizeof(int));
    temp_ids = get_uid(fp, file_name, m);
    *uid = temp_ids;

    // Make User X Interest Matrix
    assign_interests(m, &int_temp, END);
    *interests = int_temp;

    // Similarities
    similarity(m, int_temp, uu, ii);

    return m;
}



/*****
*   User created Social Network
*
*   Allows user to simulate their own social network
*   Hashes user names and creates UID matrix
*   Assigns interests at random
*   Creates similarity matricies
*/
int build_graph(int*** uu, int*** ii, int*** interests, int** uid){
    int opt=0, m;
    node *head = NULL, *cur=NULL, *ref=NULL, *parent=NULL;
    char**  name;

    while(1){
        printf(GRAPH_MENU);
        scanf("%d", &opt);

        switch(opt){
            case 0: 
                m = list_length(head); // Network Size
                to_array(head, uid); // UIDs
                assign_interests(m, interests, END); // Interest Matrix
                similarity(m, *interests, uu, ii); // Similarities
                HEAD = head;

                return m;
            case 1: // Add Node
                ref = get_node();
                name = get_name();
                fill_node(ref,name);
                head = add_node(head, ref);
                cur = head;
                break;

            case 2: // Add Friend
                if(cur != NULL)
                    name = get_name();

                    if(search(head, name, &parent) == NULL){ //Friend Doesn't Exist Yet
                        ref = get_node();
                        fill_node(ref, name);
                        head = add_node(head, ref);
                    }
                    else 
                        ref = search(head, name, &parent);

                    add_friend(cur, name);
                    add_friend(ref, cur->name);
                break;

            case 3: // Switch Node
                cur = search(head, get_name(), &parent);
                break;

            case 4: // View Nodes
                print_list(head);
                break;

            case 5: // View Friends
                printf("%s %s's Friends: \n", cur->name[0], cur->name[1]);
                if(cur != NULL)
                    view_leaf(cur->root);

                printf("\n");
                break;

            default: printf("Invalid Option\n");
        }
    }
}
