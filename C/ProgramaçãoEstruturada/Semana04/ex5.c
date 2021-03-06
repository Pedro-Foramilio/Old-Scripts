/*
Implemente uma função recursiva chamada multiplicacao_russa que recebe dois números inteiros e \
retorne a sua multiplicação. Utilize o método de multiplicação à Russa ou multiplicação Etíope. 
Uma descrição informal do método é:

    1. Escreva os números A e B, que se deseja multiplicar na parte superior das colunas.

    2. Dividir A por 2, sucessivamente, ignorando o resto até chegar à unidade, 
        escrever os resultados da coluna A.

    3.Multiplicar B por 2 tantas vezes quantas se haja dividido A por 2, 
        escrever os resultados sucessivos na coluna B.
    4.Somar todos os números da coluna B que estejam ao lado de um número ímpar da coluna A.

Sua função deve ter o seguinte protótipo:

    int multiplicacao_russa(int a, int b);
Importante: submeta apenas a função. Não use variáveis globais. Não inclua o main e não use printf/puts nas funções submetidas.
*/

//#include "multiplicacao.h"
#include <stdio.h>

int multiplicacao_russa(int a, int b) {
    if (a == 1)
        return b;

    if (a % 2 != 0)
        return b + multiplicacao_russa( (int) a/2, 2 * b);
    else
        return multiplicacao_russa((int) a/2, 2 * b);
}

int main() {

    printf("%d\n", multiplicacao_russa(123, 21));

    return 0;
}