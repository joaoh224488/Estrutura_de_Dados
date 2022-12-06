#include "deque.h"



static node * remove_begin_dll(node * head)
{
    node * aux = head;
    head = head->next;
    free(aux);
    return head;
}

static node * remove_end_dll(node * tail)
{
    node * aux = tail;
    tail = tail->prev;
    free(aux);
    return tail;
}

deque * create_deque(){
    deque * d;

    d = (deque *) malloc(sizeof(deque));

    d->head = NULL;
    d->tail = NULL;

    return d;
}

int deque_is_empty(deque *d){
    return (d->head == NULL);
}

int push_front(deque *d, int v){
    node * new_node = (node *) malloc(sizeof(node));


    if (!new_node)
        return FALSE;

    new_node->info = v;
    new_node->next = d->head;
    new_node->prev = NULL;

    if (d->head != NULL)
        d->head->prev = new_node;

    d->head = new_node;

    if (d->tail == NULL)
        d->tail = new_node;

    return TRUE;
}

int push_back(deque *d, int v){

    node * new_node = (node *) malloc(sizeof(node));

    if (!new_node)
        return FALSE;

    new_node->info = v;
    new_node->next = NULL;
    new_node->prev = d->tail;

    if (d->tail != NULL)
        d->tail->next = new_node;

    d->tail = new_node;

    if (d->head == NULL)
        d->head = new_node;

    return TRUE;
}

int pop_front(deque *d){
    if (deque_is_empty(d))
        return FALSE;

    d->head = remove_begin_dll(d->head);

    if (d->head == NULL)
        d->tail = NULL;

    return TRUE;
}

int pop_back(deque *d){
    if (deque_is_empty(d))
        return FALSE;

    d->tail = remove_end_dll(d->tail);

    if (d->tail == NULL)
        d->head = NULL;

    return TRUE;
}


void free_deque(deque *d){
    node * no, *aux;

    no = d->head;

    while (no){
        aux = no->next;

        free(no);

        no = aux;
    }

    free(d);
}





void print_deque(deque *d){

    node * no;

    no = d->head;

    while (no){
        printf("%d ", no->info);

        no = no->next;
    }

    printf("\n");
}


