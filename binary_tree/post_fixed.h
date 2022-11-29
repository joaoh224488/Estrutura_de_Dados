
#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    char info;
    struct post_fixed *left;
    struct post_fixed *right;
} post_fixed;


post_fixed *create_post_fixed(char v, post_fixed *left, post_fixed *right);

void calc_operand(post_fixed *root, char v);

void calc_operator(post_fixed *root, char v);

int calc_result(post_fixed *root);

void free_post_fixed(post_fixed *root);
