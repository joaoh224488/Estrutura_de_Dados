#include <stdio.h>
#include <stdlib.h>

char* save_word(int n);
void show_word(char *word);

int main(){
    char **nomes;
    int membros, size, i, j, k;

    membros = 3;
    nomes = (char **) malloc(membros * sizeof(char *));


    if (!nomes){
        printf("Erro - abortando\n");
        exit(1);
    }

    for (i = 0; i < membros; i++){
        printf("Digite o tamanho do nome: \n");
        scanf("%d", &size);
        printf("Digite o nome:  \n");
        nomes[i] = save_word(size + 1);
    }

    for (j = 0; j < membros; j++){
        show_word(nomes[j]);
    }
    
    printf("\n");

    for (k = 0; k < membros; k++){
        free(nomes[k]);
    }
    free(nomes);

    return 0;
}

char* save_word(int n){
    char *str;
    str = (char*) malloc(n * sizeof(char));
    if (!str){
        printf("Erro - abortando\n");
        exit(1);
    }
    
    scanf("%s", str);

    return str;
}

void show_word(char *word){

    int cont;
    cont = 0;
    while (word[cont] != '\0'){
        putchar(word[cont++]);
    
    }

    putchar('\n');
}


