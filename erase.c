#include <stdio.h>

typedef struct 
{
    int vet[5];
    int ctrl;
} Lista;
void show(Lista l){
    int i;
    for (i = 0; i <= l.ctrl; i++){
        printf("%d  ", l.vet[i]);
    }
    putchar('\n');
}

int main(){
    int i, j, aux;
    Lista l = {{8, 4, 11, 7, 0}, 4};

    show(l);

    printf("-----------------------------------------------------\n");

    for(i = 0; i < l.ctrl - 1; i ++){
        for (j = i + 1; j <= l.ctrl; j++)
            if(l.vet[j] < l.vet[i]){
                aux = l.vet[i];
                l.vet[i] = l.vet[j];
                l.vet[j] = aux;

                show(l);
                printf("%d e %d\n", i , j);
            }
    }

    return 0;
}