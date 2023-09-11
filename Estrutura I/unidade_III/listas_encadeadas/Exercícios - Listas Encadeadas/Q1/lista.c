#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista{
    int info;
    Lista* prox;
};

Lista* lst_cria(){
    return NULL;
}

Lista* lst_insere(Lista* l, int n){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = n;
    novo->prox = l;
    return novo;
}

void lst_imprime(Lista* l){
    Lista* p;

    for(p = l; p != NULL; p = p->prox){
        printf("info = %d\n", p->info);
    }
}

int maiores(Lista* l, int n){
    Lista* p;
    int soma = 0;

    for(p = l; p != NULL; p = p->prox){
        if(p->info > n) soma++;
    }
    return soma;
}

Lista* ultimo(Lista* l){
    Lista* p = l;
    Lista* ultimo = NULL; 
    while(p != NULL){
        ultimo = p;
        p = p->prox;
    }
    return ultimo;
}

void concatena(Lista* l1, Lista* l2){
    Lista* p = l1;
    Lista* ant = NULL;

    while (p != NULL) {
        ant = p;
        p = p->prox;
    }
    ant->prox = l2;
}

Lista* retira_n(Lista* l, int n){
   Lista* ant = NULL;
   Lista* p = l;

    do{
        while ( p!= NULL && p->info != n){
            ant = p;
            p = p->prox;
        }
        if (p == NULL) return l;

        if(ant == NULL) l = p->prox;

        else ant->prox = p->prox;

        free(p);
        p = l;
    } while ( p!= NULL);
   
    return l;
}