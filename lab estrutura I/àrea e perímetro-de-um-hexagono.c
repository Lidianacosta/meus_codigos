// Questão 4) Crie um programa para calcular a área e o perímetro de um hexágono. O seu
// programa deve implementar uma função chamada calcula_hexagono que calcula a área e o
// perímetro de um hexágono regular de lado l. A função deve obedecer ao seguinte protótipo:
// void calcula_hexagono(float l, float *area, float *perimetro); A área e o perímetro de um
// hexágono regular são dados, respectivamente, por:
//            A = (3*l*l*sqrt(3))/2
//            P =6*l        
//


#include<stdio.h>
#include<math.h>


void calcula_hexagono(float l, float *area, float *perimetro);

int main(){

float A,P,l;

printf("digite o lado do hexagono\n");
scanf("%f",&l);

calcula_hexagono(l,&A,&P);

printf("A: %f P: %f",A,P);

    return(0);
}

void calcula_hexagono(float l, float *area, float *perimetro){


*area = (3*pow(2,l)*sqrt(3))/2;
*perimetro = 6*l ;


}
