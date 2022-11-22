#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0

typedef struct 
{
    int x;
    int y;
}Ponto;

int dentroRet(Ponto *v1, Ponto *v2, Ponto *p);

int main(){

    Ponto v1;
    Ponto v2;
    Ponto p;

    v1.x = 2;
    v2.y = 0;

    v2.x = 5;
    v2.y = 5;

    p.x = 3;
    p.y = 2;


    if(dentroRet(&v1, &v2, &p))
        printf("O ponto está no retângulo\n");
    else
        printf("O ponto não está no retângulo\n");

    return 0;
}

int dentroRet(Ponto *v1, Ponto *v2, Ponto *p){

    if (((v1->x <= p->x) && (p->x <= v2->x)) && ((v1->y <= p->y) && (p->y <= v2->x)))
        return TRUE;
    
    else 
        return FALSE;
}