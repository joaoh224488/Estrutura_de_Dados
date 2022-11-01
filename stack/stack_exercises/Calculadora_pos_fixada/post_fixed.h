#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/*
    * A presente implementação de uma calculadora pós-fixada utiliza dentro da estrutura da 
    pilha uma Lista encadeada. Tendo em vista que, sendo uma pilha, a inserção e remoção de
    elementos ocorrem sempre no mesmo lugar, com o topo sendo substituído pelo elemento seguinte dentro
    dela. Ou seja, a única preocupação é com o topo da pilha, e, após o topo ser removido, com o novo topo 
    que é o elemento seguinte. Portanto, a lista encadeada é a estrutura mais adequada para a implementação
    desta pilha.
*/

/*
    Sobre a calculadora em si: ela recebe uma expressão pós-fixada como parâmetro, e a avalia, retornando
    o resultado da expressão. A expressão deve ser passada como uma string, e os operandos e operadores
    devem ser separados por espaços. Exemplo: "2 3 + 4 * 8 - 2 /". A calculadora é capaz de realizar as
    operações de soma, subtração, multiplicação e divisão inteira de número inteiros.

    A calculadora é capaz de realizar operações com números negativos, e também com números de mais de um
    dígito (ex: 123). Porém, ela não é capaz de realizar operações com números decimais.
*/
struct node
{
    int info;
    struct node *next;
};

typedef struct node node;


struct stack
{
    node * top;
};

typedef struct stack stack;



int push(stack * p, int v);

int pop(stack *p);

int empty_stack(stack *p);

stack * create_stack();
void free_stack(stack **p);


struct post_fixed{
    stack * p;
};

typedef struct post_fixed post_fixed;

post_fixed * create_post_fixed();

void calc_operand(post_fixed *c, int v);

void calc_operator(post_fixed *c, char op);

void free_post_fixed(post_fixed **c);



