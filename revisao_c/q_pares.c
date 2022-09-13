#include <stdio.h>

int q_pares(int n, int *vet);

int main(){

    int m[6] = {0, 1, -2, 3, 4, 5};

    printf("A quantidade de números pares do vetor é %d\n", q_pares(6, m));


    return 0;
}

int q_pares(int n, int *vet){
    int i, cont;
    cont = 0;
    
    for (i = 0; i < n; i++){
        if (vet[i] % 2 == 0){
            cont++;
        }
    }
    return cont;
}