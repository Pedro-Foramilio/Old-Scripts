#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Fila.h"

typedef struct _viz Viz;

struct _viz
{
  int noj;
  float peso;
  Viz *prox;
};

typedef struct _grafo
{
  int nv;    /* numero de nos ou vertices */
  int na;    /* numero de arestas */
  Viz **viz; /* viz[i] aponta para a lista de arestas vizinhas do no i */
} Grafo;


static Viz *criaViz(Viz *head, int noj, float peso)
{
  /* insere vizinho no inicio da lista */
  Viz *no = (Viz *)malloc(sizeof(Viz));
  assert(no);
  no->noj = noj;
  no->peso = peso;
  no->prox = head;
  return no;
}

static Grafo *grafoCria(int nv, int na)
{
  int i;
  Grafo *g = (Grafo *)malloc(sizeof(Grafo));
  g->nv = nv;
  g->na = na;
  g->viz = (Viz **)malloc(sizeof(Viz *) * nv);
  for (i = 0; i < nv; i++)
    g->viz[i] = NULL;
  return g;
}

Grafo *grafoLe(char *filename)
{
  /* cria grafo n�o orientado - sup�e que arquivo est� correto! */

  FILE *arq = fopen(filename, "rt");
  int nv, na, no1, no2 = 0;
  float peso;
  Grafo *novo;

  fscanf(arq, "%d %d", &nv, &na);
  novo = grafoCria(nv, na);
  assert(novo);
  while (fscanf(arq, "%d %d %f", &no1, &no2, &peso) == 3)
  {
    novo->viz[no1] = criaViz(novo->viz[no1], no2, peso);
    // novo->viz[no2] = criaViz(novo->viz[no2], no1, peso);
  }
  return novo;
}

Grafo *grafoLibera(Grafo *grafo)
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

void busca_Largura(Grafo *grafo, int s, char *Cor, int *D, int *Pred)
{
  for (int u = 0; u < grafo->nv; u++)
  {
    Cor[u] = 'B';
    D[u] = -1;
    Pred[u] = -1;
  }

  Cor[s] = 'C';
  D[s] = 0;
  Pred[s] = -1;

  Fila *Q = fila_cria();
  fila_insere(Q, s);

  int u;
  while (!is_fila_vazia(Q))
  {
    u = (int)fila_retira(Q);
    for (Viz *w = grafo->viz[u]; w != NULL; w = w->prox)
    {
      if (Cor[w->noj] == 'B')
      {
        Cor[w->noj] = 'C';
        D[w->noj] = D[u] + 1;
        Pred[w->noj] = u;
        fila_insere(Q, w->noj);
      }
    }
    Cor[u] = 'P';
  }
}

void imprimeCaminho(int s, int t, int *Pred)
{
  if (t == s)
  {
    printf("%d", t);
    return;
  }
  imprimeCaminho(s, Pred[t], Pred);
  printf(" -> %d", t);
}

int main()
{
  Grafo *g = grafoLe("grafo2.dat");
  char texto[] = "\nMeu grafo\n";
  char Cor[g->nv];
  int D[g->nv];    // distancia
  int Pred[g->nv]; // predecessor

  grafoMostra(texto, g);

  busca_Largura(g, 0, Cor, D, Pred);

  printf("Cor: [");
  for(int i = 0; i < g->nv; i++)
  {
    printf("%c,", Cor[i]);
  }
  printf("]\n");

  printf("D: [");
  for(int i = 0; i < g->nv; i++)
  {
    printf("%d,", D[i]);
  }
  printf("]\n");

  printf("Pred: [");
  for(int i = 0; i < g->nv; i++)
  {
    printf("%d,", Pred[i]);
  }
  printf("]\n");

  printf("\nCaminho de 0 a 5:\n");
  imprimeCaminho(0, 5, Pred);
  printf("\n");

  return 0;
}
