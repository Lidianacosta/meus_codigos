#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    char nome[50];
    int doc;
    int mat;
}Aluno;


// int ler_aluno(Aluno *a){
//     //char linha[100];
//     int qtd_alunos = 0;
//     FILE* arquivo = fopen("alunos.txt", "rt");
//     if (arquivo == NULL){
//         printf("erro!");
//         exit(1);
//     }
    
//     // while (fgets(linha, 100, arquivo) != NULL){
//     //    if (qtd_alunos != 0){
//     //         a = realloc(a,sizeof(Aluno)*(qtd_alunos));
//     //    }
//     //     sscanf(linha, " %[^;]s;  %[^;]s; %d",a[qtd_alunos].nome,a[qtd_alunos].doc,&a[qtd_alunos].mat);
//     //     qtd_alunos++;
//     // }


//     while (feof(arquivo) == 0){
//        if (qtd_alunos != 0){
//             a = realloc(a,sizeof(Aluno)*(qtd_alunos));
//        }
//         fscanf(arquivo, " %[^\n] %d %d",a[qtd_alunos].nome,&a[qtd_alunos].doc,&a[qtd_alunos].mat);
//         qtd_alunos++;
//     }
//     fclose(arquivo);
//     return(qtd_alunos);
//  }

 void ler_aluno(Aluno *a){
    int i,qtd_alunos;
    FILE* arquivo = fopen("alunos.txt", "rt");
    if (arquivo == NULL){
        printf("erro!");
        exit(1);
    }
        fscanf(arquivo, "%d",&qtd_alunos);
    for (i = 0; i < qtd_alunos; i++){
        fscanf(arquivo, " %[^\n] %d %d",a[i].nome,&a[i].doc,&a[i].mat);
    }
    fclose(arquivo);
 }



void menu(void){
    printf("\nmenu\n");
    printf("1-criar aluno\n2-busca aluno por nome\n3-busca aluno por matricula\n4-imprimir alunos\n5-salvar alunos\n6-sair\n");
}

void imprime_alunos(Aluno* a, int qtd_alunos){
    int i;
    for (i = 0; i < (qtd_alunos); i++){
        printf("nome: %s , documento: %d , matricula: %d\n",a[i].nome,a[i].doc,a[i].mat);
    }
}

void criar_alunos(Aluno* a, int qtd_alunos){
     printf("digite os dados do aluno\n");
     printf("nome: ");
     scanf(" %[^\n]s", a[qtd_alunos].nome);
     printf("documento: ");  
     scanf("%d",&a[qtd_alunos].doc);
     printf("matricula: ");
     scanf("%d", &a[qtd_alunos].mat);
}


int busca_interpolada_mat(Aluno* a,int qtd_alunos, int mat){
    int inicio = 0;
    int fim = qtd_alunos-1; 
    int meio; 
    while (inicio <= fim){
        meio = inicio + (mat - a[inicio].mat) / (fim - inicio) * (a[fim].mat - a[inicio].mat);
        if(mat == a[meio].mat){
            return(meio);
        }
        else if(mat > a[meio].mat){
            inicio = meio+1;
        }
        else{
            fim = meio-1;
        } 
    }
    return(-1);
}

int busca_interpolada_nome(Aluno* a,int qtd_alunos, char* nome){
    int inicio = 0;
    int fim = qtd_alunos-1; 
    int meio; 
    while (inicio <= fim){
         meio = inicio + (strcmp(nome,a[inicio].nome) * (fim - inicio)) / strcmp(a[fim].nome,a[inicio].nome);
        if(strcmp(nome,a[meio].nome) == 0){
            return(meio);
        }
        else if(strcmp(nome,a[meio].nome) == 1){
            inicio = meio+1;
        }
        else{
            fim = meio-1;
        } 
    }
    return(-1);
}



void salva_alunos(Aluno* a,int qtd_alunos){
    int i;
    FILE* arquivo = fopen("alunos.txt", "w");
    if (arquivo == NULL){
        printf("erro!");
        exit(1);
    }
        fprintf(arquivo, "%d\n",qtd_alunos);
    for (i = 0; i < qtd_alunos; i++){
        fprintf(arquivo, "%s\n%d\t%d\n",a[i].nome,a[i].doc,a[i].mat);
    }
    fclose(arquivo);
}
