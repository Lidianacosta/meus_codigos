#include<stdio.h>

int soma (int a ,int b){ // funçao para calcular dois numeros 
 return(a+b); // retornando a soma dos valores 
}

int calcula (int x, int y, int (*operacao)(x,y)){    // funçao que chamar a funçao soma, esta recebendo dois numeros inteiros e uma ponteiro(endereço)da funçao 

 return ((*operacao)(x,y)); // chamando a funçao no return passando os dois inteiros 

} 

int main(){

printf("digite os numeros para fazer a somatoria!\n");
int t,tt;

scanf("%d %d",&t,&tt);

 int resultado = calcula(t,tt,soma); // chamndoa funçao calcua passando dois inteiros e a funçao soma como parametros

 printf("resultado: %d\n",resultado); // imprimindo o resultado
    return (0);
}
