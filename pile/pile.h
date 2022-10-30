#ifndef PILE_H
#define PILE_H

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


struct pile
{
    node * top;
};

typedef struct pile pile;

int push(pile ** p, int v);

int pop(pile **p);

pile * create_pile();


#endif