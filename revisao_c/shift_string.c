#include <stdio.h>

void shift_string(char *str);

int main(){

    char palavra[] = "CAZA";

    shift_string(palavra);

    printf("%s\n", palavra);

    return 0;
}

void shift_string(char *str){


    int i;

    for (i = 0; str[i] != '\0'; i++){

        if ((('A' <= str[i]) && ('Z' > str[i])) || (('a' <= str[i]) && ('z' > str[i])))
        
            str[i] = str[i] + 1;

        else if (str[i] == 'Z')
            str[i] = 'A';
        
        else if (str[i] == 'z')
            str[i] = 'a';

    }

}