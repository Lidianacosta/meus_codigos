#include <stdio.h>
#include "arvore.c"  // pra rodar no vscode tem qeu ser o .c 

int main(){
    Arvore* raiz = NULL;
    raiz = inserirNaArvore(raiz, 20);
    raiz = inserirNaArvore(raiz, 25);
    raiz = inserirNaArvore(raiz, -4);
    raiz = inserirNaArvore(raiz, 57);
    raiz = inserirNaArvore(raiz, 50);
    raiz = inserirNaArvore(raiz, 18);
    raiz = inserirNaArvore(raiz, 18);

    imprimirArvore(raiz);

    printf("altura da arvore: %d\n", alturaDaArvore(raiz));

    printf("return: %d\n", verificaBalanceamento(raiz));
    if(verificaBalanceamento(raiz) != 0)
        printf("A árvore está balanciada\n");
    else
        printf("A árvore está desbalanciada\n");
}