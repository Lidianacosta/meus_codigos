#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

int main(){

    No* l = lst_cria();
    No* achou;
    l = lst_insere_ordenada(l,74);
    l = lst_insere_ordenada(l,100);
    l = lst_insere_ordenada(l,20);
    l = lst_insere_ordenada(l,40);
    l = lst_retira(l,74);
    lst_imprime(l);
    achou = lst_busca(l,100);
    printf(" achou = %d\n",achou->info);
    return 0;
}
