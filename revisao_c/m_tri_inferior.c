#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct
{
    int size;
    int *vet;
} Matriz_triangular_inferior;

void set_in_matrix(Matriz_triangular_inferior *m, int i, int j, int v){
    if ((i >= m->size)|| (j >= m->size))
        printf("Elemento excede o tamanho da matriz\n");
    else if (j > i)
        printf ("O valor da linha %d e coluna%d é 0.\n", i , j);
    
    else
        m->vet[j + i * (i + 1)/2] = v;

}

int get_in_matrix(Matriz_triangular_inferior *m, int i, int j, int v){
    if (j > i)
        return 0;
    else
        return m->vet[j + i * (i + 1)/2] = v;

}
// i * (i + 1)/2 é a quantidade de elementos das linhas anteriores
void exibir_matriz(Matriz_triangular_inferior *m){
    int i, j, ind;
    for(i = 0; i < m->size; i++){
        for (j = 0; j < m->size; j++){
            if (j > i){
                printf("%d, ", 0);
            }
            else{
                ind = j + i * (i + 1)/2;
                
                printf("%d  ", m->vet[ind]);
            }
        }
        putchar('\n');
    }
}

int main(){

    int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9 , 10}, size = 4;

    Matriz_triangular_inferior *m;

    m = (Matriz_triangular_inferior *) malloc(sizeof(int) + size * sizeof(int));
    
    m->size = size;
    m->vet = vet;


    exibir_matriz(m);

    free(m);


    return 0;
}