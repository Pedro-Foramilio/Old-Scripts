
#include <stdio.h>
#include <stdlib.h>

int main() {
    /*
    int *qtd = malloc(sizeof(int));
    *qtd = 0;

    printf("qtd = %p, *qtd = %d\n", qtd, *qtd); // qtd = 007318C0, *qtd = 0
    (*qtd)++;
    printf("qtd = %p, *qtd = %d\n", qtd, *qtd); // qtd = 007318C0, *qtd = 1
    *qtd++;
    printf("qtd = %p, *qtd = %d\n", qtd, *qtd); // qtd = 007318C4, *qtd = 7536832
    *++qtd;
    printf("qtd = %p, *qtd = %d\n", qtd, *qtd); // qtd = 007318C8, *qtd = -1797823864
    ++*qtd;
    printf("qtd = %p, *qtd = %d\n", qtd, *qtd); // qtd = 007318C8, *qtd = -1797823863
    */

   int *vetor = calloc(5, sizeof(int));
    for (int i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++){
        printf("%p ", &vetor[i]);
    }
}