#include <stdlib.h>
#include "Heap.h"

struct Heap {
    int max; //tamanho maximo do heap
    int pos; //proxima pos livre do vetor
    int *prioridade; //vetor das prioridades
    //ignorando dados
};

Heap *heap_cria(int max)
{
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->max = max;
    heap->pos = 0;
    heap->prioridade = (int *)malloc(heap->max * sizeof(int));
    return heap;
}


static void troca(int a, int b, int *v)
{
    int f = v[a];
    v[a] = v[b];
    v[b] = f;
}

static void corrige_acima(Heap *heap, int pos)
{
    int pai;
    while (pos > 0)
    {
        pai = (pos-1)/2;
        if (heap->prioridade[pai] < heap->prioridade[pos])
        {
            troca(pos,pai,heap->prioridade);
        }
        else
        {
            break;
        }
        pos=pai;
    }
}

void heap_insere(Heap *heap, int prioridade)
{
    if (heap->pos < heap->max)
    {
        heap->prioridade[heap->pos] = prioridade;
        corrige_acima(heap, heap->pos);
        heap->pos++;
    }
}

static void corrige_abaixo(int *prios, int atual, int tam)
{
    int pai = atual;
    int filho_esq, filho_dir,filho;

    while (2 * pai + 1 < tam)
    {
        filho_esq = 2 * pai + 1;
        filho_dir = 2 * pai + 2;

        if (filho_dir >= tam) filho_dir = filho_esq;
        if (prios[filho_esq] > prios[filho_dir])
            filho = filho_esq;
        else
            filho = filho_dir;
        
        if (prios[pai] < prios[filho])
            troca(pai, filho, prios);
        else
            break;
        pai = filho;
    }
}

int heap_remove(Heap *heap)
{
    if (heap->pos > 0)
    {
        int topo = heap->prioridade[0];
        heap->prioridade[0] = heap->prioridade[heap->pos - 1];
        heap->pos--;
        corrige_abaixo(heap->prioridade,0,heap->pos);
        return topo;
    }
    return -1;
}
