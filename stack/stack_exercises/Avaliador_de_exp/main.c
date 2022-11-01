#include "avaliador.h"


int main(){
    int resultado;
    char *expressao;

    printf("Digite a expressao: ");
    scanf("%s", expressao);

    // "{[2+3]*4}+5"

    // Cria o avaliador
    avaliador *a = create_avaliador(expressao);

    resultado = avaliar(a);
    if (resultado)
        printf("Expressao correta\n");
    else
        printf("Expressao incorreta\n");
}