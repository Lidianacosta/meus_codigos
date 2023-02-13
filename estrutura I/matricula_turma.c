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

void matricula_aluno(Turma *turma, int mat, char *nome);

void lanca_notas(Turma *turma);

void imprime_alunos(Turma *turma);

void imprime_turmas(Turma **turmas, int n);

Turma *procura_turma(Turma **turmas, int n, char id);

//========================================================

int main()
{
    int op, i, count;
    char id;

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
            printf("digite o id da turma que deseja cadastrar: ");
            scanf(" %c", turmas[i]->id);
            turmas[i] = cria_turma(turmas[i]->id);

            break;
        case 2:

            break;
        case 3:
            printf("digite o id da  turma que deseja cadastrar o aluno: ");
            scanf(" %c", &id);
            printf("digite a matricula do aluno: ");
            scanf("%d", turmas[i]->alunos[i]->mat);
            printf("digite o nome do aluno: ");
            scanf(" %[^\n]s", turmas[i]->alunos[i]->nome);
            matricula_aluno(turmas, turmas[i]->alunos[i]->mat, turmas[i]->alunos[i]->nome);
            break;
        case 4:

            break;
        case 5:

            break;
        }

        ++i;
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
    printf("MENU:\n");
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
    Turma *turma;
    turma->id = id;
    turma->vagas = NULL;
    for (count = 0; count < MAX_VAGAS; count++)
    {
        turma->alunos[count] = NULL;
    }
    printf("Turma %c criada com sucesso!", id);
    return (turma);
}

void matricula_aluno(Turma *turma, int mat, char *nome)
{
    turma

}

void lanca_notas(Turma *turma)
{
}
void imprime_alunos(Turma *turma)
{
}

void imprime_turmas(Turma **turmas, int n)
{
}

Turma *procura_turma(Turma **turmas, int n, char id)
{
}