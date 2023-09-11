/*Questão 2) Escreva um programa em C que preencha um vetor de 10 inteiros com informações
vindas de um arquivo e escreva em outro arquivo o menor elemento, o maior elemento, bem
como a média dos elementos do vetor, como ilustrado a seguir

10
2
8
1
12
8
10
5
4
19

menor elemento: 1
maior elemento: 19
media dos elementos: 7.900000*/


#include<stdio.h>
#include <string.h>

int main(void){
    int vetor[10],i,maior,menor;
    char linha[100];
    float media = 0;
    FILE* entrada = fopen("entrada.txt", "r");
    if (entrada == NULL){
        printf("nao foi possivel abrir o arquivo de entrada\n");
        return(1);
    } 
    FILE* saida = fopen("saida.txt", "w");
     if (saida == NULL){
        printf("nao foi possivel abrir o arquivo de saida\n");
        return(1);
    }

    while(fgets(linha, 100, entrada) != NULL){       
        sscanf(linha, "%d ", &vetor[i]);   
        
        media += vetor[i];
        i++;
    }
        menor = maior = vetor[0];
    
       for(i = 1; i < 10; i++){
         if (menor >= vetor[i]){
            menor = vetor[i];
         }
         if (maior <= vetor[i]){
            maior = vetor[i];
         }     
        }

    fprintf(saida, " menor elemento: %d\nmaior elemento: %d\nmedia dos elementos: %f\n",menor,maior,media/10);

    fclose(entrada);    
    fclose(saida);

    return(0);
}
