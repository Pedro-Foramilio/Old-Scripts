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
No * remover(Arvore *, int);

int main(void)
{
    Arvore *arvore = criaArvore();
    int chave;
    char op;
    No *no;

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'I')
        {
            scanf("%d", &chave);
            inserir(arvore, criaNo(chave));
        }
        else if (op == 'R')
        {
            scanf("%d", &chave);
            no = remover(arvore, chave);
            if (no != NULL)
            {
                printf("item %d removido da arvore\n", no->chave);
                free(no);
            }

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

No * remover(Arvore *t, int chave)
{
    No *anterior = NULL;
    No *filho = t->raiz;

    while (filho != NULL && filho->chave != chave)
    {
        anterior = filho;
        if (filho->chave < chave)
        {
            filho = filho->direita;
        }
        else
        {
            filho = filho->esquerda;
        }
    }
    //filho nulo ou apontando ao que queremos remover
    if (filho != NULL)
    {

        if (filho->esquerda == NULL && filho->direita == NULL) //eh folha
        {
            if (anterior != NULL) // nao eh raiz
            {
                if (anterior->esquerda == filho) //eh filho da esquerda do pai
                {
                    anterior->esquerda = NULL;
                }

                else //eh filho da direita do pai
                {
                    anterior->direita = NULL;
                }
            }

            else //eh raiz
            {
                t->raiz = NULL;
            }
        }

        else if (filho->esquerda != NULL && filho->direita != NULL) //eh pai de 2 filhos
        {

        }

        else // pai de filho unico
        {
            if (anterior != NULL) //nao eh raiz
            {
                if (anterior->esquerda == filho) // eh filho de lado esquerdo
                {
                    if (filho->esquerda != NULL) // tem filho na esquerda
                    {
                        anterior->esquerda = filho->esquerda; //avo na subarvore esquerda assume neto esquerdo
                        filho->esquerda->pai = anterior;
                    }

                    else // tem filho na direita
                    {
                        anterior->esquerda = filho->direita; //avo na subarvore esquerda assume neto direito
                        filho->direita->pai = anterior;
                    }
                }

                else //filho de lado direito
                {
                    if (filho->esquerda != NULL) //tem filho na esquerda
                    {
                        anterior->direita = filho->esquerda;
                        filho->esquerda->pai = anterior;
                    }

                    else //tem filho na direita
                    {
                        anterior->direita = filho->direita;
                        filho->direita->pai = anterior;
                    }
                }
            }
            else //eh raiz
            {
                if (filho->esquerda != NULL) //raiz tem filho na esquerda
                {
                    t->raiz = filho->esquerda;
                }
                else //raiz tem filho na direita
                {
                    t->raiz = filho->direita;
                }
                t->raiz->pai = NULL;
            }

        }

    }

    return filho;
}
