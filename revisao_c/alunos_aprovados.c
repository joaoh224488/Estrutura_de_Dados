#include <stdio.h>
#include <string.h>

struct aluno
{
    char nome[81];
    char matricula[8];
    char turma;
    float p1;
    float p2;
    float p3;
};

typedef struct aluno Aluno;

void imprime_aprovados(int n, Aluno ** turmas);

int main(){

    Aluno a1;
    Aluno a2;
    Aluno a3;
    strcpy(a1.nome, "Joao Henrique");
    strcpy(a1.matricula, "20210026705");
    a1.p1 = 10;
    a1.p2 = 10;
    a1.p3 = 10;


    strcpy(a2.nome, "Eduardo Gonçalves");
    strcpy(a2.matricula, "20171710006");
    a2.p1 = 6;
    a2.p2 = 4;
    a2.p3 = 5;

    strcpy(a3.nome, "Eufrazino");
    strcpy(a3.matricula, "20171710014");
    a3.p1 = 7;
    a3.p2 = 7;
    a3.p3 = 7;


    Aluno *turmas[3]; // PRECISA SER ESCRITO ASSIM PARA QUE AS STRUCTS SEJAM CONTÍGUAS

    turmas[0] = &a1;
    turmas[1] = &a2;
    turmas[2] = &a3;

    imprime_aprovados(3, turmas);

    return 0;
}

void imprime_aprovados(int n, Aluno ** turmas){
    int i;
    float med;

    for (i = 0; i < n; i++){
        med = (float) (turmas[i]->p1 + turmas[i]->p2 + turmas[i]->p3) / 3.00;
        if (med >= 7){
            printf("O aluno %s, matrícula %s, foi aprovado com média %f\n", turmas[i]->nome, turmas[i]->matricula, med);
        }
    }
}
