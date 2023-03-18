#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

typedef struct matriz{
  int lin;
  int col;
  float* v;
}Matriz;

/*typedef struct matriz {
  int lin;
  int col;
  float** v;
}Matriz;*/


Matriz* mat_cria(int m, int n){
  Matriz* nova_matriz = (Matriz*)malloc(sizeof(Matriz));
  nova_matriz->lin = m;
  nova_matriz->col = n;
 float* v = (float*)malloc(m*n*sizeof(float));
  nova_matriz->v = v;
  return(nova_matriz);
}

void mat_libera(Matriz* mat){
   free(mat->v);
   free(mat);
}

float mat_acessa(Matriz* mat, int i, int j){
  return(mat->v[i+j]);
}

void mat_atribui(Matriz* mat, int i, int j, float v){
  mat->v[i+j] = v;
}

int mat_linhas(Matriz* mat){
  return(mat->lin);
}

int mat_colunas(Matriz* mat){
  return(mat->col);
}
