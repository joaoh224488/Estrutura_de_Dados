#include <stdio.h>

int conta_char(char *str, char c);

int main(){

    char p[] = "Amanda";

    printf("A quantidade do carcactere é:  %d \n", conta_char(p, 'a'));


    return 0;
}

int conta_char(char *str, char c){
    int i, cont;
    
    cont = 0;

    for (i = 0; str[i] != '\0'; i++){

        if (str[i] == c){
            cont ++;
        }
    } 
    return cont;
}