#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct listano ListaNo;

struct listano{
    int info;
    ListaNo* prox;
};

struct lista{
    ListaNo* prim;
};

Lista* lst_cria (void){
    Lista* l = (Lista*)malloc(sizeof(Lista));
    l->prim = NULL;
    return l;
}

void lst_insere (Lista* l, int v){
    ListaNo* novo = (ListaNo*)malloc(sizeof(ListaNo));
    novo->info = v;
    novo->prox = l->prim;
    l->prim = novo;
}

void lst_imprime (Lista* l){
    for (ListaNo* p = l->prim; p != NULL; p = p->prox){
        printf("info = %d\n", p->info);
    }    
}

int lst_pertence (Lista* l, int v){
     for (ListaNo* p = l->prim; p != NULL; p = p->prox){
        if (p->info == v){
            return 1;
        }
    }
    return 0;
}

void lst_insere_ordenado (Lista* l, int v){
    ListaNo* ant = NULL;
    ListaNo* p = l->prim;

    while (p != NULL && p->info < v){
        ant = p;
        p = p->prox;
    }

    ListaNo* novo = (ListaNo*)malloc(sizeof(ListaNo));

    if (ant == NULL){
        novo->prox = l->prim;
        l->prim = novo;
    }
    else
    {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
}

void lst_retira (Lista* l, int v){
    ListaNo* ant = NULL;
    ListaNo* p = l->prim;

    while (p != NULL){
        ant = p;
        p = p->prox; 
    }
    
}
