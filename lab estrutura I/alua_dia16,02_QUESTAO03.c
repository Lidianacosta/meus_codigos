// 3. Escreva um programa que implementa uma struct Data com os campos dia, mˆes e ano. O mˆes deve
// ser armazenado como um enum com os valores JANEIRO, FEVEREIRO, MARC¸ O, ABRIL, MAIO,
// JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO e DEZEMBRO. O programa
// deve ler a data e imprimir a data no formato dd/mm/aaaa.


#include<stdio.h>
#include<stdlib.h>

typedef enum mes{JANEIRO = 01, FEVEREIRO, MARCO, ABRIL, MAIO,JUNHO,JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO ,DEZEMBRO}Mes; // meses dos anos 

typedef struct data{  // guarda a o ano o dia e o mes 

    char dia[3];
    char ano[5];
    Mes mes ;  // enum Mes 

}Data;



int main(void){

    Data data;  // criando a variavel 
    
    printf("digite o dia : ");  //prenchendo seus campos
    scanf(" %[^\n]s",data.dia);
    printf("digite o mes : ");
    scanf("%d",(int *)&data.mes);
    printf("digite o ano : ");
    scanf(" %[^\n]s",data.ano);

    printf("\nDADOS :   "); //mostrando seus campos
    printf("%s /",data.dia);
  
    if(data.mes<10){
     printf("0%d /",data.mes);
    }else{
    printf("%d /",data.mes);
    }
    printf("%s",data.ano);
    return (0);
}
