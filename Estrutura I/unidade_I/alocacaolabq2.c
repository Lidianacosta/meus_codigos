// 2. Aloque dinamicamente uma matriz de inteiros 3x3 e preencha cada elemento da matriz com o seu
// respectivo ´ındice (matriz[i][j] = i*3 + j). Em seguida, imprima a matriz.

#include<stdio.h>
#include<stdlib.h>

#define T 3 // tamanho da matriz

int main (void){
    
    int linha,coluna;
    
    int **m = (int **) malloc(T*sizeof(int*));         // alocando uma matriz dinamicamente 
        
        if(m==NULL){        //verificando se nao deu erro na alocaçao 
        printf("Erro");
        exit(1);
        } 

    for(linha=0; linha<T; linha++){     // alocando as linhas da matriz 

       m [linha]= (int *) malloc(T*sizeof(int));

        if(m[linha]==NULL){  //verificando se nao deu erro na alocaçao
        printf("Erro");
        exit(1);
        } 
    }

    for(linha=0; linha<T; linha++){         
     for(coluna =0;coluna<T;coluna++){
    
        m[linha][coluna] = linha*T + coluna;    // atribuindo o indice da posiçao a matriz 
       
        printf("%d\t",m[linha][coluna]);// mostrando o conteudo da matriz da matriz 

     }
    }

     for(linha=0; linha<T; linha++){            // liberando memoria
         free( m [linha]);
      }
        free(m);        // liberando memoria

      return(0);
}
