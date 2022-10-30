#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct node
{
    int info;
    struct node * next;
};


typedef struct node node;


struct pile
{
    node * top;
};

typedef struct pile pile;

int push(pile ** p, int v);

int pop(pile **p);

pile * create_pile();
void free_pile(pile **p);


struct post_fixed{
    char f[50]; // input
    pile * p;
};

typedef struct post_fixed post_fixed;

post_fixed * create_post_fixed(char *f);

void calc_operand(post_fixed *c, int v);

void calc_operator(post_fixed *c, char op);

void calc_free(post_fixed *c);



