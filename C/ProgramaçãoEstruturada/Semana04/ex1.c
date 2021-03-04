/*
Desenvolva uma função recursiva contafreq que recebe dois números naturais e indique a 
frequência com que o segundo número aparece no primeiro. O segundo número sempre será menor do que 10.

Por exemplo, contafreq(12343, 3) = 2.

A sua função deverá ter o seguinte protótipo:

int contafreq(int num, int digito);
Importante: submeta apenas a função. Não use variáveis globais. 
Não inclua o main e não use printf/puts nas funções submetidas.
*/

//#include "contafreq.h"
#include <stdio.h>

int contafreq(int num, int digito) {
    if (num == 0) return 0;
    
    int qtdDigitos = 0;
    int numero = num;
    while (numero != 0) {
        numero = numero / 10;
        qtdDigitos++;
    }
    
    int divisor = 1;
    for (int i = 0; i < qtdDigitos-1; i++) {
        divisor = divisor * 10;
    }

    if (digito == num / divisor)
        return 1 + contafreq(num%divisor, digito);
    else
        return 0 + contafreq(num%divisor, digito);
    
  
}

int main() {
    int contagem = contafreq(122322, 2);
    printf("contagem = %d\n", contagem);
    return 0;
}
