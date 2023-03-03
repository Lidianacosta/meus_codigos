// 1. Escreva um programa que implementa uma struct Pessoa com os campos nome, idade e gˆenero. O
// gˆenero deve ser armazenado como um enum com os valores MASCULINO e FEMININO. O programa
// deve ler os dados de uma pessoa e imprimir os dados da pessoa.

#include<stdio.h>
#include<stdlib.h>

#define numero_pessoas 1 // costante para o numero de pessoas 

typedef enum sexo{MASCULINO,FEMININO}Sexo; // enum para o genero do passoa 

typedef struct pessoas{ // para guarda os dados das pessoas  
    char nome[50];
    int idade;
    Sexo sexo;
}Pessoas;

int main(void){

    Pessoas *pessoas = (Pessoas*)malloc( numero_pessoas* sizeof(Pessoas));  // alocando dinamicamente 

    printf("digite o nome : ");         // pedindo o nome 
    scanf(" %[^\n]s",pessoas->nome);
    printf("digite a idade: ");        // pedindo a idade 
    scanf("%d",&pessoas->idade);
    printf("digite o genero: ");          //pedindo o genero
    scanf("%d",(int*)&pessoas->sexo);

    printf(" o nome : %s\n",pessoas->nome);  // mostrando os dados 
    printf("a idade: %d\n",pessoas->idade);
 
  //  pessoas->sexo == MASCULINO?printf("MASCULINO\n"):printf("FEMININO\n");
 
    pessoas->sexo == FEMININO?printf("FEMININO\n"):printf("MASCULINO\n");   // verificando se é homem ou mulher 
 
  //  printf("o genero: %d\n",pessoas->sexo);
   
   // printf("");
    
    // nao terminei de ajeitar 
    return(0);
}
