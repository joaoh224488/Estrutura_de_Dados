#include "doubly_linked_list.h"

#define TRUE 1
#define FALSE 0

node * create_dll(){
    return NULL;
}

int dll_add_begin(node **dll, int v){
    //cria node
    node * new;

    new = (node *) malloc(sizeof(node));
    if (!new) return (FALSE);

    //preenche node

    new->info = v;
    new->next = *dll;
    new->prev = NULL;

    // insere node
    *dll = new;

    return TRUE;

}

int dll_add_back(node **dll, int v){
    //cria node
    node * new;
    node * p;

    new = (node *) malloc(sizeof(node));
    if (!new) return (FALSE);

    //preenche node

    new->info = v;
    new->next = NULL;

    // insere node
    if (*ll == NULL){
        new->prev = NULL;
        *ll = new;
    } else {
        for (p = *ll; p->next != NULL; p = p->next);
        p->next = new;
        new->prev = p;
    }

    return TRUE;

}

int dll_insert_at(node **dll, int pos, int v){
    //cria node
    node * new;
    node * p;
    int i;

    return TRUE;

}

node * dll_search(node **)

