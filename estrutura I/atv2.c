// Questão 2) Escreva um programa para corrigir provas de múltipla escolha. Cada prova tem N
// questões e cada questão vale 10/N pontos. Os primeiros dados a serem lidos são o número de
// questões e o gabarito da prova. Em seguida, serão lidas as respectivas respostas de um total de
// 10 alunos matriculados. Calcule e mostre:
// a) a nota obtida para cada aluno;
// b) a porcentagem de aprovação, sabendo-se que a nota mínima para ser aprovado é 6.


#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define cost 10


int main(void){
setlocale(LC_ALL,"Portuguese");

    int numero_de_questoes,cont,qtd_alunes,soma_pontos = 0,qtd_alunes_passarao = 0;
    float media,percentual;

    printf("digite o numero de questoes que sua prova tem\n");
        scanf("%d",&numero_de_questoes);
 printf("\n================================================================\n\n");

 int *gabarito = (int *)malloc(numero_de_questoes * sizeof(int));
 
 if (gabarito == NULL){
    printf("Memoria insuficiente.\n");
    exit(1);
 }
 int *resposta_alunos = (int *)malloc(numero_de_questoes * sizeof(int));

 if (resposta_alunos == NULL){
    printf("Memoria insuficiente.\n");
    exit(1);
 }
 
printf("digite o gabarito\n");

for(cont = 0;cont<numero_de_questoes;cont++){
scanf("%d",&gabarito[cont]);

}
printf("\n================================================================\n\n");
for(qtd_alunes = 0;qtd_alunes<cost;qtd_alunes++){
soma_pontos = 0;
printf("digite suas respostas aluno n %d°\n",qtd_alunes + 1);

for(cont = 0;cont<numero_de_questoes;cont++){
    printf("resposta n %dº\n",cont +1);
    scanf("%d",&resposta_alunos[cont]);

if (gabarito[cont] == resposta_alunos[cont]){
    soma_pontos+=10;
}
}

media  = soma_pontos/numero_de_questoes;

if (media >= 6.0)
{
        qtd_alunes_passarao++;
}

printf("a nota obtida foi : %.1f\n",media);
printf("\n================================================================\n\n");
}
percentual = (qtd_alunes_passarao * 100)/cost;
printf("a porcentagem de aprovação foi : %.0f%%\n",percentual);

printf("\n================================================================\n");
free(gabarito);
free(resposta_alunos);
    return(0);
}
