// Questão 1) A Nlogônia é um país tropical, com muitas belezas naturais internacionalmente
// famosas; dentre elas, encontram-se as belas praias que compõem o arquipélago do país, que
// todo verão recebem milhões de turistas estrangeiros.
// O Ministério do Turismo da Nlogônia está preparando o país para a chegada dos turistas, mas,
// para fazer seu planejamento, precisa saber a extensão da costa nlogônica. Para isso, ele gerou
// um mapa que divide o território nacional em vários quadrados, que podem ser ocupados por
// água ou por terra; considera-se que um quadrado é parte da costa nlogônica se ele é um
// quadrado ocupado por terra que tem um lado em comum com um quadrado ocupado por
// água.
// Como a Nlogônia é um país muito grande, o ministro do turismo pediu que você escrevesse um
// programa que, dado o mapa da Nlogônia, determina a extensão da costa nlogônica.
// Entrada
// A primeira linha da entrada contém dois inteiros M e N indicando, respectivamente, o número
// de linhas e o número de colunas do mapa. Cada uma das M linhas seguintes contém N
// caracteres: um caractere ‘.’ indica que aquele quadrado do território é ocupado por água; um
// caractere ‘#’ indica que aquele quadrado do território é ocupado por terra.
// Considere que todo o espaço fora da área do mapa é ocupado por água.
// Saída
// Seu programa deve imprimir uma única linha contendo um único inteiro, indicando quantos
// quadrados do território fazem parte da costa da Nlogônia.
// Restrições
// ? 1 = M, N = 1000.

#include<stdio.h>
#include<stdlib.h>
                
void pedir_o_mapa(int m,int n, char **matriz);

void verifica_costa(int m ,int n,char **matriz);

int main(void){

    int m,n,cont;
    printf("digite o numero de linhas e colunas\n");
   
    scanf("%d %d",&m,&n);

    char **mapa = (char**)malloc(m*sizeof(char*));

    if(mapa == NULL) {
        printf("erro");
        exit(1);
    }

    for(cont = 0; cont < m; cont++) {
        mapa[cont] = (char*)malloc(n*sizeof(char));     
        if(mapa[cont] == NULL) {
        printf("erro");
        exit(1);
        }
    }

    pedir_o_mapa(m,n,mapa);
    verifica_costa(m,n,mapa);

    for(cont = 0; cont < m; cont++) {
        free(mapa[cont]);
    }

 free(mapa);
    return(0);
}

void pedir_o_mapa(int m,int n, char **matriz){
 int linha ,coluna;
    printf("mostre como e seu mapa digite '.' para mar e '#'para terra\n");
    for(linha = 0; linha<m ;linha++){
    scanf(" %[^\n]s",matriz[linha]);
    }
}

void verifica_costa(int m ,int n,char **matriz){

  int linha ,coluna,soma_costas = 0;

    for(linha = 0;linha<m;linha++){
         for(coluna = 0;coluna<n;coluna++){
           if(matriz[linha][coluna] == '#'){
                if (linha != (m-1) && linha != 0 && coluna != (n-1) && coluna != 0){
                    if (matriz[linha][coluna +1] == '.' || matriz[linha][coluna -1] == '.' || matriz[linha + 1][coluna] == '.' || matriz[linha - 1][coluna] == '.'){
                        soma_costas++;
                    }
                }else if (linha == (m-1)){
                    if(coluna != 0 && coluna != (n-1)){
                        soma_costas++;
                    }else if(coluna == 0){
                        soma_costas++;
                    }else if(coluna == (n-1)){
                        soma_costas++; 
                    }
                }else if (linha == 0){  
                    if(coluna != (n-1) && coluna != 0){
                        soma_costas++;
                    }else if(coluna == 0){
                        soma_costas++;
                    }else if(coluna == (n-1)){
                        soma_costas++;
                    }     
                }
            }
        }
    }
    printf("a quantidade de costas e : ");
    printf(" %d",soma_costas);
}
