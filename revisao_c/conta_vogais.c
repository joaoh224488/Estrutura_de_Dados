#include <stdio.h>

int conta_vogais(char *str);

int main(){

    char p[] = "Ana";

    printf("A quantidade de vogais é:   %d\n", conta_vogais(p));

    return 0;
}

int conta_vogais(char *str){

    int cont, i, j;
    char let;

    char letters[] = "aAbBcCdDeE";

    cont = 0;

    for (i = 0; str[i] != '\0';i++){

        let = str[i];
        for (j = 0; j < 10; j++){
            if (let == letters[j])
                cont++;
        }

    }
    
    return cont;
}