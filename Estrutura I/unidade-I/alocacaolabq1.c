// 1. Aloque dinamicamente um vetor de inteiros de tamanho 10 e preencha cada elemento 
//do vetor com o seu respectivo ´ındice (vetor[i] = i). Em seguida, imprima o vetor.

#include<stdio.h>
#include<stdlib.h>

#define N 10    // tamanho do vetor 

int main (void){

    int cont;
    int *v = (int*)malloc(N*sizeof(int)); // alocando dinamicamente um vetor de N POSIÇOES 

    if (v == NULL){         // verificando se deu erro 
        printf("ERRO");
        exit(1);
    }

    for (cont = 0; cont < N; cont++){   // mostrando os elementos 
        *(v + cont) = cont;
        printf("%d\t",*(v + cont));
        
    }

    free(v);   //liberando a memoria 
    return(0);
}
