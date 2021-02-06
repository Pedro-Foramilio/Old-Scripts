// Faça um programa que leia um inteiro N da entrada padrão. 
// Na sequência leia N números inteiros e imprima SIM se os números estão em ordem crescente e NAO caso contrário. 
// Você não deve utilizar vetores para resolver esse exercício.

// Obs: não esqueça de imprimir a quebra de linha após o SIM e NÃO.

#include <stdio.h>

int main() {
    int ordenados = 1;
    int n, numero, anterior;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &numero);
        if (i == 0) {
            anterior = numero;
        }
        if (anterior > numero) {
            ordenados = 0;
        }
        anterior = numero;
    }

    if (ordenados) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }

    return 0;
}
