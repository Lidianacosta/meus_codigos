// Cóodigo 1 - Fibonacci

#include <stdio.h>

int fibonacci(int n){
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
int main(){
    fibonacci(15);
}

/*

a) Depure o c´odigo para descobrir quantas vezes o fibonacci(5) ´e calculado (requisitado).
resposta: b fib if n == 5 , c ate acaba depois info b fib
b) Descubra atrav´es da depura¸c˜ao, qual a maior quantidade de n´ıveis (frames) esse c´odigo alcan¸ca.
reposta: b 7 if n == 1 , fin , bt
c) Depure o c´odigo at´e o momento que o primeiro fibonacci(14) ´e calculado e o execut´avel ir´a come¸car
a calcular o fibonacci(13).
resposta: b main s ate n = 14 quase entrando na função 

*/