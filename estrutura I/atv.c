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

int n,i,contf = 0,contm = 0;

printf("digite o numero de pessoas que responderam as perguntas\n");
scanf("%d", &n);

char *sexo = (char *)malloc(n * sizeof(char));
int *op = (int *)malloc(n * sizeof(int));

for( i = 0; i < n; i++){
   printf("digite o sexo do intrevistado F para Feminino e M pra masculino\n");
    scanf(" %c", &sexo[i]);
    printf("digite 0 pra nao gostou e 1 pra gostou\n");
    scanf("%d", &op[i]);
}

int j;
for( j = 0; j < n; j++){

if ((sexo[j] == 'F') && (op[j] == 1)){ contf++;}
if ((sexo[j] == 'M') && (op[j] == 0)){ contm++;}

}

float FM, MM;
FM = (contf*100)/n;
MM = (contm*100)/n;
system("cls");
printf("A porcentagem de pessoas do sexo feminino : %.2f%%\n",FM);
printf("A porcentagem de pessoas do sexo masculino : %.2f%%\n",MM);

free(sexo);
free(op);

}
