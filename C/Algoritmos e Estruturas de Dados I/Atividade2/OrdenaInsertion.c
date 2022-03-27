#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int *);
void imprimeVetor(int *, int);


int main()
{
    int n;
    int nTrocas = 0;
    scanf("%d", &n);
    int *vetor = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    imprimeVetor(vetor, n);
    insertionSort(vetor, n, &nTrocas);
    imprimeVetor(vetor, n);
    printf("Trocas:%d\n", nTrocas);

    if (nTrocas == 0)
    {
        printf("MELHOR CASO\n");
    }
    else if (nTrocas >= n*(n-1)/2)
    {
        printf("PIOR CASO\n");
    }
    else
    {
        printf("CASO ALEATORIO\n");
    }

    free(vetor);
    return 0;
}

void imprimeVetor(int *v, int n)
{
    for (int i = 0; i < n-1; i++)
        printf("%d ", v[i]);
    printf("%d\n", v[n-1]);
}

void insertionSort(int *v, int n, int *nTrocas)
{
    int chave, i, j;
    for (i = 1; i < n; i++)
    {
        chave = v[i];
        j = i-1;
        while(j>=0 && v[j] >= chave)
        {
            v[j+1] = v[j];
            v[j] = chave;
            j--;
            imprimeVetor(v, n);
            (*nTrocas)++;
        }
    }
}