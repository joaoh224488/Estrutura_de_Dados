#include "binary_tree.h"


node * create_empty_tree(){
    return NULL;
}

int empty_tree(node *root){
    return root == NULL;
}

node * create_tree(int v, node *left, node *right){
    node *new_node = (node *) malloc(sizeof(node));
    if (new_node == NULL) return 0;
    new_node->info = v;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

node * insert_tree(node *root, int v){
    node * new_node;
    if(empty_tree(root)){
        new_node = create_tree(v, NULL, NULL);
        return new_node;
    }
    else if(v <= root->info){
        root->left = insert_tree(root->left, v);
    }
    else{
        root->right = insert_tree(root->right, v);
    }
    return root;
}



void print_tree(node *root){
    if(root){
        printf("%d ", root->info);
        print_tree(root->left);
        print_tree(root->right);
    }
    else {
        printf("[]");
        return;
    }
}

node * free_tree(node *root){
    if(root){
        root->left = free_tree(root->left);
        root->right = free_tree(root->right);
        printf("Liberando %d  \n", root->info);
        free(root);
        return NULL; // Retorna 
    }

    return NULL;

}

node * binary_search_tree(node *root, int v){
    if(root){
        if(root->info == v){
            return root;
        }
        else if(v <= root->info){
            return binary_search_tree(root->left, v);
        }
        else{
            return binary_search_tree(root->right, v);
        }
    }
    return NULL;
}
