/*
Um disco voador abandonado foi encontrado pelo professor ABC. Dentro do disco, havia vestígios de DNA alienígena, que também era formado pelas
 quatro bases A, C, G, T. Contudo, quando entrou em contato com a água, as bases C e G foram eliminadas da sequência.

Implemente a função dna_alien, que recebe uma lista ligada com as bases que formam o DNA Alien e retorna o DNA modificado após contato com a água.
 Ou seja, a função irá remover todos os nós com as bases C e G. Por exemplo, para a sequência AAGCGAGTCAGGCTGAAGCTAGCTA, 
 a função retornaria a lista AAATATAATATA. A função deve retornar o ponteiro para o início da lista após a remoção dos nós.

Observação: a função deve remover os nós da lista original e não alocar uma nova lista com novos nós.

Considere a seguinte estrutura para um nó de lista ligada:

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   char data;
   LinkedNode *next;
};
A função deve seguir o seguinte protótipo:

LinkedNode *dna_alien(LinkedNode *atual);


Importante: submeta apenas a função. Não use variáveis globais. Não inclua o main. 
Não use printf/fprintf/puts/gets/fgets/scanf/fscanf e headers adicionais (por exemplo, stdio.h). Neste exercício, pode usar stdlib.h.


A definição da struct LinkedNode já existe no sistema de correção automática (portanto, não inclua a definição da struct no código submetido). 
É necessário incluir a seguinte linha no início do código submetido:

#include "dna_alien.h"
*/
#include <stdlib.h>
typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   char data;
   LinkedNode *next;
};

LinkedNode *dna_alien(LinkedNode *inicio) {
    if (inicio == NULL) return NULL;

    LinkedNode *atual = inicio;
    LinkedNode *anterior = NULL;

    while(atual != NULL) {
        if (atual->data == 'C' || atual->data == 'G' ) {
            if (anterior != NULL)
                anterior->next = atual->next;
            else
                inicio = atual->next;
            
            LinkedNode *temp = atual;
            atual = atual->next;
            free(temp);
            continue;
        }

        anterior = atual;
        atual = atual->next;
    }
    return inicio;
}
