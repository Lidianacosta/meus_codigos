#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(void) {
  Matriz* mat = mat_cria(3,3);
  mat_atribui(mat,2,2,5);
  printf("%.2f\n", mat_acessa(mat,2,2));
  printf("tem %d linha/as\n",mat_linhas(mat));
  printf("tem %d coluna/as\n",mat_colunas(mat));
  mat_libera(mat);
  return 0;
}