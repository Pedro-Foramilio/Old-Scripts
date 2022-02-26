#include <stdio.h>

int buscaLinear(int vetor[], int tamanho, int targetElement)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] == targetElement)
            return 1;
    }
    return 0;
}

int main()
{
    int n;
    int elementoAtual;
    scanf("%d", &n);

    int v[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < (n+1); i++)
    {
        scanf("%d", &elementoAtual);

        if (!buscaLinear(v, n, elementoAtual))
        {
            printf("%d\n", elementoAtual);
            return 0;
        }
    }

    return 0;
}
