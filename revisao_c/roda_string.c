#include <stdio.h>
#include <stdlib.h>

char* roda_string(char *);

int main(){

    char palavra[] = "Joao";

    char *new;

    new = roda_string(palavra);

    printf("%s\n", new);

    free(new);


    return 0;
}

char* roda_string(char *str){

    int i, cont;
    char *nova_string;

    for (cont = 0; str[cont] != '\0';)
        cont++;

    nova_string = (char *) malloc(sizeof(char) * cont);

    if (!nova_string){
        printf("Alocação falhou.\n");
        exit(1);
    }

    nova_string[0] = str[cont - 1];

    for (i = 2; i <= cont; i++){
        nova_string[i - 1] = str[(cont + i) % (cont - 1)];
    }

    return nova_string;
}