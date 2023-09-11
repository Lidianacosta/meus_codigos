#include <stdio.h>
#include <stdlib.h>
#include "tentativa01.c"

int main(void){

    Lista* l = lst_cria();
    lst_insere(l,23);
    lst_insere(l,45);
    lst_imprime(l);
    int verifica = lst_pertence(l,23);

    if (verifica == 1){
        printf("pertenceeee\n");
    }else {
        printf("nao pertence\n");
    }
    
    return 0;
}
