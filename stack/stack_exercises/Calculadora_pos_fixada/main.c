#include "post_fixed.h"



int main(){

    post_fixed *calculator;

    int v, sign;

    char c;

    char *expression = "20 -35 + 4 *8 - 2 /";

    calculator = create_post_fixed();


    if (!calculator){
        printf("Error creating calculator.\n");
        exit(1);
    }

    // *(++ expression) foi usado porque, do contrário, o
    // caractere salvo não avançaria da forma esperada, retornando valores anteriores.



    for (c = *expression; c != '\0'; c = *(++expression))
    {   
        sign = 1;       // sinal é inicializado positivo

        // if para verificar se deve passar para o próximo caractere
        if (c == ' '){
            continue;
        }

        // if para verificar numeros negativos
        if (c == '-' && ( *(expression + 1) >= '0' && *(expression + 1) <= '9')){
            v = 0;
            c = *(++expression); // pula o sinal de negativo
            sign = -1; // sinal de negativo
        }

        // if para verificar se o caractere é um número e salvar o valor na variável v
        if (c >= '0' && c <= '9'){
            v = 0;
            while (c >= '0' && c <= '9'){
                v = v * 10 + (c - '0');
                c = *(++expression);
            }
            v *= sign; // aplica o sinal de negativo se necessário
            calc_operand(calculator, v);        // adicona o número na pilha
          
        }
        // fora das possibilidades anteriores, o caractere pode ser um operador
        // ou um caractere inválido (dentro de calc_operator há uma proteção contra isso)
        else{
            calc_operator(calculator, c);
           
        }
    }
    putchar('\n');
    printf("Result: %d\n\n", pop(calculator->p));

    free_post_fixed(&calculator);


    return 0;
}