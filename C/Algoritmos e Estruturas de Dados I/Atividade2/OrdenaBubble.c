#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *, int, int *);
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
    bubbleSort(vetor, n, &nTrocas);
    imprimeVetor(vetor, n);
    printf("Trocas: %d\n", nTrocas);

    free(vetor);
    return 0;
}

void imprimeVetor(int *v, int n)
{
    for (int i = 0; i < n-1; i++)
        printf("%d ", v[i]);
    printf("%d\n", v[n-1]);
}

void bubbleSort(int *v, int n, int *nTrocas)
{
	int i, j , aux;
	for (i = 0; i < n-1; i++)
	{
		for (j=0; j < n-1-i; j++)
		{
			if (v[j] > v[j+1])
			{
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
                imprimeVetor(v, n);
                (*nTrocas)++;
			}
		}
	}
	return;
}