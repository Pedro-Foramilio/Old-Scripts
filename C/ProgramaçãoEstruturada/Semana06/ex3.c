/*
Cria uma função que procura um trecho de texto na frase e cria uma nova string com todo o conteúdo 
da frase a partir do trecho indicado. Por exemplo, para frase="Frase de teste." e trecho="de", a função deve criar 
uma nova string "de teste.". A função deve retornar NULL se não encontrar o trecho na frase. A função deve retornar uma nova 
string e não deve alterar o vetor com a frase passada para a função.

A função deve ter o seguinte protótipo:

char* avanca_palavra(char *frase, char *trecho)


Importante: submeta apenas a função. Não use variáveis globais. Não inclua o main. 
Não use printf/puts/fscanf/fprintf e headers adicionais (por exemplo, stdio.h). Neste exercício, pode usar stdlib.h.
*/
#include <stdio.h>
#include <stdlib.h>

char *avanca_palavra(char *frase, char *trecho) {
    int tamanhoTrecho = 0;
    int tamanhoFrase = 0;
    int inicio = 0;
    int booleano;

    while(trecho[tamanhoTrecho] != '\0') {
        tamanhoTrecho++;
    }
    while(frase[tamanhoFrase] != '\0') {
        tamanhoFrase++;
    }

    int percursor = 0;
    char trechoAtual[tamanhoTrecho];
    while (percursor < tamanhoFrase) {
        
        for (int i = 0; i < tamanhoTrecho; i++) {
            trechoAtual[i] = frase[percursor + i];
        }

        booleano = 1;
        for (int i = 0; i < tamanhoTrecho; i++){
            if (trechoAtual[i] != trecho[i])
                booleano = 0;
        }

        if (booleano) {
            inicio = percursor;
            percursor = tamanhoFrase;
        }
        
        percursor++;
    }

    if (! booleano) {
        return NULL;
    }

    int tamanhoFinal = tamanhoFrase - inicio;
    char *fraseFinal = malloc(tamanhoFinal * sizeof(char));

    percursor = 0;
    for (int i = inicio; i < tamanhoFrase; i++){
        fraseFinal[percursor] = frase[i];
        percursor++;
    }
    puts("frase final\0");
    puts(fraseFinal);
    return fraseFinal;
}

int main() {
    char frase[16] = "Frase de teste.\0";
    char trecho[3] = "de\0";
    char *oi = avanca_palavra(frase, trecho);
    puts(oi);

    return 0;
}
