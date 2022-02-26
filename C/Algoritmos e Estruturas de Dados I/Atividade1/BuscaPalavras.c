#include <stdio.h>

int main()
{
    int nPalavras, qtdConsultas, resultados = 0;
    scanf("%d", &nPalavras);

    char vetorPalavras[nPalavras][20];//nPalavras de 20 letras max
    char pesquisa[20];

    for (int i = 0; i < nPalavras; i++)
    {
        scanf("%s", vetorPalavras[i]);
    }

    scanf("%d", &qtdConsultas);

    for (int i = 0; i <qtdConsultas; i++)
    {
        scanf("%s", pesquisa);
        for (int j = 0; j < nPalavras; j++)
        {
            if (vetorPalavras[j] == pesquisa)
            {
                resultados++;
            }
        }
        printf("%d\n", resultados);
        resultados = 0;

    }

    return 0;
}
