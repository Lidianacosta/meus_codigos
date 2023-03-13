#include<stdio.h>
#include "contabancaria.c"



int main(void){
    ContaBancaria* conta01;
    ContaBancaria* conta02;
    char nome01[20] = "lidiana", nome02[20] = "lucas";
    conta01 = cria_conta(nome01,01,200);
    conta02 = cria_conta(nome02,02,200);
    deposita(conta01,200);
    deposita(conta02,200);
    saca(conta01,100);
    transfere(conta01,conta02,100);
    printf("%s seu saldo é: %.2f\n",conta01->titular,saldo(conta01));
    printf("%s seu saldo é: %.2f\n",conta02->titular,saldo(conta02));
    return(0);
}
