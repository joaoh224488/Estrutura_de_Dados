#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
    struct node *prev;
} node;


node *create_dll();

int dll_add_begin(node ** dll, int v);
int dll_add_end(node ** dll, int v);
int dll_insert_at(node ** dll, int v, int pos);

node *dll_search(node **dll, int v);

int dll_is_clear(node **dll);

int dll_size(node **dll);

void dll_show(node **dll);
void dll_free(node **dll);

#endif