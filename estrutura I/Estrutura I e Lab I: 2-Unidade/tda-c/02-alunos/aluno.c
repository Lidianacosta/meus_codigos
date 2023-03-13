#include <stdio.h>
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
void aluno_ordena(int n, Aluno** v);
void aluno_salva(FILE* fp, int n, Aluno** v){
    fprintf(fp,"%s %.2f",(*v)->nome,(*v)->nome);
}
