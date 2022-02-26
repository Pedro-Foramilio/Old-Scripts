#include <stdio.h>

int comparaStrings(char a[], char b[])
{
    int i = 0;
    while(a[i]!='\0' && b[i]!='\0')
    {
        if (a[i]!=b[i])
            return 0;
        i++;
    }

    return a[i] == b[i];
}

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
            if (comparaStrings(vetorPalavras[j], pesquisa))
            {
                resultados++;
            }
        }
        printf("%d\n", resultados);
        resultados = 0;

    }

    return 0;
}
