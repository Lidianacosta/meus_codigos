#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no{
    int info;
    No* prox;
};


No* lst_cria(){
    return NULL;
}

No* lst_insere(No* l, int v){
    No* novo = (No*)malloc(sizeof(No));
    novo->info = v;
    novo->prox = l;
    return novo;
}

int lst_vazia(No* l){
    return(l == NULL);
}

void lst_imprime(No* l){
    No* p;
    for(p = l; p != NULL; p = p->prox){
        printf("info = %d\n",p->info);
    }
}

No* lst_busca(No* l, int elemento){
    No* p;
    for(p = l; p != NULL; p = p->prox){
        if (p->info == elemento){
            return p;
        }
    }
    return NULL;
}

No* lst_retira(No* l, int v){
    No* ant = NULL;
    No* p = l;

    while (p->info != v){
        if (p == NULL){
            return l;
        }

        ant = p;
        p = p->prox;
    }

    if (ant == NULL){
        l = p->prox;
    }
    else{
        ant->prox = p->prox;
    }

    free(p);
    return l;
}

void lst_libera(No* l){
    No* p  = l;
    No* t;

    while (p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }
}

No* lst_insere_ordenada(No* l, int v){
    No* novo;
    No* ant = NULL;
    No* p = l ;

    while (p != NULL && p->info <v){
        ant = p;
        p = p->prox;
    }

    novo = (No*)malloc(sizeof(No));
    novo->info = v;
    if (ant == NULL){
        novo->prox = l;
        l = novo; 
    }
    else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return l;
}
