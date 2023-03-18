#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

typedef struct aluno{
  char nome[5];
  float nota;
}Aluno;

Aluno* aluno_cria(char* nome, float nota){
  Aluno* novo_aluno =(Aluno*)malloc(sizeof(Aluno));
  if(novo_aluno == NULL){
    printf("erro\n");
    exit(1);
  }
  strcpy(novo_aluno->nome,nome);
  novo_aluno->nota = nota;
  printf("Aluno cadastrado com sucesso\n");
  return (novo_aluno);
}

void aluno_libera(Aluno* a){
  free(a);
}

void aluno_imprime(Aluno* a){
  printf("%s: %.2f\n",a->nome, a->nota);
}

void aluno_ordena(int n, Aluno** v); 

void aluno_salva(FILE* fp, int n, Aluno** v){
  int i;
  for(i=0; i<n; i++){
   fprintf(fp, "%s: %.2f\n", v[i]->nome, v[i]->nota);
  }
}