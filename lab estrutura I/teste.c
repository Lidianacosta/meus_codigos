#include<stdio.h>

int soma (int a ,int b){
 return(a+b);
}

int calcula (int x, int y, int (*operacao)(x,y)){

 return ((*operacao)(x,y));

} 

int main(){

printf("digite os numeros para fazer a somatoria!\n");
int t,tt;

scanf("%d %d",&t,&tt);

 int resultado = calcula(t,tt,soma);

 printf("resultado: %d\n",resultado);
    return (0);
}
