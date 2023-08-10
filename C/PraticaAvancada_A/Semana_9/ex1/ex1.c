#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _viz Viz;
struct _viz 
{
    int noj;
    float peso;
    Viz *prox;
};

typedef struct _grafo
{
    int nv; //numero vertiices
    int na; //numero arestas
    Viz **viz; // viz[i] aponta para a lista de verticies vizinhos de i
} Grafo;

static Viz* criaViz(Viz *head, int noj, float peso)
{
    Viz *no = (Viz*) malloc(sizeof(Viz));
    assert(no);
    no->noj = noj;
    no->peso = peso;
    no->prox = head;
    return no;
}

static Grafo* criaGrafo(int nv, int na)
{
    int i;
    Grafo *g = (Grafo *) malloc(sizeof(Grafo));
    g->nv = nv;
    g->na = na;
    g->viz = (Viz **) malloc(sizeof(Viz *) * nv);

    for (i = 0; i < nv; i++)
    {
        g->viz[i] = NULL;
    }

    return g;
}

Grafo* grafoLe(char *filename)
{
    FILE *arq = fopen(filename, "rt");
    int nv, na, no1, no2 = 0;
    float peso = 0;
    Grafo *novo;

    fscanf(arq, "%d %d", &nv, &na);
    //scanf("%d %d", &nv, &na);
    novo = criaGrafo(nv, na);
    assert(novo);
    
    while (fscanf(arq, "%d %d %f", &no1, &no2, &peso) == 3)
    //while (scanf("%d %d %f", &no1, &no2, &peso) != EOF)
    {
        novo->viz[no1] = criaViz(novo->viz[no1], no2, peso);
        //novo->viz[no2] = criaViz(novo->viz[no2], no1, peso);
    }
    return novo;
}

Grafo* grafoLibera(Grafo *grafo)
{
    if (grafo)
    {
        int i = 0;
        Viz *no, *aux;
        for (i = 0; i < grafo->nv; i++)
        {
            no = grafo->viz[i];
            while (no)
            {
                aux = no->prox;
                free(no);
                no = aux;
            }
        }
        free(grafo->viz);
        free(grafo);
    }
    return NULL;
}

void imprimeCarantes(Grafo *grafo)
{
    int ehCarente[grafo->nv];

    for (int i = 0; i < grafo->nv; i++)
    {
        ehCarente[i] = 1;
    }

    for (int i = 0; i < grafo->nv; i++)
    {
        for (Viz *w = grafo->viz[i]; w != NULL; w = w->prox)
        {
            ehCarente[w->noj] = 0;
        }
    }

    int aux = 0;
    for (int i = 0; i < grafo->nv; i++)
    {
        if (ehCarente[i])
        {
            aux = 1;
            printf("%d ", i);
        }
    }

    if (aux)
    {
        printf("\n");
    }
    else
    {
        printf("Nao ha vertices carentes\n");
    }

}

int main()
{
    Grafo *g1 = grafoLe("grafo.dat");
    Grafo *g2 = grafoLe("grafo2.dat");
    
    imprimeCarantes(g1);
    imprimeCarantes(g2);

    return 0;
}
