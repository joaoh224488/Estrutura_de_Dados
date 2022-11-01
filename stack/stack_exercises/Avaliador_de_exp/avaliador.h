#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/*
O presente avaliador de expressões foi criado 
*/

struct node
{
    char info;
    struct node *next;
};

typedef struct node node;


struct stack
{
    node * top;
};

typedef struct stack stack;



int push(stack * p, char v);

int pop(stack *p);

int empty_stack(stack *p);

stack * create_stack();
void free_stack(stack **p);

struct avaliador
{
    stack *pilha;
    char *expressao;
    int resultado;
};
typedef struct avaliador avaliador;

avaliador * create_avaliador(char *expressao);
int avaliar(avaliador *a);
void free_avaliador(avaliador **p);
