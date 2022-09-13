#include <stdio.h>

double pi(int n);

int main(){

    int n;

    n = 10000000;

    printf("A aproximação de pi com %d termos é %lf\n", n, pi(n));

    return 0;
}

double pi(int n){

    double soma;
    int i, multi;

    soma = 1.0;

    for (i = 1; i < n; i++){
        if (i % 2 == 0){
            
            soma += 1.0/(2*i + 1);
        }
        else{
            soma -= 1.0/(2*i + 1);
        }
    } 
    printf("%lf\n", 4 * soma);

    return (4 * soma);
}