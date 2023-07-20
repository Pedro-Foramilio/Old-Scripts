#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 127

struct Aluno
{
    int mat;
    char nome[81];
    char email[41];
    char turma;
};
typedef struct Aluno Aluno;

typedef Aluno* Hash[N];

int hash(int x)
{
    return x % N;
}

int hash2(int x)
{
    return N - 2 - x % (N-2);
}

Aluno* hsh_busca(Hash tab, int mat)
{
    int h = hash(mat);
    int h2 = hash2(mat);
    while (tab[h] != NULL)
    {
        if (tab[h]->mat == mat)
        {
            return tab[h];
        }
        h = (h+h2) % N;
    }
    return NULL;
}

Aluno* hsh_insere(Hash tab, int mat, char *n, char *e, char t)
{
    int h = hash(mat);
    while (tab[h] != NULL)
    {
        if (tab[h]->mat == mat)
        {
            break;
        }
        h = (h+1) % N;
    }
    if (tab[h] == NULL) //nao encontrou o elemento
    {
        tab[h] = (Aluno *)malloc(sizeof(Aluno));
        tab[h]->mat = mat;
    }

    //atribui / modifica informacao
    strcpy(tab[h]->nome, n);
    strcpy(tab[h]->email, e);
    tab[h]->turma = t;
    return tab[h];

}
