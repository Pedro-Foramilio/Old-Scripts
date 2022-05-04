#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
No * sucessor(No *);

int main()
{
    Arvore *arvore = criaArvore();
	int chave;
	char comando[13];
    No *no;

	while (scanf("%s", comando) != EOF)
	{
		if (strcmp(comando, "pre-order") == 0)
		{
			preOrder(arvore->raiz);
			printf("\n");
		}
		else if (strcmp(comando, "in-order") == 0)
		{
			inOrder(arvore->raiz);
			printf("\n");
		}
		else if (strcmp(comando, "post-order") == 0)
		{
			postOrder(arvore->raiz);
			printf("\n");
		}
		else
		{
			scanf("%d", &chave);
			if (strcmp(comando, "insert") == 0)
			{
				inserir(arvore, criaNo(chave));
			}
			else if (strcmp(comando, "delete") == 0)
			{
				no = remover(arvore, chave);
				if (no != NULL)
				{
					printf("%d\n", no->chave);
					free(no);
				}
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
//warning: bug com repeticao de chave???
{
    No *pai = NULL;
    No *filho = t->raiz;

    while (filho != NULL)
    {
        pai = filho;
        if (filho->chave <= novo->chave)
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
        if (pai->chave <= novo->chave) // filho da direita
        {
            pai->direita = novo;
        }
        else
        {
            pai->esquerda = novo;
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
        printf("%d ", r->chave);
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
        printf("%d ", r->chave);
    }
}

void inOrder(No *r)
{
    if (r != NULL)
    {
        inOrder(r->esquerda);
        printf("%d ", r->chave);
        inOrder(r->direita);
    }
}

No * remover(Arvore *t, int chave)
{
    No *anterior = NULL;
    No *filho = t->raiz;
    No *subs;

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
            subs = sucessor(filho->direita); //pegar o menor dentro os maiores

            if (anterior != NULL) // nao eh raiz
            {
                if (anterior->esquerda == filho) //remover filho da esquerda
                {
                    anterior->esquerda = subs;
                }

                else // filho da direita
                {
                    anterior->direita = subs;
                }
            }

            else //eh raiz
            {
                t->raiz = subs;
            }

            subs->pai = anterior;

            subs->esquerda = filho->esquerda;
            if (filho->esquerda != NULL)
            {
                filho->esquerda->pai = subs;
            }

            subs->direita = filho->direita;
            if (filho->direita != NULL)
            {
                filho->direita->pai = subs;
            }

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

No * sucessor(No *filho)
{
    No * anterior = NULL;
    while( filho != NULL )
    {
        anterior = filho;
        filho = filho->esquerda;
    }

    if (anterior->pai->esquerda == anterior) //anterior (sucessor) eh filho esquerdo  de seu pai
    {
        anterior->pai->esquerda = anterior->direita;
    }

    else //anterior (sucessor) eh filho direito de seu pai
    {
        anterior->pai->direita = anterior->direita;
    }

    if (anterior->direita != NULL)
    {
        anterior->direita->pai = anterior->pai;
    }

    return anterior;
}
