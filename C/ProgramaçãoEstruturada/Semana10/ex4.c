/*
Implemente a função inserir_posicao, que recebe um ponteiro para o primeiro nó de uma lista ligada, 
e dois números inteiros, posicao e valor. Crie um novo nó com o inteiro valor e o insira na posição informada na lista. 
A função deve devolver um ponteiro ao primeiro elemento da lista. Assuma que a posição passada sempre será válida.

Uma posição igual a 0 indica início da lista. Uma posição igual a 1 indica o nó seguinte ao início da lista e assim por diante. 
O ponteiro dado pode ser nulo, o que significa que a lista inicial está vazia.

Considere a seguinte estrutura para um nó de lista ligada:

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};
A função deve seguir o seguinte protótipo:

LinkedNode* inserir_posicao(int posicao, int valor, LinkedNode *inicio);


Importante: submeta apenas a função. Não use variáveis globais. Não inclua o main. 
Não use printf/fprintf/puts/gets/fgets/scanf/fscanf e headers adicionais (por exemplo, stdio.h). Neste exercício, pode usar stdlib.h.
*/

#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

LinkedNode* inserir_posicao(int posicao, int valor, LinkedNode *inicio) {
    LinkedNode *novo = malloc(sizeof(LinkedNode));
    novo->data = valor;
    if (inicio == NULL) {
        novo->next = NULL;
        return novo;
    }
    if (posicao == 0) {
        novo->next = inicio;
        return novo;
    }

    LinkedNode *atual = inicio;
    for (int i = 0; i < posicao-1; i++) {
        atual = atual->next;
    }
    LinkedNode *temp = atual->next;
    atual->next = novo;
    novo->next = temp;
    
    return inicio;
}
