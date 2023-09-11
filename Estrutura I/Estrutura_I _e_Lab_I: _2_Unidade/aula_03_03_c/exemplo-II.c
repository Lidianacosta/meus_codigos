#include<stdio.h>

int main(void){
    int c;
    FILE* fp = fopen("arquivo.txt","rt");
    
    if(fp == NULL){
        printf("error ao abrir o programa");
        return(1);
    }

    //while (!feof(fp)){
        c = fgetc(fp);
        printf("%c", c);
   // }

    fclose(fp);
    return(0);
}
