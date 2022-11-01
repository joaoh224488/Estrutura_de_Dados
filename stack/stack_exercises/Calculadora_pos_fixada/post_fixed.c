
#include "post_fixed.h"


stack * create_stack(){
    stack *p;
    p =  (stack *) malloc(sizeof(stack));

    //p->top = create_ll();

    p->top = NULL;


    return p;
}

int empty_stack(stack *p){
    return (p->top == NULL);
}


int push(stack * p, int v){

    node * new_top;

    new_top = (node *) malloc(sizeof(node));

    if (!new_top) return FALSE;

    //if (ll_is_clear(&(*p)->top))

    new_top->info = v;

    new_top->next = p->top;

    p->top = new_top;

    return TRUE;
}


int pop(stack *p){
    node * t;
    int v;

    if (empty_stack(p)){
        printf("User tried to pop in a empty list.\n");
        exit(1);
    }

    t = p->top;

    p->top = t->next;

    v = t->info;
    free(t);

    return v;
}

void free_stack(stack **p){
    node *t, *next;

    for(t = (*p)->top; t != NULL; t = next){
        next = t->next;
        free(t);
    }

    free(*p);
}

post_fixed * create_post_fixed(){

    post_fixed *c;

    c = (post_fixed *) malloc(sizeof(post_fixed));

    c->p = create_stack();

    return c;
}

void calc_operand(post_fixed *c, int v){
    push(c->p, v);
    printf("Pushed %d\n", v);
}

void calc_operator(post_fixed *c, char op){
    int v1, v2, v3;

    if (empty_stack(c->p)){
        v2 = 0;
    }
    else{
        v2 = pop(c->p);
    }

    if (empty_stack(c->p)){
        v1 = 0;
    }
    else{
        v1 = pop(c->p);
    }

    switch(op){
        case '+':
            v3 = v1 + v2;
            break;
        case '-':
            v3 = v1 - v2;
            break;
        case '*':
            v3 = v1 * v2;
            break;
        case '/':
            v3 = v1 / v2;
            break;
        default:
            printf("Invalid operator.\n");
            exit(1);
    }

    push(c->p, v3);

    printf("%d %c %d = %d\n", v1, op, v2, v3);
}

void free_post_fixed(post_fixed **c){
    free_stack(&(*c)->p);
    free(*c);
    printf("Calculator freed.\n");
}


