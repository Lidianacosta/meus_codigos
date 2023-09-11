#include<stdio.h>
#include<stdlib.h>

#define MAX_HASH 26

#define MAX_CHAR 50

typedef struct pessoa Pessoa;

struct pessoa{
    char nome[MAX_CHAR];
    char email[MAX_CHAR];
    int telefone;// pode ser um long int e tratamento buscar por regex
};

struct hash{
    
};


Pessoa* criar_contato(){
    return NULL;
}

void lista_contatos(){

}

Pessoa* busca_contatos(){
    return NULL;
}

void Exporta_contatos(){
    FILE* listaDeContatos = fopen("listaDeContatos.txt", "w");

    // usar fgets 
}

void apagar_contato(){}



int main(){

}
