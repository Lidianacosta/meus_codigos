// 1. Crie um tipo estruturado para armazenar dados de um funcion´ario. Uma estrutura deste tipo possui
// os seguintes campos: nome, sal´ario, identificador e cargo.
// a) Escreva uma fun¸c˜ao que receba como parˆametro o endere¸co de uma estrutura do tipo Funcionario
// e preencha seus campos com valores fornecidos pelo usu´ario via teclado.
// b) Escreva uma fun¸c˜ao que receba como parˆametro o endere¸co de uma estrutura do tipo Funcionario
// e imprima os valores dos seus campos.
// c) Implemente uma fun¸c˜ao para realizar uma altera¸c˜ao no sal´ario de uma estrutura do tipo Funcionario.
// d) Escreva uma função que receba como parˆametro um vetor de estruturas do tipo Funcionario e
// imprima o cargo e salário do Funcionario com maior sal´ario e o cargo e sal´ario do funcion´ario
// com o menor sal´ario.

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct dados_funcionarios { // crianda a estrutura e definindo outro nome.
    char nome[50];
    float salario;
    char id[20];
    char cargo[50];
}Dados_funcionarios;
//                   funções
void preencher(Dados_funcionarios *f, int qtd); 
void imprimir( Dados_funcionarios*f,int qtd);
void modifica_salario(Dados_funcionarios *f,int qtd);
void verificar_salario(Dados_funcionarios *f,int qtd);

int main() {
    setlocale(LC_ALL,"Portuguese");
    int qtd;
    printf("digite o numero de funcionários que deseja cadastrar: "); // qtd de funcionarios que ira cadastra 
    scanf("%d",&qtd);

    Dados_funcionarios *funcionario = (Dados_funcionarios*)malloc(qtd * sizeof(Dados_funcionarios)); //criando um  ponteiro do tipo Dados_funcionarios e o alocondo dinamicamente.

    preencher(funcionario,qtd);             // passando o ponteiro funcionario e a qtd de funcionarios para a função.
    imprimir(funcionario,qtd);              // passando o ponteiro funcionario e a qtd de funcionarios para a função.
    modifica_salario(funcionario,qtd);      // passando o ponteiro funcionario e a qtd de funcionarios para a função.
    verificar_salario(funcionario,qtd);     // passando o ponteiro funcionario e a qtd de funcionarios para a função.

    free(funcionario);  //Liberando a memória 
}

void preencher(Dados_funcionarios *f,int qtd) {
    int i;
    for(i =0; i<qtd; i++) {
        printf("nome do %d° funcionário \n", i+1);
        scanf(" %[^\n]s",f[i].nome);
        printf("digite o valor do salário do %d° funcionario \n",i+1);
        scanf("%f",&f[i].salario);
        printf("digite o identificador do %d° funcionario\n",i+1);
        scanf(" %[^\n]s",f[i].id);
        printf("digite o cargo do %d° funcionário \n",i+1);
        scanf(" %[^\n]s",f[i].cargo);
        printf("\n");
    }
}

void imprimir(Dados_funcionarios *f,int qtd) {  // imprime todos os dados dos funcionarios.
    int i;
    for(i =0; i<qtd; i++) {
        printf("dados do %d° funcionario\n",i+1);
        printf("nome : %s\n",f[i].nome);
        printf("salario : %.2f\n",f[i].salario);
        printf("indentificador : %s\n",f[i].id);
        printf("cargo : %s\n",f[i].cargo);
        printf("\n");
    }
}

void modifica_salario(Dados_funcionarios *f,int qtd) { // muda o salario dos funcionarios. 
    int i,op;

    printf("deseja muda o salario do funcionario ?\n se sim, digite 1 se nao, digite 0: ");
    scanf("%d",&op);

    if(op == 0) {
        printf("não houve alteração no salario");
    } else {
        printf("digite o novo valor do salário do %d° funcionario \n",i+1);
        for(i =0; i<qtd; i++) {
            scanf("%f",&f[i].salario);
        }
    }
    if(op !=0) {
        printf("salário depois do reajuste\n");
        imprimir(f,qtd);
    }
}

void verificar_salario(Dados_funcionarios *f,int qtd) {

    int idx_maior, idx_menor,i;
    float veri_maior,veri_menor;

    veri_maior = f[0].salario;
    idx_maior = 0;
    veri_menor = f[0].salario;
    idx_menor = 0;

    for(i=1; i<qtd; i++) {
        if(veri_maior < f[i].salario) {
            idx_maior = i;
        }
        if(veri_menor < f[i].salario) {
            idx_menor =i;
        }
    }

    if (f[idx_maior].cargo == f[idx_menor]. cargo)
    {
       printf("quem recebe mais é o %s\n",f[idx_maior].cargo);
    }else{  
    printf("quem recebe mais é o %s\n",f[idx_maior].cargo);
    printf("quem recebe menos é o %s\n",f[idx_menor]. cargo);
   }
}
