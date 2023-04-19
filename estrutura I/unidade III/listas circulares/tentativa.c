#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista{
    int info;
    Lista* prox;
    Lista* ant;
};

Lista* lstc_cria(void){
    return NULL;
}

Lista* lstc_insere(Lista* l, int v){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if (novo){
        novo->info = v;
        if (l == NULL){
            novo->ant = novo;
            novo->prox = novo;
        }else{
            novo->ant = l->ant;
            novo->ant->prox = novo;
            l->ant = novo;
            novo->prox = l;
            
        }
    }
    return novo;
}

void lstc_imprime(Lista* l){
    Lista* p;
    for(p = l; p != NULL; p = p->prox){
        printf("info = %d\n", p->info);
    }
}

void lstc_imprime_circ(Lista* l){
    Lista* p = l;
    do{
        printf("info = %d\n", p->info);
        p = p->prox;
    } while (p!= l);
}

// #include <stdio.h>
// #include "lista.c"

int main(void){
    Lista* l = lstc_cria();

    l = lstc_insere(l,1);
    l = lstc_insere(l,2);
    l = lstc_insere(l,3);
    l = lstc_insere(l,4);
    l = lstc_insere(l,5);

    //lstc_imprime(l);
    lstc_imprime_circ(l);
    return 0;
}
