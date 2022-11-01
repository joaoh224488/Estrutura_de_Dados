#include "stack.h"


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

    stack *p;
    int n, i;

    n = 10;

    p = create_stack();


    for (i = 0; i < n; i++){
        push(&p, i);
    }

    show_stack(p->top);
    //ll_show(&(p->top));

    return 0;
}