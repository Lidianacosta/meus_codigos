// 2. Escreva um programa que implementa uma struct Produto com os campos nome, pre¸co e tipo. O
// tipo deve ser armazenado como uma union que armazena um dos tipos: ALIMENTO, BEBIDA ou
// ELETRONICO. O programa deve ler os dados de um produto e imprimir os dados do produto

#include<stdio.h>
#include<stdlib.h>

typedef union escolha{
    char alimento[20];
    char bebida[20];
    char eletronico[20];
}Escolha;

typedef struct produto{
    float preco;
    Escolha escolha
}Produto;


int main(void){
    int op;
    Produto produto;

    printf("digite o produto que vai querer \n");
    printf("1 para alimwnto 2 para bebida e 3 para eletronico : ");
    scanf("%d",&op);

    switch (op)
    {
    case 1:
            printf("digite o alimento : ");
            scanf(" %[^\n]s",produto.escolha.alimento);
    break;
    case 2 :
            printf("digite a bebida : ");
            scanf(" %[^\n]s",produto.escolha.bebida);
    break;
    case 3 :
            printf("digite o eletronico : ");
            scanf(" %[^\n]s",produto.escolha.eletronico);
    break;
    default:
        printf("opçao invalida\n");
        exit(1);
        break;
    }

    printf("digite o preço : ");
    scanf("%f",&produto.preco);

    printf("DADOS : \n");
    switch (op)
    {
    case 1:

            printf("alimento : %s",produto.escolha.alimento);
        break;
    case 2 :
            printf("bebida : %s",produto.escolha.bebida);
    break;
    case 3 :
            printf("eletronico : %s",produto.escolha.eletronico);
    break;
    }

    printf("preço : %.2f",produto.preco);
    return (0);
}