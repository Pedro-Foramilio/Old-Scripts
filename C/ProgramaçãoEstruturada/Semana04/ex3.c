/*
Considere o superfatorial de um número N como o produto dos N primeiros fatoriais de N. 
Assim, o superfatorial de 4 é:

superfatorial(4) = 1! * 2! * 3! * 4! = 288

Faça uma função recursiva que receba um número inteiro positivo N e retorne o superfatorial desse número.

A função deve ter o seguinte protótipo:

long superfatorial(int n);

Importante: submeta apenas a função. Não use variáveis globais. 
Não inclua o main e não use printf/puts nas funções submetidas.

*/

//#include "superfatorial.h";
#include <stdio.h>

long fatorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * fatorial(n-1);
}

long superfatorial(int n) {
    if (n == 0)
        return 1;
    else 
        return fatorial(n) * superfatorial(n-1);

}

int main() {
    printf("%ld\n", superfatorial(4));

    return 0;
}
