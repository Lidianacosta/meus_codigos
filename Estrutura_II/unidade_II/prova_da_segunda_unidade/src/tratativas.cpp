#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <regex.h>

#define MAX_CHAR 100
#define MAX_NUM 100

#define SIZE 32

static const char EXPRESSAO_TELEFONE[] = "^[1-9][1-9][9][1-9][1-9][1-9][1-9][1-9][1-9][1-9][1-9]$";
static const char EXPRESSAO_NOME[] = "^[a-z]*"; //([\s]^[a-z]*$)?
static const char EXPRESSAO_EMAIL[] = "^[a-z]*$";


int isValid(int valor);
int valida_entrada(char *telelefone, const char* expressao);


long int getTelefone(){
    char telefone[MAX_NUM];

    do{
        printf("digite umnumero de telefone valido exempo: DDD + 9 + 99999999: ");
        scanf(" %[^\n]", telefone);
        fflush(stdin);
    
    } while (valida_entrada(telefone, EXPRESSAO_TELEFONE));

    printf("expressão: %s\n",telefone);

    return (long int)telefone;

}


int getNumero(){
    char num;

    do{
        printf("digite sua escolha");
        scanf(" %c", &num);
        fflush(stdin);
    
    } while (valida_entrada(&num, "^[0-9]$"));

    printf("expressão: %c\n",num);

    return (int)num;
}



char* getNome(){
    char nome[MAX_NUM];

    do{
        printf("digite um nome: ");
        scanf(" %[^\n]", nome);
        fflush(stdin);
    
    } while (valida_entrada(nome, EXPRESSAO_NOME));

    printf("expressão: %s\n",nome);

    return nome;

}

char* getEmail(){
    char email[MAX_NUM];

    do{
        printf("digite um email valido: ");
        scanf(" %[^\n]", email);
        fflush(stdin);
    
    } while (valida_entrada(email, EXPRESSAO_EMAIL));

    printf("expressão: %s\n",email);

    return email;

}


int valida_entrada(char *string, const char* expresao){
    regex_t regex;
    int valor;

    valor = regcomp(&regex, expresao, 0);

    if (valor == 0)
    {
        printf("RegEx compiled successfully.\n");
    }
    else
    {
        printf("Compilation error.\n");
    }

    valor = regexec(&regex, string, 0, NULL, 0);

    regfree(&regex);

    return isValid(valor);
}

int isValid(int valor)
{
    if (valor == 0)
    {
        printf("expressão correta! \n");
        return valor;
    }
    else if (valor == REG_NOMATCH){
        printf("expressão não correta! \n");
        return REG_NOMATCH;
    }

    printf("An error occured.\n");
    return -1;
}

int main(void)
{
    // unsigned long int tel = getTelefone();
    char* nome = getNome();
    // char* email = getEmail();

    // printf("%ld\n",tel);
    // printf("%s\n",email);
    printf("%s\n",nome);

    return 0;
}