
#include <stdio.h>
#include <stdlib.h>

int main() {
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
}