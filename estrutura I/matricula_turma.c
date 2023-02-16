#include <stdio.h>
#include <stdlib.h>

#define MAX_VAGAS 3
#define MAX_TURMAS 2

typedef struct aluno
{
    int mat;
    char nome[50];
    float notas[3];
    float media;
} Aluno;

typedef struct turma
{
    char id;
    int vagas;
    Aluno *alunos[MAX_VAGAS];

} Turma;

//=======================================================
//                    funções
Turma *cria_turma(char id);

void menu(void);

void imprime_turmas(Turma **turmas, int n);

// void matricula_aluno(Turma *turma, int mat, char *nome);

// void lanca_notas(Turma *turma);

// void imprime_alunos(Turma *turma);



Turma *procura_turma(Turma **turmas, int n, char id);

//========================================================

int main()
{
    int op, i = 0, count, cont_alunos, mat;
    

    Turma **turmas = (Turma **)malloc(MAX_TURMAS * sizeof(Turma *));

    for (count = 0; count < MAX_TURMAS; count++)
    {
        turmas[count] = (Turma *)malloc(MAX_VAGAS * sizeof(Turma));
    }

    do
    {
        menu();
        printf("digite sua opção: ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:
            if (i < MAX_TURMAS)
            {
                printf("digite o id da turma que deseja cadastrar: ");
                scanf(" %c", &turmas[i]->id);
                turmas[i] = cria_turma(turmas[i]->id);
            } 
            else
            {
                printf("nao ha mais vagas para criar turmas\n");
            }
            break;
        case 2:
                    imprime_turmas(turmas,i);
            break;

        }
        i++;
    } while (op != 6);

    for (count = 0; count < MAX_TURMAS; count++)
    {
        free(turmas[count]);
    }

    free(turmas);
    return 0;
}
//=======================================
//                funções
void menu(void)
{
    printf("\nMENU:\n");
    printf("1 – Criar turma\n");
    printf("2 – Listar turmas\n");
    printf("3 – Matricular aluno\n");
    printf("4 – Lancar notas\n");
    printf("5 – Listar alunos\n");
    printf("6 – Sair\n");
}

Turma *cria_turma(char id)
{
    int count;   
    Turma turma;   
    // turma.vagas = MAX_VAGAS;
    // for (count = 0; count < MAX_VAGAS; count++)
    // {
    //      turma.alunos[count] = NULL;
    // }

    // turma.vagas = MAX_VAGAS;
    // turma.id = id;

    printf("Turma %c criada com sucesso!", id);
    return(&turma);
}

void imprime_turmas(Turma **turmas, int n){
 int i,count_alunos,count_notas;
     printf("TURMAS: \n");
    for(i = 0; i < n; i++)
    {
        printf("%c\n",turmas[i]->id);
        printf("%d\n",turmas[i]->vagas);
    }
}
