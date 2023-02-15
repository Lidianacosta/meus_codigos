// Questão 2) Escreva um programa para corrigir provas de múltipla escolha. Cada prova tem N
// questões e cada questão vale 10/N pontos. Os primeiros dados a serem lidos são o número de
// questões e o gabarito da prova. Em seguida, serão lidas as respectivas respostas de um total de
// 10 alunos matriculados. Calcule e mostre:
// a) a nota obtida para cada aluno;
// b) a porcentagem de aprovação, sabendo-se que a nota mínima para ser aprovado é 6.

#include<stdio.h>
#include<stdlib.h>

#define C 3 //costante usada para dizer a qtd de alunos que responderam a prova e para saber o pecentual de aprovados.

int main(void){

    int numero_de_questoes,cont,qtd_alunes,soma_pontos = 0,qtd_alunes_passarao = 0;
    float media,percentual;

    printf("digite o numero de questoes que sua prova tem\n");
        scanf("%d",&numero_de_questoes);
 printf("\n================================================================\n\n");

 int *gabarito = (int *)malloc(numero_de_questoes * sizeof(int));   //alocando espaço para o gabarito
 
 if (gabarito == NULL){
    printf("Memoria insuficiente.\n"); // verificando se tem espaço para a alocação.
    exit(1);
 }
 int *resposta_alunos = (int *)malloc(numero_de_questoes * sizeof(int));//alocando espaço para as respostas.

 if (resposta_alunos == NULL){
    printf("Memoria insuficiente.\n"); // verificando se tem espaço para a alocação.
    exit(1);
 }
 
printf("digite o gabarito\n");

for(cont = 0;cont<numero_de_questoes;cont++){
scanf("%d",&gabarito[cont]);    // pedindo o gabarito
}
printf("\n================================================================\n\n");
for(qtd_alunes = 0;qtd_alunes<C;qtd_alunes++){
soma_pontos = 0;    // variavel para soma a qtd de questoes que o aluno acertou.
printf("digite suas respostas aluno n %d°\n",qtd_alunes + 1);

for(cont = 0;cont<numero_de_questoes;cont++){
    printf("resposta n %d\n",cont +1); 
    scanf("%d",&resposta_alunos[cont]);  // pegando as respostas dos alunos.

if (gabarito[cont] == resposta_alunos[cont]){
    soma_pontos+=10;        //verificando as respostas.
}
}

media  = (float)soma_pontos/numero_de_questoes; // media do aluno.
// "erro" não está mostrando um float, está mostrando como int entao forcei a ser do tipo float.
if (media >= 6.0)
{
        qtd_alunes_passarao++;  //contando quantos alunos passaram para saber o percentual de alunos aprovados.
}
printf("a nota obtida foi : %.2f\n",media);
printf("\n================================================================\n\n");
}
percentual = (qtd_alunes_passarao * 100)/C;
printf("a porcentagem de aprovação foi : %.0f%%\n",percentual);  // percentual de alunos aprovados.

printf("\n================================================================\n");
free(gabarito); //Liberando a memória 
free(resposta_alunos); //Liberando a memória
    return(0);
}
