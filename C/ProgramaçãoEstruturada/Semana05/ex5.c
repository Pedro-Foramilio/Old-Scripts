/*
Escreva uma função que recebe um texto e uma largura de linha. A função deve calcular a 
quantidade de linhas necessárias para imprimir o texto passada para a função. 
O retorno da quantidade de linhas será por referência, no parâmetro qtd_linhas.

Algumas regras importantes para o cálculo da quantidade de linhas:

as palavras não podem ser separadas. Portanto, se não tiver espaço disponível 
para incluir uma palavra em uma linha, ela deverá ser incluída na próxima. 
Por exemplo, para o texto "Frase teste" e largura de linha 8, a divisão seria em duas 
linhas "Frase" e "teste" (não há espaço na primeira linha para incluir "Frase teste". 
Se a largura de linha for 11, apenas uma linha é suficiente.

toda linha deve iniciar com uma letra, ou seja, nenhuma linha deve iniciar com o caractere espaço 
ou com pontuação (ponto, vírgula, etc). Se algum sinal de pontuação ficar exatamente após uma 
quebra de linha, a palavra que precede o sinal deve ser passada para a próxima linha, 
de forma que nenhuma linha inicie com pontuação. Por exemplo, para o texto 
"Neste teste, a frase possui pontuacao." e largura de linha 11, a divisão seria em cinco linhas: 
"Neste", "teste, a", "frase", "possui", "pontuacao."

um caractere espaço que fique exatamente após uma quebra de linha deve ser suprimido, 
de forma que a próxima linha inicie com uma palavra (e não com um caractere espaço). 
Por exemplo, para o texto "Texto para teste ABCD" e largura 10, a divisão seria em duas linhas: 
"Texto para" e "teste ABCD".
*/

//#include "conta_linhas_texto.h"

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
                *qtd_linhas++;
            } else {
                *qtd_linhas++;
                int palavra = j - ultimo_espaco+1;
                tamanho -= palavra;
            }

            contador = -1;
        }
        contador++;
        j++;
    }

}
