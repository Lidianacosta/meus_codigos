#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

int main(void){
    Lista* l = lst_cria();
    Lista* l1 = lst_cria();

    int elementos_maiores;
    Lista* ult;

    l = lst_insere(l,20);
    l = lst_insere(l,23);
    l = lst_insere(l,5);
    printf("l\n");
    lst_imprime(l);
    l1 = lst_insere(l1,52);
    l1 = lst_insere(l1,41);
    l1 = lst_insere(l1,23);
    printf("l1\n");
    lst_imprime(l1);
    elementos_maiores = maiores(l,10);
    printf("são %d elementos maiores que %d\n",elementos_maiores,10);
    ult = ultimo(l);
    printf("o ultimo elemento é %d\n",ult->info);
    concatena(l,l1);
    lst_imprime(l);
    l = retira_n(l,23);
    lst_imprime(l);

    return 0;
}