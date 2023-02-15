// Questão 1) Uma empresa fez uma pesquisa para saber se as pessoas gostaram ou não de um
// novo produto. Um número N de pessoas de ambos os sexos foi entrevistado, e o questionário
// consistia em apenas duas perguntas: (i) o sexo do entrevistado (M/F) e (ii) sua opinião sobre o
// produto (gostou/não gostou). Escreva um programa em C que:
// a) leia as respostas contidas no questionário e armazene-as em dois arrays vinculados,
// um deles contendo a resposta para a primeira pergunta e o outro contendo a resposta
// para a segunda pergunta.
// b) determine a porcentagem de pessoas do sexo feminino que responderam que
// gostaram do produto.
// c) determine a porcentagem de pessoas do sexo masculino que responderam que não
// gostaram do produto.

#include<stdio.h>
#include<stdlib.h>

int main(){

int numero_responderam,i,contf = 0,contm = 0;

printf("digite o numero de pessoas que responderam as perguntas\n");// solicitei quantas pessoas responderam  a pesquisa.
scanf("%d", &numero_responderam);

char *sexo = (char *)malloc(numero_responderam * sizeof(char)); //declarando um ponteiro e alocando dinamicamente.
int *op = (int *)malloc(numero_responderam * sizeof(int));      //declarando um ponteiro e alocando dinamicamente.

for( i = 0; i < numero_responderam; i++){
   printf("digite o sexo do intrevistado F para Feminino e M pra masculino\n"); //pedindo o sexo.
    scanf(" %c", &sexo[i]);             
    printf("digite 0 pra nao gostou e 1 pra gostou\n"); // perguntando se gostou ou nao gostou.
    scanf("%d", &op[i]);
}

int j;
for( j = 0; j < numero_responderam; j++){
if ((sexo[j] == 'F') && (op[j] == 1)){ contf++;} // verificando se é mulher. 
if ((sexo[j] == 'M') && (op[j] == 0)){ contm++;} // verificando se é homem. 
}

float FM, MM;
FM = (contf*100)/numero_responderam;    //porcentagem de mulheres que gostaram do produto
MM = (contm*100)/numero_responderam;    //a porcentagem de homems que não gostaram do produto.
system("cls");  
printf("porcentagem de pessoas do sexo feminino que responderam que gostaram do produto : %.2f%%\n",FM);
printf("porcentagem de pessoas do sexo masculino que responderam que não gostaram do produto : %.2f%%\n",MM);

free(sexo); //liberando a memória.
free(op); //liberando a memória.

}
