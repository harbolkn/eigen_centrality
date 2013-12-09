#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "matrix.h"
#include "list.h"
#include "graph.h"
#include "eigen.h"

#define END golf 
#define MENU "\n0)Exit\n1)Graph From File\n2)User Graph\n"
#define GRAPH_MENU "\n0)Main Menu\n1)New Node\n2)Add Friend\n3)Switch Node\n4)Print Nodes\n5)Print Friends\n"

typedef enum{
    reading=0,
    tv,
    movies,
    fishing,
    programming,
    gardening,
    walking,
    exercise,
    music,
    hunting,
    sports,
    shopping,
    traveling,
    sleeping,
    sewing,
    golf,
//    crafts,
//    camping,
//    swimming,
//    writing,
//    boating,
//    bowling,
//    running,
//    painting
}interest;

void print_uid(int*, int);
void print_matrix(int**, int, int);

int num_ads();

void similarity(int, int**, int***, int***);

int from_file(int***, int***, int***, int**);
int build_graph(int***, int***, int***, int**);
