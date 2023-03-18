#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

#define QTD_ALUNOS 5

int main(void) {
  int cont_alunos;
  char nome[50];
  float nota;
  FILE* fp = fopen("saida.txt", "wt");
  if(fp == NULL){
    printf("erro ao abrir o arquivo\n");
    exit(1);
  }
  Aluno** alunos = (Aluno**)malloc(QTD_ALUNOS * sizeof(Aluno*));
  if(alunos == NULL){
    printf("sem armazenamento suficiente\n");
  exit(1);
  }
  for(cont_alunos=0; cont_alunos < QTD_ALUNOS; cont_alunos++){
    printf("digite o nome e a nota  do aluno %d°",cont_alunos+1);
    scanf(" %s %f", nome, &nota);
  alunos[cont_alunos] = aluno_cria(nome, nota);
  }

  for(cont_alunos=0; cont_alunos < QTD_ALUNOS; cont_alunos++){
    printf("nome e a nota  do aluno %d°\n",cont_alunos+1);
  
  aluno_imprime(alunos[cont_alunos]);  
  }

  aluno_salva(fp,QTD_ALUNOS,alunos);

  
  for(cont_alunos=0; cont_alunos<QTD_ALUNOS; cont_alunos++){
aluno_libera(alunos[cont_alunos]);
  }
  free(alunos);
  printf("programa finalizado\n");
  return 0;
}