#include <stdio.h>

int fibonacci(int n){
    if (n == 1){
        return 1;
    }
    else if (n == 2){
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(){
    int n;
    n = 10;
    printf("O %d° elemento da sequencia de fibonacci é %d\n", n, fibonacci(n));
    return 0;
}