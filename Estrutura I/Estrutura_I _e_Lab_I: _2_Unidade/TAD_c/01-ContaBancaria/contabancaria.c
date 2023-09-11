#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "contabancaria.h"

typedef struct contabancaria{ 
    char titular[51];
    int numero_conta;
    float saldo;
}ContaBancaria;

ContaBancaria* cria_conta(char* titular, int numero_conta, float saldo){
    ContaBancaria* conta = (ContaBancaria*)malloc(sizeof(ContaBancaria));
    if (conta == NULL){
        printf("erro sem espaÃ§o na memoria!\n");
        exit(1);
    }
    strcpy(conta->titular,titular);
    conta->numero_conta = numero_conta;
    conta->saldo = saldo;
    return(conta);
}

void deposita(ContaBancaria* conta, float valor_deposita){
    conta->saldo += valor_deposita;
}

void saca(ContaBancaria* conta, float valor_sacar){
    if (conta->saldo >=valor_sacar){
        conta->saldo -=valor_sacar;
    }else{
        printf("saldo insufifiente!\n");
    }
}

void transfere(ContaBancaria* conta_trasfere, ContaBancaria* conta_recebe, float valor_trasferencia){
    if (conta_trasfere->saldo >=valor_trasferencia){
        conta_trasfere->saldo -= valor_trasferencia;
        conta_recebe->saldo += valor_trasferencia;
    }else{
        printf("saldo insufifiente!\n");
    }
}

float saldo(ContaBancaria* conta){
    return(conta->saldo);
}

void exclui_conta(ContaBancaria* conta){
    free(conta);
}

void imprimir(ContaBancaria* conta){
    printf("%s seu saldo Ã©: %.2f\n",conta->titular,saldo(conta));
}