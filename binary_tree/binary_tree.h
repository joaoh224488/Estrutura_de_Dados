#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0



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

void ordered_print(node *root);

node * free_tree(node *root);

node * binary_search_tree(node *root, int v);

int is_in_tree(node *root, int v);

int height_tree(node *root);

int q_nodes_tree(node *root);

int node_level(node *root, int v);

//-------------------------------------------------------------------------------

node *rotate_left(node *);

node *rotate_right(node *);

node *balance_tree(node *);

node *remove_tree(node *, int);

node * recursive_balance(node *);

