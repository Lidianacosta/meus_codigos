#include<stdio.h>
#include<stdlib.h>

int main(void){
    
    FILE* file_entrada,* file_saida;  
    float nota1,nota2,nota3,media;
    char nome[50],linha[100];

    file_entrada = fopen("entrada_file.txt","rt");
    if(file_entrada == NULL){
        printf("erro ao abrir o arquivo\n");
        return(1);
    }

    file_saida = fopen("saida_file.txt","wt");
    if(file_saida == NULL){
        printf("erro ao abrir o arquivo \n");
        return(1);
    }

    while(fgets(linha,100,file_entrada) != NULL){
        sscanf(linha, "%20[^\t]\t%f\t%f\t%f",nome,&nota1,&nota2,&nota3);
        media  = (nota1 + nota2 + nota3)/3;

        fprintf(file_saida, "%s\t%.1f\t%s\n",nome,media,(media>=7.0)?"aprovado":"reprovado");
    }
    fclose(file_entrada);
    fclose(file_saida);
    
}

// Amanda	7.0	6.5	9.0
// Alberto	5.0	7.0	3.5
// Jane	8.0	6.8	4.5
// Igor	9.0	9.0	8.5
// Samara	10.0	10.0	7.0
// Maria Luiza	10.0	10.0	10.0
// Cesar 	10.0	9.0	8.0
// Pedro Felipe	7.0	7.0	7.0

