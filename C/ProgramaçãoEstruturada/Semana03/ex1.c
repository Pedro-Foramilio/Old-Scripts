/*
Escreva uma função que receba uma matriz quadrada e verifique se a matriz é estritamente diagonal dominante por linhas.

Uma matriz A é estritamente diagonal dominante por linhas se 
o módulo do valor da diagonal é maior que a soma dos módulos dos demais valores da linha.
*/

//#include "diagonal_dominante.h"

int diagonal_dominante(int n, int m[][n]) {
    int somaColuna = 0;
    int diagonalAtual;
    for (int i = 0; i < n; i++) {
        diagonalAtual = m[i][i];
        
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            somaColuna += m[i][j];
        }

        if (diagonalAtual <= somaColuna) return 0;
        somaColuna = 0;
    }
    
}