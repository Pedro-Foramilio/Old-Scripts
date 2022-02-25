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

float calculaMediaGols(struct Jogador *elenco, int n)
{
    int i, somaGols = 0;
    for (i = 0; i < n; i++)
    {
        somaGols += elenco[i].qtdGols;
    }

    return ((float)somaGols)/(float)n;
}

int main()
{
    int n, i, j;
    float mediaGols;
    struct Time *times;

    scanf("%d", &n);
    times = (struct Time *) malloc(n * sizeof(struct Time));
    for (i = 0; i < n; i++)
    {
        scanf("%s", times[i].nome);
        scanf("%d", &times[i].qtdJogadores);

        times[i].elenco = (struct Jogador *) malloc(times[i].qtdJogadores * sizeof(struct Jogador));

        for (j = 0; j < times[i].qtdJogadores; j++)
        {
            scanf("%s %d", times[i].elenco[j].nome, &times[i].elenco[j].qtdGols);
        }

    }
/*
    for (i = 0; i < n; i++)
    {
        printf("====%s====\n", times[i].nome);
        for (j = 0; j < times[i].qtdJogadores; j++)
        {
            printf("%s\n", times[i].elenco[j].nome);
        }
    }
*/
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

    return 0;
}