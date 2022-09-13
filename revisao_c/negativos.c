#include <stdio.h>

int negativos(int n, float *vet);


int main(){

    float m[6] = {0, 1, -2, 3, 4, 5};

    printf("A quantidade de números negativos do vetor é %d\n", negativos(6, m));

}

int negativos(int n, float *vet){

    int cont, i;

    cont = 0;

    for (i = 0; i < n; i++){
        
        if (vet[i] < 0){
            cont++;
        }
    }

    return cont;
}