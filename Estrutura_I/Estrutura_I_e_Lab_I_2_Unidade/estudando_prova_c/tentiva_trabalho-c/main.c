#include <stdio.h>
#include <stdlib.h>
#include "aluno.c"


int main(void){
    Aluno* alunos = (Aluno*)malloc(sizeof(Aluno));
    int qtd_alunos,op,idx,mat;
    char nome[50];
        FILE* arquivo = fopen("alunos.txt", "rt");
    if (arquivo == NULL){
        printf("erro!");
        exit(1);
    }
    fscanf(arquivo, "%d",&qtd_alunos);
    fclose(arquivo);
    alunos = realloc(alunos,sizeof(Aluno)*(qtd_alunos));
    ler_aluno(alunos);
    printf("\ntem %d alunos cadastrados!\n",qtd_alunos);
    
    do{
        menu();
        printf("sua opção: ");
        scanf("%d",&op);
        
        switch (op){
        case 1:
         alunos = realloc(alunos, sizeof(Aluno)*(qtd_alunos+1));
            criar_alunos(alunos,qtd_alunos);
            qtd_alunos++;
            printf("\ntem %d alunos cadastrados!\n",qtd_alunos);
            break;
        case 2:
            printf("digite o nome do aluno que deseja busca: ");
            scanf(" %[\n]s",nome);
            idx = busca_interpolada_nome(alunos,qtd_alunos,nome);
            printf("aaaaw!\n");
            if (idx == -1){
                printf("aluno nao encontrado\n");
            }else{
                printf("nome: %s , documento: %d , matricula: %d\n",alunos[idx].nome,alunos[idx].doc,alunos[idx].mat);
            }
            break;
        case 3:
        printf("digite a matricula do aluno que deseja busca: ");
            scanf("%d",&mat);
            idx = busca_interpolada_mat(alunos,qtd_alunos,mat);
            if (idx == -1){
                printf("aluno nao encontrado\n");
            }
            else{
                printf("nome: %s , documento: %d , matricula: %d\n",alunos[idx].nome,alunos[idx].doc,alunos[idx].mat);
            }
            break;
        case 4:
            imprime_alunos(alunos,qtd_alunos);
            break;
        case 5:
            salva_alunos(alunos,qtd_alunos);
            break;
        default:
            break;
        }
       
    } while (op != 6);
    
    return (0);
}
