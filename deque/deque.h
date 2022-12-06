#include <stdio.h>

#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node
{
    int info;

    struct node * prev;

    struct node * next;
} node;


static node * remove_begin_dll(node *);

static node * remove_end_dll(node *);


typedef struct deque
{
    node * head;
    node * tail;
} deque;


deque * create_deque();

int deque_is_empty(deque * );

int push_back(deque *, int v);

int push_front(deque *, int v);

int pop_back(deque *);

int pop_front(deque *);

void free_deque(deque *);

void print_deque(deque *);          // apenas para testes, VIOLA O CONCEITO DE FILA