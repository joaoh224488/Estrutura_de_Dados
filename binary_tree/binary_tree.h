#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int info;
    struct node *left;
    struct node *right;
} node;


node *create_empty_tree();

int empty_tree(node *root);

node *insert_tree(node *root, int v);

node *create_tree(int v, node *left, node *right);

void print_tree(node *root);  

node * free_tree(node *root);


node * binary_search_tree(node *root, int v);


