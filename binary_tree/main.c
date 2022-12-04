#include "binary_tree.h"


int main(){

    node *root;

    root = create_empty_tree();

    
    root = insert_tree(root, 11);

    root = insert_tree(root, 13);

    root = insert_tree(root, 16);

    root = insert_tree(root, 18);

   // root = insert_tree(root, 14);

    //root = insert_tree(root, 19);

   // root = insert_tree(root, 20);

    root = insert_tree(root, 10);
    root = insert_tree(root, 5);
    //root = insert_tree(root, 15);
    root = insert_tree(root, 3);
    
    root = insert_tree(root, 7);
    root = insert_tree(root, 12);
    //root = insert_tree(root, 17);

    root = insert_tree(root, 4);

    root = insert_tree(root, 6);
    
    
    print_tree(root);

    putchar('\n');


    printf("A altura da árvore é:   %d \n", height_tree(root));

    printf("A altura da árvore left é: %d \n", height_tree(root->left)); 
    printf("A altura da árvore right é: %d \n", height_tree(root->right)); 

    printf("A quantidade de nodos da árvore é: %d\n", q_nodes_tree(root));

    ordered_print(root);

    putchar('\n');


    root = remove_tree(root, 11);

    print_tree(root);

    putchar('\n');


    printf("A altura da árvore é:   %d \n", height_tree(root));

    printf("A altura da árvore left é: %d \n", height_tree(root->left)); 
    printf("A altura da árvore right é: %d \n", height_tree(root->right)); 

    printf("A quantidade de nodos da árvore é: %d\n", q_nodes_tree(root));


    root = remove_tree(root, 13);

    root = remove_tree(root, 16);

    root = remove_tree(root, 18);

    root = remove_tree(root, 10);

    


    

    print_tree(root);
    putchar('\n');
    //print_tree(root->left);
  
    //print_tree(root->right);
    
    //print_tree(root);

    //printf("\n");


    //root->left = free_tree(root->left);



    printf("A altura da árvore é:   %d \n", height_tree(root));

    printf("A altura da árvore left é: %d \n", height_tree(root->left)); 
    printf("A altura da árvore right é: %d \n", height_tree(root->right)); 

    printf("A quantidade de nodos da árvore é: %d\n", q_nodes_tree(root));

    //printf("O nível do nó 11 é %d\n ", node_level(root, 11));

    ordered_print(root);
    putchar('\n');

    root = free_tree(root);



    return 0;
}