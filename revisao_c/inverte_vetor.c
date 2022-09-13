#include <stdio.h>

void inverte(int n, int *vet);

void show(int n, int *vet);

int main(){
    int m[5] = {0, 1, 2, 3, 4};

    show(5, m);

    inverte(5, m);

    show(5, m);
    return 0;
}

void show(int n, int *vet){
    int i;
    putchar('[');
    for (i = 0; i< n - 1; i++){
        printf(" %d ,", vet[i]);
    }
    printf(" %d ]\n", vet[n -1]);
}

void inverte(int n, int *vet){

    int aux, i;

    for (i = 0; i < n / 2; i++){
        aux = vet[i];
        
        vet[i] = vet[n - 1 - i];

        vet[n - 1 - i] = aux;
    }
}