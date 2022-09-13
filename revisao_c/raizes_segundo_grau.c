#include <stdio.h>
#include <math.h>

int raizes(float a, float b, float c, float *x1, float *x2);

int main(){

    float a, b, c, x1, x2;
    int control;

    a = 1;
    b = -1;
    c = -2;
    control = raizes(a, b, c, &x1, &x2);

    printf("A equação %fx² + %fx + %f tem %d raízes:   \n", a, b, c, control);
    if (control)
        printf("x1:    %f          x2:    %f\n", x1, x2);
    else
    printf("A função não tem raízes reais.\n");

    return 0;
}

int raizes(float a, float b, float c, float *x1, float *x2){

    float delta;

    delta = (b * b) - 4 * a * c;

    if (delta < 0){
        return 0;
    }

    *x1 = (double) (-b + sqrt(delta)) / (2 * a); 

    *x2 = (double) (-b - sqrt(delta)) / (2 * a); 

    printf("%f", delta);

    if (delta == 0){
        return 1;
    }
    else if (delta > 0){
        return 2;
    }
    
}