#include <stdio.h>

void minusculo(char *str);

int main(){

    char palavra[] = "BaNAna";

    minusculo(palavra);

    printf("%s\n", palavra);

    return 0;
}
// LEMBRAR SEMPRE QUE 'a' é maior que  'A'
void minusculo(char *str){
    int i;

    for (i = 0; str[i] != '\0'; i++){
        if((str[i] >= 'A') && (str[i]<= 'Z'))

            str[i] = str[i] + 'a' - 'A';
    }
}
