#include<stdio.h>
#include<stdlib.h>

int main(void){

    FILE* fp;
    fp = fopen("entrada.txt","rt");
    if (fp == NULL){
        printf("erro na abretura do arquivo!\n");
        exit(1);
    }else{
        printf("arquivo criado com sucesso!\n");
    }
     
    int c;
    int nlinhas = 0;

    while ((c = fgetc(fp)) != EOF){
        if (c == '\n'){
            nlinhas++;
        }
    }
    
    printf("o nomeros de linhas do o arquivo : %d\n",nlinhas);


    int valor = fclose(fp);

    if(valor != 0){
      printf("nao foi possivel fecha o arquivo\n");
    }else{
      printf("arquivo fechado com sucesso!\n");
    }

    return(0);
   }
