// 1. Escreva um programa que implementa uma struct Pessoa com os campos nome, idade e gˆenero. O
// gˆenero deve ser armazenado como um enum com os valores MASCULINO e FEMININO. O programa
// deve ler os dados de uma pessoa e imprimir os dados da pessoa.

#include<stdio.h>
#include<stdlib.h>

#define numero_pessoas 1

typedef enum sexo{MASCULINO,FEMININO}Sexo;

typedef struct pessoas{
    char nome[50];
    int idade;
    Sexo sexo;
}Pessoas;

int main(void){

    Pessoas *pessoas = (Pessoas*)malloc( numero_pessoas* sizeof(Pessoas));

    printf("digite o nome : ");
    scanf(" %[^\n]s",pessoas->nome);
    printf("digite a idade: ");
    scanf("%d",&pessoas->idade);
    printf("digite o genero: ");
    scanf("%d",(int*)&pessoas->sexo);

    printf("digite o nome : %s\n",pessoas->nome);
    printf("digite a idade: %d\n",pessoas->idade);
 
  //  pessoas->sexo == MASCULINO?printf("MASCULINO\n"):printf("FEMININO\n");
 
    pessoas->sexo == FEMININO?printf("FEMININO\n"):printf("MASCULINO\n");
 
  //  printf("digite o genero: %d\n",pessoas->sexo);
   
    printf("");
    return(0);
}