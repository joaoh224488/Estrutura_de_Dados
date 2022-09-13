#include <stdio.h>


void deriva(double *poli, int grau, double *out);

void show(int n, double *vet){
    int i;
    putchar('[');
    for (i = 0; i< n - 1; i++){
        printf(" %.2lf ,", vet[i]);
    }
    printf(" %.2lf ]\n", vet[n -1]);
}

int main(){

    double poli[] = {4, 2, -3, 4};

    show(4, poli);

    double out[3];

    deriva(poli, 3, out);

    show(3, out);


    return 0;
}

void deriva(double *poli, int grau, double *out){

    int i, j, multi;

    for (i = 0; i < grau ; i++){
        out[i] = poli[i] * (grau - i);
    }

    out[grau - 1] = poli[grau - 1];
}