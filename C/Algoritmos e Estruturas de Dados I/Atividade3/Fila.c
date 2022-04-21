#include <stdlib.h>
#include <stdio.h>

struct Item
{
    int chave;
};

struct FilaEstatica
{
    struct Item *itens;
    int tamanho;
    int inicio, fim;
};

struct FilaEstatica criaFilaEstatica(int);
struct Item criaItem(int);
void enfileirar(struct FilaEstatica *, struct Item);
struct Item desenfileirar(struct FilaEstatica *);
int filaVazia(struct FilaEstatica);
int filaCheia(struct FilaEstatica);
void mostrarFila(struct FilaEstatica);

int main(void)
{
    struct FilaEstatica fila;
    int n, chave;
    char op;

    scanf("%d", &n);
    fila = criaFilaEstatica(n);

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'E')
        {
            scanf("%d", &chave);
            enfileirar(&fila, criaItem(chave));

        }

        else if (op == 'D')
        {
            if (! filaVazia(fila))
                printf("%d\n", desenfileirar(&fila).chave);
        }

        else
        {
            mostrarFila(fila);
        }
    }


    return 0;
}

struct FilaEstatica criaFilaEstatica(int n)
{
    struct FilaEstatica f;
    f.itens = (struct Item *) malloc(n * sizeof(struct Item));
    f.tamanho = n;
    f.inicio = -1;
    f.fim = -1;
    return f;
}

struct Item criaItem(int chave)
{
    struct Item t;
    t.chave = chave;
    return t;
}

void enfileirar(struct FilaEstatica *f, struct Item novo)
{
    if (filaCheia(*f)) return;
    if (filaVazia(*f))
        f->inicio++;
    
    f->fim++;
    f->itens[f->fim] = novo;
}

struct Item desenfileirar(struct FilaEstatica *f)
{
    struct Item it;
    if (! filaVazia(*f))
    {
        it = f->itens[f->inicio];

        //este if else resolve problema do overflow
        if (f->inicio != f->fim)
        {
            f->inicio++;
        }
        else
        {
            f->inicio = -1;
            f->fim = -1;
        }

    }
    return it;
}

int filaVazia(struct FilaEstatica f)
{
    return f.inicio == -1 && f.fim == -1 || f.inicio > f.fim;
}

int filaCheia(struct FilaEstatica f)
{
    return f.fim == f.tamanho - 1;
}

void mostrarFila(struct FilaEstatica f)
{
    int i;

    if (filaVazia(f)) return;

    for (i = f.inicio; i <= f.fim; i++)
        printf("%d%s", f.itens[i].chave, i < f.fim ?" ":"\n");
}
