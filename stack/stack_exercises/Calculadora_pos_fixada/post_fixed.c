
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

int calc_result(post_fixed *c, char * expression){
    int v, sign;
    char carac;

    // *(++ expression) foi usado porque, do contrário, o
    // caractere salvo não avançaria da forma esperada, retornando valores anteriores.

    for (carac = *expression; carac != '\0'; carac = *(++expression))
    {   
        sign = 1;       // sinal é inicializado positivo

        // if para verificar se deve passar para o próximo caractere
        if (carac == ' '){
            continue;
        }

        // if para verificar numeros negativos
        if (carac == '-' && ( *(expression + 1) >= '0' && *(expression + 1) <= '9')){
            v = 0;
            carac = *(++expression); // pula o sinal de negativo
            sign = -1; // sinal de negativo
        }

        // if para verificar se o caractere é um número e salvar o valor na variável v
        if (carac >= '0' && carac <= '9'){
            v = 0;
            while (carac >= '0' && carac <= '9'){
                v = v * 10 + (carac - '0');
                carac = *(++expression);
            }
            v *= sign; // aplica o sinal de negativo se necessário
            calc_operand(c, v);        // adicona o número na pilha
          
        }
        // fora das possibilidades anteriores, o caractere pode ser um operador
        // ou um caractere inválido (dentro de calc_operator há uma proteção contra isso)
        else{
            calc_operator(c, carac);
           
        }
    }

    return pop(c->p); // retorna o resultado da expressão
}

void free_post_fixed(post_fixed **c){
    free_stack(&(*c)->p);
    free(*c);
    printf("Calculator freed.\n");
}


