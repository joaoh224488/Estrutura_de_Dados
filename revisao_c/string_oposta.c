#include <stdio.h>

void string_oposta(char *str);

int main(){

    char palavra[] = "z";

    string_oposta(palavra);

    printf("%s\n", palavra);

    return 0;
}

void string_oposta(char *str){


    int i;

    for (i = 0; str[i] != '\0'; i++){

    if ((('A' <= str[i]) && ('Z' > str[i])))
    
        str[i] = 'Z' - (str[i] - 'A');
    else if (('a' <= str[i]) && ('z' > str[i]))
        str[i] = 'z' - (str[i] - 'a');
}
}