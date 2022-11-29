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

    root = insert_tree(root, 11);

    root = insert_tree(root, 13);

    root = insert_tree(root, 16);

    print_tree(root);
    putchar('\n');
    print_tree(root->left);
    putchar('\n');

    print_tree(root->right);
    
    //print_tree(root);

    //printf("\n");


    //root->left = free_tree(root->left);


    putchar('\n');

    root = balance_tree(root);

    print_tree(root);

    putchar('\n');


    printf("A altura da árvore é:   %d \n", height_tree(root));

    printf("A quantidade de nodos da árvore é: %d\n", q_nodes_tree(root));

    printf("O nível do nó 11 é %d\n ", node_level(root, 11));



    root = free_tree(root);




    return 0;
}