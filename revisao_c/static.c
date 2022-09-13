#include <stdio.h>

void show(int );

int main(){

    int n = 20;

    for (int i = 0; i <= n; i ++){
        show(i);
    }


    return 0;
}


void show(int a){
    static int n = 1;
    printf("  %.2d  ", a);

    if ((n % 5) == 0) printf("\n");
    n++;
}