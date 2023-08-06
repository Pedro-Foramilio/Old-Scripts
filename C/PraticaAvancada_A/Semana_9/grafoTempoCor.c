#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int tempo = 0; //global

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

void dfs_visit(Grafo *grafo, int v, int *predecessor, int *d, int *f, char *cor);

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
    novo = criaGrafo(nv, na);
    assert(novo);
    
    while (fscanf(arq, "%d %d %f", &no1, &no2, &peso) == 3)
    {
        novo->viz[no1] = criaViz(novo->viz[no2], no1, peso);
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

void grafoMostra(char *title, Grafo *grafo)
{
    int i;
    if (title)
        printf("%s", title);
    if (grafo)
    {
        printf("NV: %d, NA: %d\n", grafo->nv, grafo->na);
        for (i = 0; i < grafo->nv; i++)
        {
            Viz *viz = grafo->viz[i];
            printf("[%d]->", i);
            while (viz)
            {
                printf("{%d, %g}->", viz->noj, viz->peso);
                viz = viz->prox;
            }
            printf("NULL\n");
        }
    }
}

void dfs_visit(Grafo *grafo, int v, int *predecessor, int *d, int *f, char *cor)
{
    cor[v] = 'C';
    tempo++;
    d[v] = tempo;
	printf("v: %3d %3c \n", v, cor[v]);

    for (Viz *w = grafo->viz[v]; w != NULL; w = w->prox)
    {
        if (cor[w->noj] == 'B')
        {
            predecessor[w->noj] = v;
            printf("\t%3d - %3d: %3c predecessor: %3d\n", v, w->noj, cor[w->noj], predecessor[w->noj]);
            dfs_visit(grafo, w->noj, predecessor, d, f, cor);
        }
    }

    cor[v] = 'P';
    f[v] = ++tempo;
    printf("%3d:>(%3d,%3d,%3c) \n", v, d[v], f[v], cor[v]);
}

void dfs(Grafo *grafo)
{
    if (!grafo) return;
    int predecessor[grafo->nv];
	int d[grafo->nv];
	int f[grafo->nv];
	char cor[grafo->nv];

    for (int i = 0; i < grafo->nv; i++)
    {
        predecessor[i] = -1;
        cor[i] = 'B';
    }

    for (int i = 0; i < grafo->nv; i++)
    {
        if (cor[i] == 'B') dfs_visit(grafo, i, predecessor, d, f, cor);
    }
}

int main()
{
    Grafo *g = grafoLe("grafo.dat");
    char texto[] = "\nMeu grafo\n";
    grafoMostra(texto, g);
    dfs(g);
    return 0;
}
