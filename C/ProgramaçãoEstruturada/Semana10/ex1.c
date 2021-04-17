/*
Implemente a função comparar_listas, que recebe dois ponteiros para os primeiros nós de duas listas ligadas. 
A função deve comparar os dados nos nós das listas para verificar se eles são iguais 
(retorna verdadeiro se forem iguais e falso caso contrário). As listas são iguais apenas se tiverem o mesmo número de nós e 
os nós correspondentes tiverem os mesmos dados. O ponteiro dado pode ser nulo, o que significa que a lista estaria vazia.

Considere a seguinte estrutura para um nó de lista ligada:

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};
A função deve seguir o seguinte protótipo:

int comparar_listas(LinkedNode *inicio_lista1, LinkedNode *inicio_lista2);


Importante: submeta apenas a função. Não use variáveis globais. Não inclua o main. 
Não use printf/fprintf/puts/gets/fgets/scanf/fscanf e headers adicionais (por exemplo, stdio.h). Neste exercício, pode usar stdlib.h.


A definição da struct LinkedNode já existe no sistema de correção automática (portanto, não inclua a definição da struct no código submetido).
 É necessário incluir a seguinte linha no início do código submetido:

#include "comparar_listas.h"
*/
#include <stdlib.h>
//#include "comparar_listas.h"
typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

int comparar_listas(LinkedNode *inicio_lista1, LinkedNode *inicio_lista2) {
    if (inicio_lista1 == NULL || inicio_lista2 == NULL) {
        if (inicio_lista1 == NULL && inicio_lista2 == NULL)
            return 1;
        else
            return 0;
    }
    LinkedNode *atual1 = inicio_lista1;
    LinkedNode *atual2 = inicio_lista2;

    while (atual1->data == atual2->data) {
        atual1 = atual1->next;
        atual2 = atual2->next;
        if (atual1 == NULL || atual2 == NULL) {
            if (atual1 == atual2) return 1;
            return 0;
        }
    }

    return 0;
}
