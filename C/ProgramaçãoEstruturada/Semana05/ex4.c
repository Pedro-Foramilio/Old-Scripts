/*
Escreva uma função que recebe uma frase e retorne o valor de algumas estatísticas 
sobre os comprimentos das palavras na frase. O retorno será realizado por parâmetros 
passados por referência. As frases podem conter pontuação.

Protótipo da função:
void estatisticas_frase(char frase[], int *min, int *max, int *soma, double *media, double *desvio);
Valores que devem ser retornados:

min: comprimento da menor palavra
max: comprimento da maior palavra
soma: soma dos comprimentos de todas as palavras
media: média dos comprimentos das palavras
desvio: desvio padrão (std) dos comprimentos das palavras, conforme fórmula a seguir, 
em que xi é o comprimento de palavra i e n é a quantidade de palavras na frase:
*/

//#include "frase.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void estatisticas_frase(char frase[], int *min, int *max, int *soma, double *media, double *desvio) {
    int tamanho = 0;
    int qtdEpacos = 0;
    *min = 100;
    *max = 0;
    *soma = 0;

    while (frase[tamanho] != '\0') {
        tamanho++;
        if (frase[tamanho] == ' ') {
            qtdEpacos++;
        }
    }

    int posicoesEspacos[qtdEpacos+1];
    int percursor = 0;
    int i = 0;
    for ( i = 0; i < tamanho; i++) {
        if (frase[i] == ' ') {
            posicoesEspacos[percursor] = i;
            percursor++;
        }
    }
    posicoesEspacos[qtdEpacos] = tamanho;

    i = 0;
    percursor = 0;
    int inicio = 0;
    int fim;
    int tamanhoPalavra = 0;
    while(percursor < qtdEpacos) {

        fim = posicoesEspacos[percursor]-1;

        if (frase[fim] == ',' || frase[fim] == '.' || frase[fim] == ':') {
            fim--;
        }
        if (frase[inicio] == ',' || frase[inicio] == '.' || frase[fim] == ':') {
            inicio++;
        }
        for (int k = inicio; k <= fim; k++){
            tamanhoPalavra++;
        }
        *soma += tamanhoPalavra;

        if (tamanhoPalavra > *max) {
            *max = tamanhoPalavra;
        }
        if (tamanhoPalavra < *min) {
            *min = tamanhoPalavra;
        }

        tamanhoPalavra = 0;
        inicio = posicoesEspacos[percursor] + 1;
        percursor++;
    }
    inicio =  posicoesEspacos[qtdEpacos-1]+1 == ',' || posicoesEspacos[qtdEpacos-1]+1 == '.' || posicoesEspacos[qtdEpacos-1]+1 == ':' 
                ? posicoesEspacos[qtdEpacos-1]+2 : posicoesEspacos[qtdEpacos-1]+1;
    fim = tamanho;
    tamanhoPalavra = 0;

    for (int k = inicio; k <= fim; k++){
        tamanhoPalavra++;
    }
    *soma += tamanhoPalavra;
    if (tamanhoPalavra > *max) {
        *max = tamanhoPalavra;
    }
    if (tamanhoPalavra < *min) {
        *min = tamanhoPalavra;
    }
    *media = (double) *soma / (double) (qtdEpacos+1);
    tamanhoPalavra = 0;
//-----------------------------------------------------------------------------------
    double std = 0;
    double s = 0;

    i = 0;
    percursor = 0;
    inicio = 0;
    fim = 0;
    while(percursor < qtdEpacos) {

        fim = posicoesEspacos[percursor]-1;

        if (frase[fim] == ',' || frase[fim] == '.' || frase[fim] == ':') {
            fim--;
        }
        if (frase[inicio] == ',' || frase[inicio] == '.' || frase[fim] == ':') {
            inicio++;
        }
        for (int k = inicio; k <= fim; k++){
            s++; 
        }
        std += (s - *media) * (s - *media);
        s = 0;

        tamanhoPalavra = 0;
        inicio = posicoesEspacos[percursor] + 1;
        percursor++;
    }
    inicio =  posicoesEspacos[qtdEpacos-1]+1 == '.' || posicoesEspacos[qtdEpacos-1]+1 == '.' || posicoesEspacos[qtdEpacos-1]+1 == ':'
                ? posicoesEspacos[qtdEpacos-1]+2 : posicoesEspacos[qtdEpacos-1]+1;
    fim = tamanho;
    tamanhoPalavra = 0;

    for (int k = inicio; k <= fim; k++){
        s++;
    }
    std += (s - *media) * (s - *media);
    std = (1 /(double) qtdEpacos+1) * std;
    *desvio = sqrt(std);
}

int main() {

    char frase[34] = "Frase de teste\0";
    int *min = calloc(1, sizeof(int));
    int *max = calloc(1, sizeof(int));
    int *soma = calloc(1, sizeof(int));
    double *media = calloc(1, sizeof(double));
    double *desvio = calloc(1, sizeof(double));

    estatisticas_frase(frase, min, max, soma, media, desvio);


    free(media);
    free(desvio);
    free(soma);
    free(max);
    free(min);
    return 0;
}
