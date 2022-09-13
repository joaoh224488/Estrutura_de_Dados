#include <stdio.h>


int fibonacci(int n);

int main(){

    int n;
    n = 7;
    printf("O %d° termo da sequência de fibonnaci é:    %d\n", n, fibonacci(n));

    return 0;
}

int fibonacci(int n){

    int a, b, c;

    a = 1;
    b = 1;

    for (int i = 1; i < n; i++){
        c = a + b;
        a = b;
        b = c;
    }

    return a;

}