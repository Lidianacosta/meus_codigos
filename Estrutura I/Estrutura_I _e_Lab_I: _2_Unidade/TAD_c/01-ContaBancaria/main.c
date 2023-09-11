#include<stdio.h>
#include "contabancaria.h"

int main(void){
    ContaBancaria* conta01;
    ContaBancaria* conta02;
    char nome01[20] = "lidiana", nome02[20] = "lucas";
    conta01 = cria_conta(nome01,01,500);
    conta02 = cria_conta(nome02,02,200);
    deposita(conta01,200);
    deposita(conta02,200);
    saca(conta01,100);
    transfere(conta01,conta02,100);
    imprimir(conta01);
    imprimir(conta02);
    exclui_conta(conta01);
    exclui_conta(conta02);
    return(0);
}