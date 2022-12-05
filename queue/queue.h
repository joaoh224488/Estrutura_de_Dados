#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0



typedef struct node {
    int info;
    struct node *next;
} node;

typedef struct queue {
    node *head;
    node *tail;
} queue;

queue * create_queue();

int push(queue *, int);

int pop(queue *);   

int queue_is_empty(queue *);

void free_queue(queue *);


void print_queue(queue *);          // apenas para testes, VIOLA O CONCEITO DE FILA
