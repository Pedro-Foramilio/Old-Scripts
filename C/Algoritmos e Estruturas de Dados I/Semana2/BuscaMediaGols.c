#include <stdio.h>
#include <stdlib.h>

struct Jogador
{
    char nome[50];
    int qtdGols;
};

struct Time
{
    char nome[50];
    int qtdJogadores;
    struct Jogador *elenco;
};

typedef struct Jogador Jogador;
typedef struct Time Time;

float calculaMediaGols(Jogador *, int);


int main()
{
    int n, i, j;
    float mediaGols;
    Time *times;

    scanf("%d", &n);
    times = (Time *) malloc(n * sizeof(Time));
    for (i = 0; i < n; i++)
    {
        scanf("%s", times[i].nome);
        scanf("%d", &times[i].qtdJogadores);

        times[i].elenco = (Jogador *) malloc(times[i].qtdJogadores * sizeof(Jogador));

        for (j = 0; j < times[i].qtdJogadores; j++)
        {
            scanf("%s %d", times[i].elenco[j].nome, &times[i].elenco[j].qtdGols);
        }
    }

    for (i = 0; i < n; i++)
    {
        mediaGols = calculaMediaGols(times[i].elenco, times[i].qtdJogadores);
        for (j = 0; j < times[i].qtdJogadores; j++)
        {
            if (times[i].elenco[j].qtdGols > mediaGols)
            {
                printf("[%s] %s\n", times[i].nome ,times[i].elenco[j].nome);
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        free(times[i].elenco);
    }
    free(times);

    return 0;
}

float calculaMediaGols(Jogador *elenco, int n)
{
    int i, somaGols = 0;
    for (i = 0; i < n; i++)
    {
        somaGols += elenco[i].qtdGols;
    }

    return ((float)somaGols)/(float)n;
}
