/*
Implemente uma função que receba uma string (vetor de caracteres) 
contendo uma frase e retorne o tamanho (número de caracteres) da palavra de maior comprimento da frase.
Considere que a string de entrada possui no máximo 100 caracteres e não contém pontuações.


Importante: submeta apenas a função. Não use variáveis globais. Não inclua o main. Não use printf/puts.
*/

//#include "maior_palavra.h"

int comprimento_maior_palavra(char frase[]) {
    int tamanho = 0;
    while (frase[tamanho] != '\0'){
        tamanho++;
    }
    int maior = 0;
    int palavra = 0;
    for (int i = 0; i < tamanho; i++) {
        if (frase[i] == ' ' || frase[i] == '\n' || frase[i] == '\0') {
            if (palavra > maior) {
                maior = palavra;
            }
            palavra = 0;
            continue;
        }
        palavra++;
    }
    return maior;
}