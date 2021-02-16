/*
implemente a função imprime_vetor, que recebe um vetor de números inteiros. A função deve imprimir o vetor em forma de triângulo. Por exemplo, o vetor 1, 2, 3, 4, 5, 6 seria impresso como:

1
2 3
4 5 6

Observação: há um caractere espaço separando cada número por linha, mas não há um caractere espaço ao final de cada linha (após o último número).

A função deve seguir o seguinte protótipo:

void imprime_vetor(int vetor[], int qtd);

Importante: submeta apenas a função. Não inclua o main.
*/

#include <stdio.h>
#include "imprime_vetor.h"

void imprime_vetor(int vetor[], int qtd) {
    int linha = 1;
    int contador = 0;
    while (contador < qtd) {
        for (int i = 0; i < linha; i++) {
            if (contador == qtd) {
                break;
            }
            
            if (i == linha-1) {
                printf("%d\n", vetor[contador]);
            } else {
                printf("%d ", vetor[contador]);
            }
            contador++;
        }
        linha++;
    }
}

