#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arvore{
    int info;
    int altura;
    Arvore* esq;
    Arvore* dir;
};

// Arvore* alocarMemoria(){
//     Arvore* no = (Arvore*)malloc(sizeof(Arvore));
//     no->esq = no->dir = NULL;
//     no->info = no->altura = 0;
//     return no;
// }

Arvore* alocarMemoria(int valor){
    Arvore* no = (Arvore*)malloc(sizeof(Arvore));
    no->esq = no->dir = NULL;
    no->info = valor;
    no->altura = 1;
    return no;
}

Arvore* inserirNaArvore(Arvore* raiz, int info){
    
    if(raiz == NULL){
        // Arvore* novoNo = alocarMemoria();
        // novoNo->info = info;
        // return novoNo;
        return alocarMemoria(info);
    }

    else if(info < raiz->info )
        raiz->esq = inserirNaArvore(raiz->esq, info);

    else if(info > raiz->info)
       raiz->dir = inserirNaArvore(raiz->dir,info);

    else 
        printf("a chave %d ja estar na arvore\n",info);

    raiz->altura = alturaDaArvore(raiz) + 1;


    int b = balanceamento(raiz);

    if(b > 1 && raiz->esq != NULL && info < raiz->esq->info)
        return rotacaoDir(raiz);

    if(b < -1 && raiz->dir != NULL && info > raiz->dir->info)
        return rotacaoEsq(raiz);

    if(b > 1 && raiz->esq != NULL && info > raiz->esq->info)
        return rotacaoEsq(raiz);

    if(b < -1 && raiz->dir != NULL && info < raiz->dir->info){
        raiz->dir = rotacaoDir(raiz->dir);
        return rotacaoEsq(raiz);
    }

    return raiz;
}

void imprimirArvore(Arvore* raiz){
    if(raiz != NULL){
        imprimirArvore(raiz->esq);
        printf(" %d ", raiz->info);
        imprimirArvore(raiz->dir);
    }
}

// não entendi bem
int antecessor(Arvore* raiz){
    int s = raiz->info;
    while(raiz->dir != NULL){
        s = raiz->dir->info;
        raiz = raiz->dir;
    }
    // não entendi porque nao é só raiz = null;
    raiz->dir = NULL;
    return s;
}

int sucessor(Arvore* raiz){
    int s = raiz->info;
    while(raiz->esq != NULL){
        s = raiz->esq->info;
        raiz = raiz->esq;
    }
    // não entendi porque nao é só raiz = null;
    raiz->esq = NULL;
    return s;
}

// não entendi bem
Arvore* removerNo(Arvore* raiz, int valor){
    if(raiz  == NULL){
        printf("A chave não estar na árvore");
        return NULL;
    }
    
    if(valor < raiz->info)
        raiz->esq = removerNo(raiz->esq, valor);

    else if(valor > raiz->info)
        raiz->dir = removerNo(raiz->dir, valor);

    else{
        if(raiz->esq == NULL)
            return raiz->dir;

        if(raiz->dir == NULL)
            return raiz->esq;

        // faz isso quando estar no meio da arvore
        // raiz->info = antecessor(raiz->esq);
        // raiz->esq = removerNo(raiz->esq, raiz->info);
        raiz->info = sucessor(raiz->dir);
        raiz->dir = removerNo(raiz->dir, raiz->info);
    }

    return raiz;
}

int max(int a, int b){
    return (a > b) ? a : b; 
}


// entendi mais ou menos
int alturaDaArvore(Arvore* raiz){
    if (raiz == NULL)
        return -1;

    int alturaEsq = alturaDaArvore(raiz->esq);
    int alturaDir = alturaDaArvore(raiz->dir);

    return max(alturaDir, alturaEsq) + 1;
}

int verificaBalanceamento(Arvore* raiz){
    if(raiz == NULL)
        return 1;
    
    int alturaEsq = alturaDaArvore(raiz->esq);
    int alturaDir = alturaDaArvore(raiz->dir);
    int balanceamento = (alturaEsq > alturaDir) ? alturaEsq - alturaDir : alturaDir - alturaEsq;
    
    if(balanceamento > 1) // 
        return 0;
    return 1;
}

// nao sei oq fazer com ela ainda 
int balanceamento(Arvore* raiz){
    if(raiz == NULL)
        return 0;
    return alturaDaArvore(raiz->esq) - alturaDaArvore(raiz->dir);
}

int alturaDoNo(Arvore* raiz){
    if(raiz == NULL)
        return 0;
    return raiz->altura;
}

Arvore* rotacaoDir(Arvore* raiz){
    Arvore* rotacao = raiz->esq;

    raiz->esq = rotacao->dir;
    rotacao->dir = raiz;

    raiz->altura = max(alturaDoNo(raiz->dir), alturaDoNo(raiz->esq)) + 1;
    rotacao->altura = max(alturaDoNo(rotacao->dir), alturaDoNo(rotacao->esq)) + 1;

    return rotacao;
}

Arvore* rotacaoEsq(Arvore* raiz){
    Arvore* rotacao = raiz->dir;

    raiz->dir = rotacao->esq;
    rotacao->esq = raiz;

    raiz->altura = max(alturaDoNo(raiz->dir), alturaDoNo(raiz->esq)) + 1;
    rotacao->altura = max(alturaDoNo(rotacao->dir), alturaDoNo(rotacao->esq)) + 1;

    return rotacao;
}
