/*
Escreva um programa que lerá duas matrizes A e B e depois imprime o resultado da multiplicação das matrizes.

Entrada:

n_linhas_A n_colunas_A
dados da matriz A (linha por linha)
n_linhas_B n_colunas_B
dados da matriz B (linha por linha)
Saída:

matriz resultado da multiplicação A x B


Importante: utilize malloc para alocar vetores ou matrizes (não declare vetor ou matriz com colchetes).
Para acessar as posições no vetor, pode usar colchetes neste exercício. Não use variáveis globais.

Lembre-se de liberar toda memória alocada com malloc/calloc!
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    //ALOCAR A
    int n_linhas_A;
    int n_colunas_A;
    scanf("%d %d", &n_linhas_A, &n_colunas_A);

    int **matriz_A = malloc(sizeof(int *) * n_linhas_A);
    for (int i = 0; i < n_linhas_A; i++) {
        matriz_A[i] = malloc(sizeof(int) * n_colunas_A);
    }

    for (int i = 0; i < n_linhas_A; i++) {
        for (int j = 0; j < n_linhas_A; j++) {
            scanf("%d", &matriz_A[i][j]);
        }
    }

    //================================================================
    //================================================================
    //ALOCAR B
    int n_linhas_B;
    int n_colunas_B;
    scanf("%d %d", &n_linhas_B, &n_colunas_B);

    int **matriz_B = malloc(sizeof(int *) * n_linhas_B);
    for (int i = 0; i < n_linhas_B; i++) {
        matriz_B[i] = malloc(sizeof(int) * n_colunas_B);
    }

    for (int i = 0; i < n_linhas_B; i++) {
        for (int j = 0; j < n_linhas_B; j++) {
            scanf("%d", &matriz_B[i][j]);
        }
    }

    //================================================================
    //================================================================
    // A x B
    /*
    int n_linhas_A = 2;
    int n_colunas_A = 3;
    int matriz_A[2][3] = {{1, 2, 3},{4, 5, 6}};
    int n_linhas_B = 3;
    int n_colunas_B = 4;
    int matriz_B[3][4] ={{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};
    */


    int linhasResultado = n_linhas_A;
    int colunasResultado = n_colunas_B;

    int **resultado = malloc(sizeof(int *) * linhasResultado);
    for (int i = 0; i < n_linhas_A; i++) {
        resultado[i] = malloc(sizeof(int) * colunasResultado);
        for (int j = 0; j < colunasResultado; j++) {
            resultado[i][j] = 0;
        }
    }

    int a, b, c;
    for (a = 0; a < n_linhas_A; a++) {
        for (b = 0; b < n_colunas_B; b++) {
            for (c = 0; c < n_colunas_A; c++) {
                resultado[a][b] += matriz_A[a][c] * matriz_B[c][b];
            }
        }
    }

    //================================================================
    //================================================================
    //IMPRESSAO
    for (int i = 0; i < linhasResultado; i++) {
        for (int j = 0; j < colunasResultado; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    //================================================================
    //================================================================
    //LIBERAR
    for (int i = 0; i < n_linhas_A; i++) {
        free(matriz_A[i]);
    }
    free(matriz_A);

    for (int i = 0; i < n_linhas_B; i++) {
        free(matriz_B[i]);
    }
    free(matriz_B);

    for (int i = 0; i < linhasResultado; i++) {
        free(resultado[i]);
    }
    free(resultado);

    return 0;
}
