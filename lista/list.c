#include "list.h"

#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0


int create_list(List *l, int tam){

    l->vet  = (int *) malloc(sizeof(int) * tam);

    if(!l->vet)
        return FALSE;

    l->ctrl = -1;

    l->tam = tam;

    return TRUE;
}

int free_list(List *l){
    free(l->vet);
    l->ctrl = -1;

    l->tam = 0;
}

int is_full(List *l){

    if (l->ctrl == l->tam - 1)
        return TRUE;
    else
        return FALSE;

}

int is_empty(List *l){
    if (l->ctrl == - 1)
        return TRUE;
    else
        return FALSE;
}

int push_head(List *l, int v){
    int pos;

    if(is_full(l))
        return FALSE;
    
    else{
        l->ctrl += 1;
        pos =  l->ctrl;
        while (pos > 0)
        {
            l->vet[pos] = l->vet[pos - 1];
            pos--;
        }

        l->vet[0] = v;
        
        return TRUE;
    }
}

int push_back(List *l, int v){

    if (is_full(l))
    
        return FALSE;
    
    else{

        l->ctrl += 1;

        l->vet[l->ctrl] = v;

        return TRUE;
    }

}

int remove_back(List *l){
    if(is_empty(l))
        return FALSE;

    else{
        l->ctrl -= 1;
        return TRUE;
    }
}

int remove_head(List *l){
    int i;

    if(is_empty(l))
        return FALSE;
    
    else{

        l->ctrl -= 1;

        for(i = 0; i <= l->ctrl; i++)
            l->vet[i] = l->vet[i + 1];
        
        return TRUE;
    }
}

int clean(List*l){
    if (is_empty(l))
    {
        return FALSE;
    }
    
    l->ctrl = -1;
    return TRUE;
}

void show(List *l){
    if(is_empty(l)){
        printf("ERROR. MISSING ELEMENTS\n");
        exit(1);
    }

    int i;
    putchar('[');
    for (int i = 0; i <= l->ctrl - 1; i++){
        printf(" %d,", l->vet[i]);
    }
    printf(" %d ]\n", l->vet[l->ctrl]);
}