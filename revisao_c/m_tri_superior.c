#include <stdio.h>


typedef struct
{
    int size;
    int *vet;
} Matriz_triangular_superior;


void set_in_matrix(Matriz_triangular_superior *m, int i, int j, int v){
    if ((i >= m->size)|| (j >= m->size))
        printf("Elemento excede o tamanho da matriz\n");
    else if (i > j)
        printf ("O valor da linha %d e coluna%d é 0.\n", i , j);
    
    else
        m->vet[i + j * (j + 1)/2] = v;

}

int get_in_matrix(Matriz_triangular_superior *m, int i, int j, int v){
    if (j > i)
        return 0;
    else
        return m->vet[i + j* (j + 1)/2] = v;

}
// i * (i + 1)/2 é a quantidade de elementos das linhas anteriores
void exibir_matriz(Matriz_triangular_superior *m){
    int i, j, ind;
    for(i = 0; i < m->size; i++){
        for (j = 0; j < m->size; j++){
            if (i > j){
                printf("%d, ", 0);
            }
            else{
                ind = i + j * (j + 1)/2;
                
                printf("%d  ", m->vet[ind]);
            }
        }
        putchar('\n');
    }
}

int main(){

    int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9 , 10}, size = 4;

    Matriz_triangular_superior *m;

    m = (Matriz_triangular_superior *) malloc(sizeof(int) + size * sizeof(int));
    
    m->size = size;
    m->vet = vet;


    exibir_matriz(m);

    free(m);


    return 0;
}