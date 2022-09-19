#ifndef LIST_H
#define LIST_H

typedef struct 
{
    int *vet;
    int ctrl;
    int tam;
    
}List;

int create_list(List *, int);

int free_list(List *);

int is_full(List *);

int is_empty(List *);

int push_head(List *, int);

int push_back(List *, int);

int remove_back(List *);

int remove_head(List *);

int clean(List *);

void show(List *);

#endif