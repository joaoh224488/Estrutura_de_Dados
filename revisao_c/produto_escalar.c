#include <stdio.h> 


typedef struct 
{
    double x;
    double y;
    double z;
}Vetor;

double dot(Vetor *v1, Vetor *v2);


int main(){

    Vetor A, B;

    A.x = 1;
    A.y = 1;
    A.z = 2;

    B.x = -2;
    B.y =  2;
    B.z =  2;

    printf("%lf\n", dot(&A, &B));

    return 0;
}

double dot(Vetor *v1, Vetor *v2){

    return (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);

}