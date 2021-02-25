/*
Escreva uma função que receba uma matriz com n x n números inteiros e 
verifica se a matriz satisfaz a seguinte regra: cada linha e cada coluna contém exatamente um elemento diferente de zero.

A função retorna 1, em caso positivo, ou 0, caso contrário.
*/

//#include "matriz1.h"

int verifica_matriz(int n, int matriz[n][n]) {
    // Escreva o código da função aqui
    // Observe como o parâmetro da matriz é definido:
    //   o parâmetro n é definido antes do parâmetro matriz, 
    //   pois a matriz utiliza n em sua definição
    int qtdZeros = 0;
    for (int i = 0; i < n; i++) {
        qtdZeros = 0;
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == 0)
                qtdZeros++;
        }
        if (qtdZeros != (n-1))
            return 0;
    }

    for (int j = 0; j < n; j++) {
        qtdZeros = 0;
        for (int i = 0; i < n; i++) {
            if (matriz[i][j] == 0)
                qtdZeros++;
        }
        if (qtdZeros != (n-1))
            return 0;
    }
    return 1;
}