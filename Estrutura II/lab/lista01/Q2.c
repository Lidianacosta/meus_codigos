// C´odigo 2 - Opera¸c˜ao Matem´atica

#include <stdio.h>

// Funcao para calcular algo
int operacaoMatematica(int a, int b)
{
    int r;

    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int num1, num2;

    printf(" Digite o primeiro numero : ");
    scanf("%d", &num1);

    printf(" Digite o segundo numero : ");
    scanf("%d", &num2);

    int res = operacaoMatematica(num1, num2);

    printf("A operacao de %d e %d e: %d\n", num1, num2, res);

    return 0;
}

/*

a) Execute o algoritmo em modo de depura¸c˜ao.
resposta: start, n, display a, b, r;
b) Descubra atrav´es da depura¸c˜ao, qual a maior profundidade de (frames) esse c´odigo alcan¸ca.
reposta: depende da entrada, num1 e num2
c) Descubra o que ocorre quando um parˆametro ´e 0.
reposta: quando a = 0 res é b  quando b = 0 res = a
d) Descubra o que ocorre quando os dois parˆametros apresentados s˜ao iguais e maiores que 1.
resposta: res = a ou b já que são ihuais 

*/