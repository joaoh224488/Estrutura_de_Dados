#include <stdio.h>

int soma_impares(int n);



int main(){

    int n;
    n = 6;

    printf("A soma dos %d primeiros números ímpares é:  %d\n", n, soma_impares(n));

    return 0;
}

int soma_impares(int n){

    int i, soma;

    soma = 0;

    for (i = 0; i < n; i++){
        soma += 1 + 2 * i;
    }

    return soma;
}