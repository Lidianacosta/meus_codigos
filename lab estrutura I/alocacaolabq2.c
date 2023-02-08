// 2. Aloque dinamicamente uma matriz de inteiros 3x3 e preencha cada elemento da matriz com o seu
// respectivo ´ındice (matriz[i][j] = i*3 + j). Em seguida, imprima a matriz.

#include<stdio.h>
#include<stdlib.h>

#define T 3

int main (void){
    
    int linha,coluna;
    
    int **m = (int **) malloc(T*sizeof(int*));
        if(m==NULL){ 
        printf("Erro");
        exit(1);
        } 

    for(linha=0; linha<T; linha++){
       m [linha]= (int *) malloc(T*sizeof(int));

        if(m[linha]==NULL){ 
        printf("Erro");
        exit(1);
        } 
    }

    for(linha=0; linha<T; linha++){
     for(coluna =0;coluna<T;coluna++){
    
        m[linha][coluna] = linha*T + coluna;
       
        printf("%d\t",m[linha][coluna]);

     }
    }

     for(linha=0; linha<T; linha++){
         free( m [linha]);
      }
        free(m);

      return(0);
}
