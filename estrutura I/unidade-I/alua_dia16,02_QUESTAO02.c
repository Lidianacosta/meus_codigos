// 2. Escreva um programa que implementa uma struct Produto com os campos nome, pre¸co e tipo. O
// tipo deve ser armazenado como uma union que armazena um dos tipos: ALIMENTO, BEBIDA ou
// ELETRONICO. O programa deve ler os dados de um produto e imprimir os dados do produto

// nao entendi direito oq a questao queria entao fiz assim

#include<stdio.h>
#include<stdlib.h>

typedef union escolha{     // para a pessoa escolher so um 
    char alimento[20];
    char bebida[20];
    char eletronico[20];
}Escolha;

typedef struct produto{     // para guarda dados de um produto 
    char nome[20];
    float preco;
    Escolha escolha
}Produto;


int main(void){
    int op;
    Produto produto;    // variavel do tipo produto 

    printf("digite o nome do produto");
    scanf(" %[^\n]s",produto.nome);     //pedinso nome do produto 
    
    printf("digite o produto que vai querer \n");
    printf("1 para alimwnto 2 para bebida e 3 para eletronico : "); // dando um mini menu e pedindo a op 
    scanf("%d",&op);

        

    switch (op) // verificando qual op a pessoa escolheu
    {
    case 1:
            printf("digite o alimento : ");
            scanf(" %[^\n]s",produto.escolha.alimento);     //se o produto e um alimneto 
    break;
    case 2 :
            printf("digite a bebida : ");
            scanf(" %[^\n]s",produto.escolha.bebida);       //se o produto e uma bebida
    break;
    case 3 :
            printf("digite o eletronico : ");
            scanf(" %[^\n]s",produto.escolha.eletronico);   //se o produto e um eletronico
    break;
    default:
        printf("opçao invalida\n");     // se a op nao for valida
        exit(1);
        break;
    }

    printf("digite o preço : ");    // o preço do produto 
    scanf("%f",&produto.preco);  

    printf("DADOS : \n");
    switch (op)             /// vericar qual foi a op para mostra se um alimento , uma bebida ou um eletronico 
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

    printf("preço : %.2f",produto.preco);       // mostrando o preço do produto 
    return (0);
}
