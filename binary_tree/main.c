#include "binary_tree.h"


int main(){

    node *root, *a1, *a2, *a3, *a4;

    root = create_empty_tree();
    a1 = create_empty_tree();
    a2 = create_empty_tree();
    a3 = create_empty_tree();
    a4 = create_empty_tree();

    root = insert_tree(root, 10);
    root = insert_tree(root, 5);
    root = insert_tree(root, 15);
    root = insert_tree(root, 3);
    root = insert_tree(root, 7);
    root = insert_tree(root, 12);
    root = insert_tree(root, 17);
    //print_tree(root->left);
    
    //print_tree(root);

    //printf("\n");


    //root->left = free_tree(root->left);

    print_tree(root);

    printf("\n");

    a1 = binary_search_tree(root, 12);


    return 0;
}