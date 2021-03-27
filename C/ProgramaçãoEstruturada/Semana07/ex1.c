/*
Escreva as funções cria_matriz e liberar_matriz.

A função cria_matriz deve alocar e retornar uma matriz com as dimensões especificadas nos parâmetros n_linhas e n_colunas. 
A matriz deve ser preenchida com zeros e uns de forma intercalada, conforme o exemplo a seguir (n_linhas=3 e n_colunas=4):

0 1 0 1
1 0 1 0
0 1 0 1


A função liberar_matriz recebe o ponteiro para uma matriz e deve liberá-la da memória (free).



Protótipos das funções:

double **cria_matriz(int n_linhas, int n_colunas);
void liberar_matriz(double **matriz, int n_linhas);


Importante: submeta apenas as funções. Não use variáveis globais. Não inclua o main. Não use printf/puts/fprintf/fscanf e 
headers adicionais (por exemplo, stdio.h). Neste exercício, pode usar stdlib.h.



Formato do caso de teste: esse é o formato dos casos de teste que aparecem ao avaliar a atividade; não inclua impressão de dados no código, 
essa impressão é feita automaticamente pelo sistema de correção de acordo com o retorno da função submetida.
*/

//#include "matriz.h"
#include <stdlib.h>

double **cria_matriz(int n_linhas, int n_colunas) {
    //aloca matriz
    int filling;
    double **matriz = malloc(sizeof(double *) * n_linhas);

    for (int i = 0; i < n_linhas; i++) {

        matriz[i] = malloc(sizeof(double) * n_colunas);
        filling = 0 + (i % 2);
        for (int j = 0; j < n_colunas; j++) {
            //preencher matriz
            matriz[i][j] = (filling + j) % 2;
        }
    }

    return matriz;
}

void liberar_matriz(double **matriz, int n_linhas) {
    for (int i = 0; i < n_linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
