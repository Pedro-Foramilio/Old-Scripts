#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int chave;
    struct Item *proximo;
};

struct Lista
{
    struct Item *inicio;
};

struct Lista * criaLista();
struct Item * criaItem(int);
void inserir(struct Lista *, struct Item *);
struct Item * remover(struct Lista *, int);
struct Item * buscar(struct Lista *, int);
void mostrar(struct Lista *);
void desalocar(struct Lista *);

int main()
{
    struct Lista *lista = criaLista();
    struct Item *it;
    int chave;
    char op;

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'I')
        {
            scanf("%d", &chave);
            if (buscar(lista, chave) == NULL)
                inserir(lista, criaItem(chave));
        }
        else if (op == 'R')
        {
            scanf("%d", &chave);
            it = remover(lista, chave);
            if (it != NULL)
            {
                free(it);
            }
        }
        else if (op == 'B')
        {
            scanf("%d", &chave);
            printf("%s\n", buscar(lista, chave) != NULL ?"SIM":"NAO");
        }
        else if (op == 'L')
        {
            mostrar(lista);
        }
    }
    
    desalocar(lista);

    return 0;
}

struct Lista * criaLista()
{
    struct Lista *l = (struct Lista *) malloc(sizeof(struct Lista));
    if (l != NULL)
        l->inicio = NULL;
    return l;
}

struct Item * criaItem(int chave)
{
    struct Item *it = (struct Item *) malloc(sizeof(struct Item));
    if ( it != NULL)
    {
        it->chave = chave;
        it->proximo = NULL;
    }
    return it;
}

void inserir(struct Lista *l, struct Item *novo)
{
    struct Item *anterior = NULL, *atual = l->inicio;
    int achei = 0;

    while (atual != NULL && !achei)
    {
        if (atual->chave > novo->chave)
        {
            achei = 1;
        }
        else
        {
            anterior = atual;
            atual = atual->proximo;
        }
    }

    if (anterior == NULL) //inserindo inicio da fila
        l->inicio = novo;
    
    else //meio ou final
        anterior->proximo = novo;
    
    novo->proximo = atual;
    return;
}

struct Item * remover(struct Lista *l, int chave)
{
    struct Item *anterior = NULL, *atual = l->inicio;
    while (atual != NULL && atual->chave != chave)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL)
    {
        if (anterior == NULL) //removendo primeiro
        {
            l->inicio = atual->proximo;
        }
        else
        {
            anterior->proximo = atual->proximo;
        }
    }
    return atual;
}

struct Item * buscar(struct Lista *l, int chave)
{
    struct Item *it = l->inicio;
    while(it != NULL && it->chave != chave) // ou it fica null ou acha
    {
        it = it->proximo;
    }
    return it;
}

void mostrar(struct Lista *l)
{
    struct Item *it = l->inicio;
    while(it != NULL)
    {
        printf("%d%s", it->chave, it->proximo == NULL ?"\n":" ");
        it = it->proximo;
    }
}

void desalocar(struct Lista *l)
{
    struct Item *it = l->inicio, *proximo;
    while(it != NULL)
    {
        proximo = it->proximo;
        free(it);
        it = proximo;
    }
    free(l);
}
