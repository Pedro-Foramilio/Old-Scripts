#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

typedef struct lista Lista;
struct lista
{
    float info;
    Lista *prox;
};

struct pilha
{
    Lista *prim;
};

Pilha* criar(void)
{
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

void push(Pilha *p, float v)
{
    Lista *n = (Lista*) malloc(sizeof(Lista));
    n->info = v;
    n->prox = p->prim;
    p->prim = n;
}

float pop(Pilha *p)
{
    Lista *t;
    float v;

    if (esta_vazia(p)) 
    {
        printf("Lista Vazia!!!\n");
        exit(1);
    }

    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;
}

void liberar(Pilha *p)
{
    Lista *q = p->prim;
    while (q != NULL)
    {
        Lista *t = q->prox;
        free(q);
        q = t;
    }
    free(p);
    return;
}

int esta_vazia(Pilha *p)
{
    return (p->prim == NULL);
}
