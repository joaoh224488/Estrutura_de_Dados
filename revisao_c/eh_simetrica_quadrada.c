#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int eh_simetrica_quadrada_alc_un(int *, int);
int eh_simetrica_quadrada_alc_di(int **, int);

int main(){

    int m[9] = {1, -2, 4, -2, 2, 0, 4, 0, 3},

        **p, n, i, j;

    n = 3;

    p = (int **) malloc(n * sizeof(int *));

    for (i = 0; i < n; i++){
        p[i] = (int *) malloc (n * sizeof(int));
    }



    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            p[i][j] = m[(i * n) + j];
        }
    }

                
    if (eh_simetrica_quadrada_alc_un(m, 3))
        printf("A matriz é simetrica quadrada\n");
    else
        printf("A matriz não é simetrica quadrada\n");


    if (eh_simetrica_quadrada_alc_di(p, 3))
        printf("A matriz é simetrica quadrada\n");
    else
        printf("A matriz não é simetrica quadrada\n");


    return 0;
}

int eh_simetrica_quadrada_alc_un(int *m, int n){
    int i, j;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (m[(i * n) + j] != m[(j * n) + i])
                return FALSE;
        }
    }
    return TRUE;

}

int eh_simetrica_quadrada_alc_di(int **m, int n){
    int i, j;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (m[i][j] != m[j][i])
                return FALSE;
        }
    }
    return TRUE;

}