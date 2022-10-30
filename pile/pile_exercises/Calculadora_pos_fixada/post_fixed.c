
#include "post_fixed.h"


pile * create_pile(){
    pile *p;
    p =  (pile *) malloc(sizeof(pile));

    //p->top = create_ll();

    p->top = NULL;


    return p;
}

int empty_pile(pile ** p){
    return (p == NULL);
}

int push(pile ** p, int v){

    node * new_top;

    new_top = (node *) malloc(sizeof(node));

    if (!new_top) return FALSE;

    //if (ll_is_clear(&(*p)->top))

    new_top->info = v;

    new_top->next = (*p)->top;

    (*p)->top = new_top;

    return TRUE;
}


int pop(pile **p){
    node * t;
    int v;

    if (empty_pile(p)){
        printf("User tried to pop in a empty list.\n");
        exit(1);
    }

    t = (*p)->top;

    (*p)->top = t->next;

    v = t->info;
    free(t);

    return v;
}