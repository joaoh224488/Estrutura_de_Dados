#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node * next;
};


typedef struct node node;


node * create_ll();

int ll_add_begin(node **ll, int v);

int ll_add_back(node **ll, int v);

int ll_insert_at(node **ll, int pos, int v);

node* ll_search(node **ll, int v);

// insere node inicio da lista, o nodevo nó apontará para um elemento posterior da lista

int ll_show(node **ll);

int ll_is_clear(node **ll);

int ll_remove(node **ll, int v);

int ll_remove_begin(node **ll);

int ll_remove_back(node **ll);

int ll_remove_node(node **ll, int pos);

int ll_remove_at(node **ll, int pos);

int ll_ordered_insert(node **ll, int v);

int ll_size(node **ll);
void ll_free(node **ll);




#endif