/*
Implemente a função impares_pares, que recebe um ponteiro para o início de uma lista ligada. A função deve retornar a quantidade de números ímpares e a quantidade de números pares na lista ligada. O retorna será por meio dos parâmetros qtd_impares e qtd_pares por referência.

Considere a seguinte estrutura para um nó de lista ligada:

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};
A função deve seguir o seguinte protótipo:

void impares_pares(LinkedNode *inicio, int *qtd_impares, int *qtd_pares);
,#include "lista.h"

*/

#include <stdlib.h>
//#include "lista.h"


typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

void impares_pares(LinkedNode *inicio, int *qtd_impares, int *qtd_pares) {
    LinkedNode *atual = inicio;
    int pares = 0, impares = 0;

    while (atual != NULL) {
        if ((atual->data % 2) == 0)
            pares++;
        else
            impares++;
        atual = atual->next;
    }
    *qtd_impares = impares;
    *qtd_pares = pares;

    return;
}
