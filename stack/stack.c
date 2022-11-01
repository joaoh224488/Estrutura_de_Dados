
#include "stack.h"


stack * create_stack(){
    stack *p;
    p =  (stack *) malloc(sizeof(stack));

    //p->top = create_ll();

    p->top = NULL;


    return p;
}

int empty_stack(stack ** p){
    return (p == NULL);
}

int push(stack ** p, int v){

    node * new_top;

    new_top = (node *) malloc(sizeof(node));

    if (!new_top) return FALSE;

    //if (ll_is_clear(&(*p)->top))

    new_top->info = v;

    new_top->next = (*p)->top;

    (*p)->top = new_top;

    return TRUE;
}


int pop(stack **p){
    node * t;
    int v;

    if (empty_stack(p)){
        printf("User tried to pop in a empty list.\n");
        exit(1);
    }

    t = (*p)->top;

    (*p)->top = t->next;

    v = t->info;
    free(t);

    return v;
}
/*
Nesta função recursiva, o caso base serve unicamente para parar o programa para não 
mostrar a subpilha vazia
*/
void show_stack(node *p){
    
    if (!p){
        putchar('\n');
        return;
    }
    printf("%d ", p->info);
    show_stack(p->next);
}

void free_stack(stack **p){
    node *t, *next;

    for(t = (*p)->top; t != NULL; t = next){
        next = t->next;
        free(t);
    }

    free(*p);
}