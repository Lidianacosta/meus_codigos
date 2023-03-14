#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct aluno{
    char nome[50];
    float nota;
}Aluno;

Aluno* aluno_cria(char* nome, float nota){
    Aluno* novo_aluno = (Aluno*)malloc(sizeof(Aluno));
    if (novo_aluno == NULL){
        printf("erro!\n");
    }
    strcpy(novo_aluno->nome,nome);
    novo_aluno->nota = nota;
    return(novo_aluno);
}
void aluno_libera(Aluno* a){
    free(a);
}

void aluno_imprime(Aluno* a){
    printf("Dados:\nnome: %s\nnota: %.2f",a->nome,a->nota);
}

// int compararNome(const void *a, const void *b){
//     return(strcmp(((Aluno *)a)->nome,((Aluno *)b)->nome));
// }

// void aluno_ordena(int n, Aluno** v){
//       qsort(v, 5, sizeof(Aluno), compararNome);
// }
void aluno_salva(FILE* fp, int n, Aluno** v){
    int i;
    for(i = 0; i < n; i++){
        fprintf(fp, "%s\t%.2f\n", (*v)->nome, (*v)->nota);
    }
}

Aluno *procura_Aluno(Aluno **alunos,int n, char nome)    // uma funçao que ajuda a achar uma turma pelo seu id 
{
    int cont_alunos;

    for (cont_alunos = 0; cont_alunos < n; cont_alunos++){   // verifica se o id dado é igual ao da turma 
        if (strcmp(alunos[cont_alunos]->nome,nome) == 0){
            return (alunos[cont_alunos]); // retorna a turma encontrada 
        }
    }
    return (NULL);  // retorna null se nao for encontrada a turma 
}

