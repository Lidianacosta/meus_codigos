#include<stdio.h>
#include<stdlib.h>


typedef struct dados_pessoa {
    char nome[50];
    char idade[5];
    char numero_documento[20];
} pessoa;

void preencher(pessoa *p, int qtd);
void imprimir(pessoa *p,int qtd);
void verificar_idade(pessoa *p,int qtd);
void modifica_idade (pessoa *p,int qtd);

int main() {
    int qtd;
    printf("digite o numero de pessoas que deseja cadastrar: ");
    scanf("%d",&qtd);

    pessoa *Pessoa = (pessoa*)malloc(qtd * sizeof(pessoa));

    preencher(Pessoa,qtd);
    imprimir(Pessoa,qtd);
    verificar_idade(Pessoa,qtd);
    modifica_idade(Pessoa, qtd);
    free(Pessoa);
}


void preencher(pessoa *p,qtd) {
    int i;
    for(i =0; i<qtd; i++) {
        printf("nome da %d° pessoa \n", i+1);
        scanf(" %[^\n]s",p[i].nome);
        printf("digite a idade da %d° pessoa \n",i+1);
        scanf(" %[^\n]s",p[i].idade);
        printf("digite o numero do documento da %d° pessoa \n",i+1);
        scanf(" %[^\n]s",p[i].numero_documento);
    }
}

void imprimir(pessoa *p,qtd) {
    int i;

    for(i =0; i<qtd; i++) {
        printf("dados da %d° pessoa \n",i+1);
        printf("nome : %s\n",p[i].nome);
        printf("idade: %s\n",p[i].idade);
        printf("o numero do documento : %s\n",p[i].numero_documento);

        printf("\n");
    }
}


void verificar_idade(pessoa *p,int qtd) {

    int idx_maior, idx_menor,i;
    char v_maior,v_menor;


    v_maior = p[0].idade;
    idx_maior = 0;
    v_menor = p[0].idade;
    idx_menor = 0;

    for(i=1; i<qtd; i++) {

        if(v_maior < p[i].idade) {
            idx_maior = i;
        }

        if(v_menor < p[i].idade) {
            idx_menor =i;
        }
    }

    if(p[idx_maior].nome == p[idx_menor].nome) {
        printf("%s é a mais velha\n",p[idx_maior].nome);
        printf("\n");
    } else {
        printf("%s é a mais velha\n",p[idx_maior].nome);
        printf("%s é a mais nova\n",p[idx_menor].nome);
        printf("\n");
    }
}
void modifica_idade(pessoa *p,int qtd) {

    int op,i;
    char numero_verificacao[20];
    printf("deseja mudar a idade das pessoas\n");
    printf("se nao digite 0, se sim digite 1\n");

//    printf("se nao digite 0, se desejar cadastrar uma pessoa específica digite 1, se deseja mudar de todas digite 3\n");
    scanf("%d",&op);

    if(op == 0) {
        printf("não houve alteração nas idade\n");
//    } else if(op == 1) {
 //       printf("digite o numero do documento da pessoa que desejamudara idade\n");
//        scanf(" %[^\n]s",numero_verificacao);

///        for(i=0; i<qtd; i++) {
///            if(numero_verificacao == p[i].numero_documento) {
//               printf("digite a nova idade da pessoa %s\n",p[i].nome);
 //            scanf(" %[^\n]s",p[i].idade);
//            }
//        }                erro!
    } else {

        for(i=0; i<qtd; i++) {
            printf("digite a nova idade da %d° pessoa \n",i+1);
            scanf(" %[^\n]s",p[i].idade);
        }

    }
}
