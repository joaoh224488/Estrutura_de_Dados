#include "avaliador.h"


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


int push(stack * p, char v){

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

avaliador * create_avaliador(char * expressao){
    avaliador *a;
    a =  (avaliador *) malloc(sizeof(avaliador));

    a->pilha = create_stack();

    a->expressao = expressao;

    return a;
}

int avaliar(avaliador *a){
    char c;
    for (c = *(a->expressao); c != '\0'; c = *(++(a->expressao)))
    {
        switch (c)
        {
        case '(':

            push(a->pilha, c);
            break;

        case ')':

            if (empty_stack(a->pilha))
                return FALSE;

            if (a->pilha->top->info == '(')
                pop(a->pilha);

            break;
        case '[':

            push(a->pilha, c);
            break;

        case ']':

            if (empty_stack(a->pilha))
                return FALSE;

            if (a->pilha->top->info == '[')
                pop(a->pilha);

            break;
        case '{':

            push(a->pilha, c);
            break; 

        case '}':  
            if (empty_stack(a->pilha))
                return FALSE;
            
            if (a->pilha->top->info == '{')
                pop(a->pilha);
            
            break;

        default:
            break;
        }
    }

    return (empty_stack(a->pilha));
}

void free_avaliador(avaliador **p){
    free_stack(&(*p)->pilha);
    free(*p);
}

