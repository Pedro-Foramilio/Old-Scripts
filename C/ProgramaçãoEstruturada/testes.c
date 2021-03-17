
#include <stdio.h>
#include <stdlib.h>
/*
void conta_linhas(char texto[], int largura_linha, int* qtd_linhas) {
    *qtd_linhas = 0;

    int tamanho = 0;
    while (texto[tamanho] != '\0'){
        tamanho++;
    }

    int j = 0;
    int contador = 0;
    int ultimo_espaco;
    while (j < tamanho) {

        if (texto[j] == ' ') {
            ultimo_espaco = j;
        }

        if (contador == largura_linha) {
            
            if (texto[j+1] == ' ') {
                tamanho--;
                *qtd_linhas += 1;
            } else {
                *qtd_linhas += 1;
                int palavra = j - ultimo_espaco+1;
                tamanho -= palavra;
            }

            contador = -1;
        }
        contador++;
        j++;
    }

}

int main() {
    char frase[17] = "Este eh um teste\0";
    int *qtd_linha = malloc(sizeof(int));
    *qtd_linha = 0;
    conta_linhas(frase, 5, qtd_linha);

    printf("%d\n", *qtd_linha);
    free(qtd_linha);

    return 0;    
}
*/

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