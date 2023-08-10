// C´odigo 3 - N´umeros primos

#include <stdio.h>

// Funcao recursiva para verificar se um numero e primo
int ehPrimoRecursivo(int n, int i){
    if (n <= 2)
        return (n == 2);

    if (n % i == 0)
        return 0;

    if (i * i > n)
        return 1;

    return ehPrimoRecursivo(n, i + 1);
}

// Funcao para imprimir numeros primos em um intervalo
void imprimirPrimosIntervalo(int inicio, int fim)
{
    if (inicio > fim)
        return;

    if (ehPrimoRecursivo(inicio, 2))
        printf("%d ", inicio);

    imprimirPrimosIntervalo(inicio + 1, fim);
}

int main()
{
    int inicio, fim;

    printf(" Digite o inicio do intervalo : ");
    scanf("%d", &inicio);

    printf(" Digite o fim do intervalo : ");
    scanf("%d", &fim);

    printf(" Numeros primos entre %d e %d: ", inicio, fim);
    imprimirPrimosIntervalo(inicio, fim);
    printf("\n");

    return 0;
}

/*

a) Atrav´es da depura¸c˜ao, compreenda como o c´odigo funciona.
b) Desenhe em formato de uma ´arvore de recurs˜ao os passos para o c´alculo da procura dos n´umeros
primos de 10 a 20 (usando a depura¸c˜ao).
c) Conte a quantidade de chamadas recursivas para realizar o resultado de b).
d) Depure o algoritmo com os valores de entrada de 1000 e 10000. Utilize o depurador para interromper a depura¸c˜ao quando o 240º n´umero primo aparecer.

*/