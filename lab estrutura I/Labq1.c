#include<stdio.h>
#include<stdlib.h>


typedef struct dados_funcionarios {
    char nome[50];
    float salario;
    char id[20];
    char cargo[50];
} df;

void preencher(df *f, int qtd);
void imprimir(df *f,int qtd);
void modifica_salario(df *f,int qtd);
void verificar_salario(df *f,int qtd);

int main() {
    int qtd;
    printf("digite o numero de funcionários que deseja cadastrar: ");
    scanf("%d",&qtd);

    df *f = (df*)malloc(qtd * sizeof(df));

    preencher(f,qtd);
    imprimir(f,qtd);
    modifica_salario(f,qtd);
    verificar_salario(f,qtd);

    free(f);
}


void preencher(df *f,int qtd) {
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

void imprimir(df *f,int qtd) {
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

void modifica_salario(df *f,int qtd) {
    int i,op;

    printf("deseja muda o salario do funcionario se sim digite 1 se nao digite 0: ");
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

void verificar_salario(df *f,int qtd) {

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
    printf("quem recebe mais e o %s\n",f[idx_maior].cargo);
    printf("quem recebe menos e o %s\n",f[idx_menor]. cargo);
}
