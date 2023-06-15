#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"

typedef struct Lista Lista;
struct Lista {
    float info;
    Lista *prox;
};

struct Fila
{
    Lista *ini;
    Lista *fim;
};

Fila* fila_cria(void)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void fila_insere(Fila *f, float v)
{
    Lista *n = (Lista *)malloc(sizeof(Lista));
    n->info = v;
    n->prox = NULL;

    if (f->fim != NULL)
    {
        f->fim->prox = n;
    } else //fila estava vazia
    {
        f->ini = n;
    }

    f->fim = n;
    return;
}

float fila_retira(Fila *f)
{
    Lista *t;
    float v;

    if (is_fila_vazia(f))
    {
        printf("Fila vazia\n"); exit(1);
    }

    t = f->ini;
    v = t->info;

    f->ini = t->prox;

    if (f->ini == NULL) f->fim = NULL;

    free(t);
    return v;
}

void fila_libera(Fila *f)
{
    Lista *q = f->ini;
    while (q != NULL)
    {
        Lista *t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}

int is_fila_vazia(Fila *f)
{
    return (f->ini == NULL);
}
