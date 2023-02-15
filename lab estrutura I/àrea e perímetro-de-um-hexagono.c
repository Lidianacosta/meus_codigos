// Questão 4) Crie um programa para calcular a área e o perímetro de um hexágono. O seu
// programa deve implementar uma função chamada calcula_hexagono que calcula a área e o
// perímetro de um hexágono regular de lado l. A função deve obedecer ao seguinte protótipo:
// void calcula_hexagono(float l, float *area, float *perimetro); A área e o perímetro de um
// hexágono regular são dados, respectivamente, por:
//            A = (3*l*l*sqrt(3))/2
//            P = 6*l
//.

#include <stdio.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro); // funçâo.

int main()
{

    float A, P, l; // declarando as variaveis

    printf("digite o lado do hexagono\n"); // pedindo e lendo o lado do hexágono.
    scanf("%f", &l);

    calcula_hexagono(l, &A, &P); // chamada da função passando uma variavel simples e dois endereço.

    printf("A: %.2f  P: %.2f", A, P); // mostrando a área e perimetro ao úsuario.

    return (0);
}

void calcula_hexagono(float l, float *area, float *perimetro){// a função recebe a copia do conteudo e dois endereço para poder modificar o valor da variavel tbm na main.
    *area = (3 * pow(2, l) * sqrt(3)) / 2; // calculando a área e armazenando em A.
    *perimetro = 6 * l;                    // calculando a o perimetro e armazenando em P.
}
