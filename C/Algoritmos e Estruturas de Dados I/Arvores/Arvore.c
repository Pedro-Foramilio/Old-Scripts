//arvore binaria de busca
#include <stdio.h>
#include <stdlib.h>

struct No
{
    int chave;
    struct No *pai;
    struct No *direita;
    struct No *esquerda;
};

struct Arvore
{
    struct No *raiz;
};

typedef struct No No;
typedef struct Arvore Arvore;

Arvore * criaArvore();
No * criaNo(int);
void inserir(Arvore *, No *);
void preOrder(No *);
void postOrder(No *);
void inOrder(No *);

int main(void)
{
    Arvore *arvore = criaArvore();
    int chave;
    char op;

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'I')
        {
            scanf("%d", &chave);
            inserir(arvore, criaNo(chave));
        }
        else if (op == 'R')
        {
            
        }
        else // M
        {
            scanf("\n%c", &op);
            if (op == 'P')
            {
                preOrder(arvore->raiz);
            }
            else if (op == 'I')
            {
                inOrder(arvore->raiz);
            }
            else // T
            {
                postOrder(arvore->raiz);
            }
        }
    }

    return 0;
}

Arvore * criaArvore()
{
    Arvore *t = (Arvore *) malloc(sizeof(Arvore));
    if (t != NULL)
        t->raiz = NULL;
    return t;
}

No * criaNo(int chave)
{
    No *no = (No *) malloc(sizeof(No));
    if (no != NULL)
    {
        no->chave = chave;
        no->direita = NULL;
        no->esquerda = NULL;
        no->pai = NULL;
    }
    return no;
}

void inserir(Arvore *t, No *novo)
{
    No *pai = NULL;
    No *filho = t->raiz;

    while (filho != NULL)
    {
        pai = filho;
        if (filho->chave < novo->chave)
        {
            filho = filho->direita;
        }
        else
        {
            filho = filho->esquerda;
        }
    }
    //filho nulo e pai apontando no elemento pai do novo
    // ou arvore vazia => raiz
    if (pai != NULL) //inserindo uma folha
    {
        novo->pai = pai;
        if (pai->chave > novo->chave) // filho da esquerda
        {
            pai->esquerda = novo;
        }
        else
        {
            pai->direita = novo;
        }
    }
    else //inserindo raiz
    {
        t->raiz = novo;
    }
}

void preOrder(No *r)
{
    if (r != NULL)
    {
        printf("%d\n", r->chave);
        preOrder(r->esquerda);
        preOrder(r->direita);
    }
}

void postOrder(No *r)
{
    if (r != NULL)
    {
        postOrder(r->esquerda);
        postOrder(r->direita);
        printf("%d\n", r->chave);
    }
}

void inOrder(No *r)
{
    if (r != NULL)
    {
        inOrder(r->esquerda);
        printf("%d\n", r->chave);
        inOrder(r->direita);
    }
}
