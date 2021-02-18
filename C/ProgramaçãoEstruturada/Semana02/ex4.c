/*
Implemente a função remover_duplicados, que recebe um vetor de números inteiros positivos organizados em ordem crescente. A função deve eliminar o mínimo de elementos para que o vetor não contenha nenhum valor positivo repetido. Ao eliminar um elemento, os elementos à diretia serão deslocados à esquerda e será adicionado um valor -1 na última posição.

Por exemplo, para uma lista com os elementos 1, 2, 2, 2, 3, 3, 4, 8, 10, 10, a função deixará a lista com os elementos 1, 2, 3, 4, 8, 10, -1, -1, -1, -1.

Observação: a função deve alterar o vetor passado como argumento para a função.

A função deve seguir o seguinte protótipo (qtd é a quantidade de elementos no vetor):

void remover_duplicados(int vetor[], int qtd);

Importante: submeta apenas a função. Não inclua o main e não use printf/puts.

Formato da entrada no caso de teste (que aparece ao avaliar a atividade):

7 (tamanho do vetor)
11 22 22 33 44 44 55 (elementos do vetor)
*/

//#include "remover_duplicados.h"

void remover_duplicados(int vetor[], int qtd) {

  for (int i = 0; i < qtd; i++) {
    for (int j = 0; j < qtd; j++) {

      if (j == i) {
        continue;
      }

      if (vetor[j] == vetor[i]) {
        vetor[j] = -1;
      }
    }
  }

  int aux = 0;
  for (int i = qtd; i > 0; i--) {
    for (int j = 0; j < i -1; j++) {
      if (vetor[j] == -1) {
        aux = vetor[j];
        vetor[j] = vetor[j+1];
        vetor[j+1] = aux;
        aux = 0;
      }
    }
  }
}
