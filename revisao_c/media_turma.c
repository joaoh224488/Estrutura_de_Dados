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


float media_turma(int n, Aluno ** turmas, char turma);

int main(){
    char turma;
    float media;

    Aluno a1;
    Aluno a2;
    Aluno a3;
    Aluno a4;
    Aluno a5;

    strcpy(a1.nome, "Joao Henrique");
    strcpy(a1.matricula, "20210026705");
    a1.turma = 'A';
    a1.p1 = 10;
    a1.p2 = 10;
    a1.p3 = 10;


    strcpy(a2.nome, "Eduardo Gonçalves");
    strcpy(a2.matricula, "20171710006");
    a2.turma = 'A';
    a2.p1 = 6;
    a2.p2 = 4;
    a2.p3 = 5;

    strcpy(a3.nome, "Eufrazino");
    strcpy(a3.matricula, "20171710014");
    a3.turma = 'A';
    a3.p1 = 7;
    a3.p2 = 7;
    a3.p3 = 7;

    strcpy(a4.nome, "Franz");
    strcpy(a4.matricula, "20171710001");
    a4.turma = 'B';
    a4.p1 = 8;
    a4.p2 = 9;
    a4.p3 = 10;

    strcpy(a5.nome, "Micael");
    strcpy(a5.matricula, "20171710005");
    a5.turma = 'B';
    a5.p1 = 5;
    a5.p2 = 5;
    a5.p3 = 5;




    Aluno *turmas[5]; // PRECISA SER ESCRITO ASSIM PARA QUE AS STRUCTS SEJAM CONTÍGUAS

    turmas[0] = &a1;
    turmas[1] = &a2;
    turmas[2] = &a3;
    turmas[3] = &a4;
    turmas[4] = &a5;

    turma = 'B';
    media = media_turma(5, turmas, turma);


    printf("A média da turma %c é %.2f.\n", turma, media);

    return 0;
}

float media_turma(int n, Aluno ** turmas, char turma){
    int i, cont;
    float med;

    cont = 0;
    med = 0.0;
    
    for (i = 0; i < n; i++){
        if(turmas[i]->turma == turma){
            med += (turmas[i]->p1 + turmas[i]->p2 + turmas[i]->p3) / 3.00;
            printf("%f\n", med);
            cont++;
        }
    }

    med /= (float) cont;

    return med;
}
