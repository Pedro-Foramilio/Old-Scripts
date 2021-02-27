/*
Implemente uma função que receba uma string 
(vetor de caracteres) contendo uma frase e remova a palavra de índice i do vetor passado no parâmetro frase da função. 
Considere que a primeira palavra tem índice 1. Ao remover uma palavra, é necessário remover caracteres espaço adjacentes à palavra removida. 
A string de entrada possui no máximo 100 caracteres e pode conter pontuação.

Importante: submeta apenas a função. Não use variáveis globais. Não inclua o main. Não use printf/puts e não use string.h.
*/

//#include "remover_palavra.h"
#include <stdio.h>

void remover_palavra(int i, char frase[]) {
    int tamanho = 0;
    int inicio = 0;
    int final = 0;
    int qtdEpacos = 0;
    int j = 0;
    
    while (frase[tamanho] != '\0'){
        tamanho++;
    }

    while (j < tamanho) {
        if (frase[j] == ' ') {
            qtdEpacos++;
            if (qtdEpacos == i - 1) {
                inicio = j;
                break;
            }
        }
        j++;
    }

    final = inicio + 1;
    while (frase[final] != ' ' && frase[final] != '\0' && frase[final] != '.' 
            && frase[final] != ',' && frase[final] != ';' && frase[final] != '\n') {
        final++;
    }

    if (i == 1) {
        final++;
    }

    for (int k = inicio; k <= tamanho; k++) {
        frase[k] = frase[final];
        final++;
    }
}

int main() {
    char frase[100] = "Neste exercicio, a funcao envolve uso de string.\0";
    remover_palavra(2, frase);
    puts(frase);
}
