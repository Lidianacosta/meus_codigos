#include<stdio.h>


typedef union indice_academicos{
    float ira;
    float irt;      //
    float ig;
}Indice_Academicos;

typedef enum situacao{inativo,ativo,trancado}Situacao;

typedef struct aluno{
    char nome[50];
    char matricula[20];
    char curso[20];
    Indice_Academicos indice_academicos;
    Situacao  situacao;
}Aluno;


int main(void){
    int op_indice,op_situacao;

    Aluno aluno;

    printf("digite o nome do aluno : ");
    scanf(" %[^\n]s",aluno.nome);
    printf("digite a matricula do aluno : ");
    scanf(" %[^\n]s",aluno.matricula);
    printf("digite o curso do aluno : ");
    scanf(" %[^\n]s",aluno.curso);

    printf("digite 1 para ira ,2 para irt  e 3 para ig\n");
    printf("digite o indice academico que deseja dizer: ");
    scanf("%d",&op_indice);

    if (op_indice == 1) {
        scanf("%f",&aluno.indice_academicos.ira);
    }
    else if (op_indice == 2) {
        scanf("%f",&aluno.indice_academicos.irt);
    }
    else if (op_indice == 3){
        scanf("%f",&aluno.indice_academicos.ig);
    }

    printf("digite sua situaçao ativo,inativo ou trancado: ");
    scanf("%d",(int*)&aluno.situacao);

    printf("DADOS DOS ALUNOS : \n");
    printf("nome: %s\n",aluno.nome);
    printf("matricula: %S\n",aluno.matricula);
    printf("curso: %s\n",aluno.curso); 
    if (op_indice == 1) {
        printf("indice academico: %.2f\n",aluno.indice_academicos.ira);
    }
    else if (op_indice == 2) {
        printf("indice academico: %.2f\n",aluno.indice_academicos.irt);
    }
    else if (op_indice == 3){
        printf("indice academico: %.2f\n",aluno.indice_academicos.ig);
    }

    if(aluno.situacao == "inativo" || aluno.situacao == 0){
    printf("INATIVO\n");
    }else if(aluno.situacao == "ativo" || aluno.situacao == 1){
    printf("ATIVO\n");
    }else if(aluno.situacao == "trancado" || aluno.situacao == 2){
    printf("TRANCADO\n");
    }

    return(0);
}