#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *, int, int *);
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
    selectionSort(vetor, n, &nTrocas);
    imprimeVetor(vetor, n);
    printf("%d\n", nTrocas);

    free(vetor);
    return 0;
}

void imprimeVetor(int *v, int n)
{
    for (int i = 0; i < n-1; i++)
        printf("%d ", v[i]);
    printf("%d\n", v[n-1]);
}

void selectionSort(int *v, int n, int *nTrocas)
{
    int i, j, iMin, aux;
    for (i=0; i<n-1; i++)
    {
        for (j = i+1, iMin = i; j < n; j++)
        {
            if (v[j] < v[iMin])
            {
                iMin = j;
                (*nTrocas)++;
            }
        }
        aux= v[i];
        v[i] = v[iMin];
        v[iMin] = aux;
        imprimeVetor(v, n);
    }
    return;
}
