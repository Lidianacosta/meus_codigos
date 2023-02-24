#include<stdio.h>


typedef union indice_academicos{    //uniom criei para guarda so um dos indices academicos de um estudante
    float ira;
    float irt;      
    float ig;
}Indice_Academicos;

typedef enum situacao{inativo,ativo,trancado}Situacao; // saber a  situaçao do aluno na instituiçao 

typedef struct aluno{   // guarda os dados do aluno 
    char nome[50];  // nome do estudante 
    char matricula[20]; // matricula do estudante 
    char curso[20]; // curso do estudante 
    Indice_Academicos indice_academicos; //  guarda o indices academico do estudante
    Situacao  situacao; //  guarda a situaçao  academica do estudante
}Aluno;


int main(void){
    int op_indice,op_situacao; // variaveis para guarda a opçao da situaçao e do indice 

    Aluno aluno;// criando uma variavel do tipo Aluno

    printf("digite o nome do aluno : ");    //pedindo o nome 
    scanf(" %[^\n]s",aluno.nome);
    printf("digite a matricula do aluno : ");// pedindo a marticula 
    scanf(" %[^\n]s",aluno.matricula);
    printf("digite o curso do aluno : "); // pedindo o curso 
    scanf(" %[^\n]s",aluno.curso);

    printf("digite 1 para ira ,2 para irt  e 3 para ig\n"); // mini menu
    printf("digite o indice academico que deseja dizer: "); // pedindo o indice 
    scanf("%d",&op_indice);
//=========================================================
    if (op_indice == 1) {
        scanf("%f",&aluno.indice_academicos.ira);
    }
    else if (op_indice == 2) {
        scanf("%f",&aluno.indice_academicos.irt);   // verificando qual e a opçao de indice que a pessoa quer guarda 
    }
    else if (op_indice == 3){
        scanf("%f",&aluno.indice_academicos.ig);
    }
//=========================================================
    printf("digite sua situaçao ativo = 1,inativo = 0  ou trancado = 2: "); // qual situçao o aluno estar 
    scanf("%d",(int*)&aluno.situacao);

    printf("DADOS DOS ALUNOS : \n"); // dados do aluno
    printf("nome: %s\n",aluno.nome);
    printf("matricula: %S\n",aluno.matricula);
    printf("curso: %s\n",aluno.curso); 
 //=========================================================   
    
    
    if (op_indice == 1) {
        printf("indice academico: %.2f\n",aluno.indice_academicos.ira);
    }
    else if (op_indice == 2) {
        printf("indice academico: %.2f\n",aluno.indice_academicos.irt);    // verificando qual e a opçao de indice que a pessoa quer guardou para mostra o indice academico
    else if (op_indice == 3){
        printf("indice academico: %.2f\n",aluno.indice_academicos.ig);
    }
//=========================================================
    if(aluno.situacao == "inativo" || aluno.situacao == 0){
    printf("INATIVO\n");
    }else if(aluno.situacao == "ativo" || aluno.situacao == 1){ // verificando qual e a opçao de indice que a pessoa quer guardou para mostra a situaçao
    printf("ATIVO\n");
    }else if(aluno.situacao == "trancado" || aluno.situacao == 2){
    printf("TRANCADO\n");
    }
//=========================================================
    return(0);
}
