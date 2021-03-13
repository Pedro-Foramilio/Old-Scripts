/*
Escreva uma função que recebe um vetor de inteiros de comprimento n e retorne o valor de 
algumas estatísticas sobre esses números. O retorno será realizado por parâmetros passados por referência.

Protótipo da função:
void estatisticas_vetor(int vetor[], int n, int *min, int *max, int *soma, double *media, double *desvio);
Valores que devem ser retornados:

min: menor valor
max: maior valor
soma: soma dos valores
media: média dos valores
desvio: desvio padrão (std) dos valores, conforme fórmula a seguir, 
em que xi é o valor i e n é a quantidade de valores:

Entrada:
quantidade de itens no vetor
itens do vetor
Saída:
valores das estatísticas após executar a função estatisticas_vetor
*/

//#include "vetor.h"
#include <math.h>

void estatisticas_vetor(int vetor[], int n, int *min, int *max, int *soma, double *media, double *desvio) {
    *min = vetor[0];
    *max = vetor[0];
    *soma = 0;
    *media = (double) 0.0;
    *desvio = (double) 0.0;
    
    for (int i = 0; i < n; i++) {
        *soma += vetor[i];
        if (vetor[i] > *max)
            *max = vetor[i];
        if (vetor[i] < *min)
            *min = vetor[i];
    }

    *media = (double) *soma / n;
    *desvio = 0;

    for (int i=0; i < n; i++) {
        *desvio += ((double) (vetor[i] - *media) * (vetor[i] - *media));
    }

    *desvio = *desvio * ((double) 1 / n);
    *desvio = sqrt(*desvio);

    return;
}
