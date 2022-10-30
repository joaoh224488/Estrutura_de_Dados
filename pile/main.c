#include "pile.h"


void ll_show(node **ll){

    node *p;
    
    if (*ll == NULL) {
        printf("[ ]\n");
        return;
    
    }


    putchar('[');
    for(p = *ll; p->next != NULL; p = p->next){
        printf("  %d,", p->info);
    }

    printf("  %d  ]\n", p->info);

}


int main(){

    pile *p;
    int n, i;

    n = 10;

    p = create_pile();


    for (i = 0; i < n; i++){
        push(&p, i);
    }

    ll_show(&(p->top));

    for(i = 0; i < n; i++){
        printf("%d , ", pop(&p));
    }
    putchar('\n');

    ll_show(&(p->top));

    return 0;
}