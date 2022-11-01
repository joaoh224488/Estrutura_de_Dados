#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
//#include "../linked_list/linked_list.h"


#define TRUE 1
#define FALSE 0

struct node
{
    int info;
    struct node * next;
};


typedef struct node node;


struct stack
{
    node * top;
};

typedef struct stack stack;

int push(stack ** p, int v);

int pop(stack **p);

stack * create_stack();

void free_stack(stack **p);


#endif