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
    int op, i = 0, count, cont_alunos, mat;
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
            if (i < MAX_TURMAS)
            {
                printf("digite o id da turma que deseja cadastrar: ");
                scanf(" %c", &id);
                
                turmas[i] = cria_turma(id);
            }
            else
            {
                printf("nao ha mais vagas para criar turmas\n");
            }

            break;
        case 2:

            break;
        case 3:
            printf("digite o id da  turma que deseja cadastrar o aluno: ");
            scanf(" %c", &id);
            for (count = 0; count < MAX_TURMAS; count++)
            {
                if (turmas[count]->id == id)
                {
                    printf("digite a matricula do aluno: ");
                    scanf("%d", &mat);

                    for (cont_alunos = 0; cont_alunos < MAX_VAGAS; cont_alunos++)
                    {
                        {
                            if (turmas[count]->alunos[cont_alunos] == NULL)
                            {
                                turmas[count]->alunos[cont_alunos]->mat = mat;
                                matricula_aluno(turmas[count], turmas[count]->alunos[cont_alunos]->mat, turmas[count]->alunos[cont_alunos]->nome);
                            }
                            else
                            {
                                printf("nao a mais vagas para cadastra o aluno na turma");
                            }
                        }
                    }
                }
                else
                {
                    printf("Turma inexistente!\n");
                }
            }

            break;
        case 4:

            break;
        case 5:
        imprime_turmas(turmas, i);

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
   // ERRO COMEÇA A AQUI !
   (*turma).id = id;
  
    
    turma->vagas = MAX_VAGAS;
    for (count = 0; count < MAX_VAGAS; count++)
    {
        turma->alunos[count] = NULL;
    }
    printf("Turma %c criada com sucesso!", id);
    return &(*turma);
}

void matricula_aluno(Turma *turma, int mat, char *nome)
{
    printf("digite o nome do aluno : ");
    scanf(" %[^\n]s", nome);
}

void lanca_notas(Turma *turma)
{
}
void imprime_alunos(Turma *turma)
{
}

void imprime_turmas(Turma **turmas, int n){
 int i,count_alunos,count_notas;
    for(i = 0; i < n; i++)
    {
        printf("TURMAS: \n");
        //printf("Turma: %s",turmas[i]->id);
        for(count_alunos = 0; count_alunos < MAX_VAGAS; count_alunos++){
             printf("aluno : %s",turmas[i]->alunos[count_alunos]->nome);
          for(count_notas = 0; count_notas < 3; count_notas++){
             printf("notas: %.2f",turmas[i]->alunos[count_alunos]->notas[count_notas]);
        }
        printf("media: %.2f",turmas[i]->alunos[count_alunos]->media);
        }
       // printf("");
        //printf("");
    }
}

Turma *procura_turma(Turma **turmas, int n, char id)
{
}
