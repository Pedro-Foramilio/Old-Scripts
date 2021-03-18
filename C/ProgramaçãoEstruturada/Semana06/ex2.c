/*
Escreva a função duplica_impares, que recebe um vetor de inteiros (v) de comprimento n_entrada 
e retorna outro vetor com todos os números ímpares duplicados. A função também retorna (por referência) a quantidade 
de elementos no vetor retornado (n_retorno). Observação: a função deve retornar um novo vetor e não alterar o vetor de entrada (v).

Protótipo da função:

int* duplica_impares(int *v, int n_entrada, int *n_retorno);

Importante: submeta apenas a função. Não use variáveis globais. Não inclua o main. 
Não use printf/puts e headers adicionais (por exemplo, stdio.h). Neste exercício, pode usar stdlib.h.
*/

//#include "vetor.h"
#include <stdlib.h>

int ehImpar(int numero) {
    return (numero % 2 != 0);
}

int *duplica_impares(int *v, int n_entrada, int *n_retorno) {

    int qtdImpares = 0;
    for (int i = 0; i < n_entrada; i++) {
        if (ehImpar(v[i]))
            qtdImpares++;
    }

    *n_retorno = n_entrada + qtdImpares;
    int *vetorSaida = calloc(*n_retorno, sizeof(int));

    for (int i = 0; i < n_entrada; i++) {
        vetorSaida[i] = v[i];
    }

    int contador = 0;
    for (int i = 0; i < *n_retorno; i++) {
        if (contador == *n_retorno){break;}
        if (ehImpar(vetorSaida[contador])) {
            for (int j = *n_retorno-1; j > contador; j--) {
                vetorSaida[j] = vetorSaida[j-1];
            }
            vetorSaida[contador+1] == vetorSaida[contador];
            contador++;
        }
        contador++;
    }
    return vetorSaida;
}

