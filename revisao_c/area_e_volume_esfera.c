#include <stdio.h>

void calc_esfera(float r, float *area, float *volume);

#define pi 3.14

int main(){

    float area, vol, r;
    r = 5;
    calc_esfera(r, &area, &vol);

    printf("A área da esfera com raio %f é %f e o volume é %f\n", r, area, vol);
    return 0;
}

void calc_esfera(float r, float *area, float *volume){


    *area = 4 * pi * r * r;

    *volume = (float) (4 * pi * r * r * r) / 3;
}