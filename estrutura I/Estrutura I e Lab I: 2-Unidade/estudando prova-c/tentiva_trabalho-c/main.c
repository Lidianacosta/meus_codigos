#include <stdio.h>
#include <stdlib.h>
#include "aluno.c"


int main(void){
    Aluno* alunos = (Aluno*)malloc(sizeof(Aluno));
    int qtd_alunos,op,idx,mat;
    qtd_alunos = ler_aluno(alunos);
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
        
        default:
            break;
        }
       
    } while (op != 5);
    
    return (0);
}
