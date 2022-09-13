#include <stdio.h>

#define TRUE 1
#define FALSE 0

int primo (int n);

int main(){

    for (int n = 0; n < 20; n++){

        if (primo(n))
            printf("O número %d é primo.\n", n);
        else
            printf("O número %d não é primo.\n", n);
    }

    return 0;
}

int primo(int n){

    int n_div = 0;

    for (int i = 1; i <= n; i++){

        if ((n % i) == 0)
            n_div++; 
    }

    if (n_div == 2){
        return TRUE;
    }


    return FALSE;
}