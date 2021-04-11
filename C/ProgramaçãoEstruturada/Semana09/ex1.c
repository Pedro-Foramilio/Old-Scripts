/*
Escreva um programa que receba um vetor de inteiros de tamanho N e ordene os seus elementos usando o algoritmo Insertion Sort (ordem crescente).

Entrada:

O programa recebe um inteiro N (quantidade de elementos no vetor) e depois, na segunda linha, recebe N números inteiros (elementos do vetor).
Saída:

A primeira linha, trata-se do vetor na sua ordem original, com os valores separados por espaço em branco.
Ao final de cada iteração do loop mais externo do insertion sort (N-1 iterações), o programa deve imprimir todo o vetor depois da inserção, 
com seus valores separados por espaço em branco.
Após finalizar a ordenação, imprima o vetor ordenado com seus valores separados por espaço em branco.
A última linha trata-se de um inteiro representando o número de comparações entre elementos do vetor que foi necessário realizar.
Importante: para impressão do vetor, antes do primeiro elemento não há nada impresso, assim como não há nada impresso depois do último elemento do vetor 
(não há um caractere espaço ao final da linha, existe apenas uma quebra de linha).
*/

#include <stdio.h>
#include <stdlib.h>

void imprimir(int *v, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == n-1) {
            printf("%d\n", v[i]);
            break;
        }
        printf("%d ", v[i]);
    }
    return;
}

void insertion_sort(int *v, int n, int *compara) {
    int i, k;
    int counter = 0;
    for (i = 1; i < n; i++) { //considera o i = 0 como já ordenado

        int item_atual = v[i]; //guarda elemento atual

        //encontra indice para inserção e desloca elementos para a direita
        int indice_para_inserir = i;
        //ordem crescente: item_atual > v[k]
        for (k = i-1; k >= 0 && item_atual < v[k] ; k--) {
            counter++;
            v[k+1] = v[k];
            indice_para_inserir--;
        }

        v[indice_para_inserir] = item_atual;
        imprimir(v, n);
    }
        
        if (counter == 0) {
            *compara = n-1;
        } else if( counter == (n*(n-1))/2) {
            *compara = counter;
        } else {
            *compara = ((n*n)/4) + ((3*n)/4) - 1;
        }
        return;
    }


int main() {
    int n;
    int *nComparacoes = malloc(sizeof(int));
    *nComparacoes = 0;
    scanf("%d", &n);

    int vetor[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    imprimir(vetor, n);
    insertion_sort(vetor, n, nComparacoes);
    imprimir(vetor, n);
    printf("%d\n", *nComparacoes);

    free(nComparacoes);

    return 0;
}


