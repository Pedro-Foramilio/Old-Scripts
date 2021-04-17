/*
Implemente a função inverter_lista, que recebe um ponteiro para o primeiro nó de uma lista ligada. 
A função deve inverter a ordem dos nós na lista. Isto é, as ligações devem ser invertidas. 
A função deve devolver um ponteiro ao primeiro elemento da lista invertida. O ponteiro dado pode ser nulo, 
o que significa que a lista inicial estaria vazia.

Observação: a função deve alterar a lista original e não alocar uma nova lista com novos nós.

Considere a seguinte estrutura para um nó de lista ligada:

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};
A função deve seguir o seguinte protótipo:

LinkedNode* inverter_lista(LinkedNode *inicio);
*/

#include <stdlib.h>
typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

LinkedNode* inverter_lista(LinkedNode *inicio) {
    if (inicio == NULL) return NULL;

    LinkedNode *anterior = NULL;
    LinkedNode *atual = inicio;
    LinkedNode *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->next;
        atual->next = anterior;
        anterior = atual;
        atual = proximo;
    }
    inicio = anterior;
    
    return inicio;
}
