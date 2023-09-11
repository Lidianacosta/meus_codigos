#include<stdio.h>

int main(void){
    FILE* fp = fopen("arquivo.txt","wt");
    if(fp == NULL){
        printf("error ao abrir o programa");
        return(1);
    }

    fputc('A', fp);
    fclose(fp);
    return(0);
}
