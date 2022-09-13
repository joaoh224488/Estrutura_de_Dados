#include <stdio.h>

double avalia(double *poli, int grau, double x);

int main(){

    double poli[] = {12, 2, 3}, x = 2;

    printf("O valor do polinômio em %.2lf é:  %.2lf\n", x,  avalia(poli, 2, x));



    return 0;
}


double avalia(double *poli, int grau, double x){
    int i, j;
    double soma, multi;

    soma = poli[0];

    for (i = 1; i <= grau; i++){
        
        multi = 1;

        for (j = 1; j <= i; j++){
            multi *= x;
        }

        soma += poli[i] * multi;

    }

    return soma;


}