#include "post_fixed.h"


post_fixed *create_post_fixed(char v, post_fixed *left, post_fixed *right){
    post_fixed *new_node = (post_fixed *) malloc(sizeof(post_fixed));
    if (new_node == NULL) return NULL;
    new_node->info = v;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

