#include<stdio.h>
#include"aluno.c"
#include<stdlib.h>


#define QTD_ALUNOS 2

int main(void){
    int cont_alunos_criados = 0;
    Aluno **alunos = (Aluno**)malloc(QTD_ALUNOS* sizeof(Aluno*));
    if (alunos == NULL){
        printf("erro!\n");
        exit(1);
    }

    Aluno *aluno_procurado;

    char nome[] ="lidiana";

    alunos[cont_alunos_criados] = aluno_cria(nome , 10);
    cont_alunos_criados++;
    aluno_procurado =  procura_Aluno(alunos,nome);
    aluno_imprime(aluno_procurado);

    aluno_libera();

    return(0);
}   
    // do
    // {
    //        switch (op)
    // {
    // case /* constant-expression */:
    //     /* code */
    //     break;
    
    // default:
    //     break;
    // } 
    // } while (op != 6);
