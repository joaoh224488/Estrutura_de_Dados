#include "post_fixed.h"



int main(){

    post_fixed *calculator;

    int value;

    char *expression = "20 -35 + 4 *8 - -2 /";

    calculator = create_post_fixed();


    if (!calculator){
        printf("Error creating calculator.\n");
        exit(1);
    }


    value = calc_result(calculator, expression);
    
    putchar('\n');
    printf("Result: %d\n\n", value);

    free_post_fixed(&calculator);


    return 0;
}