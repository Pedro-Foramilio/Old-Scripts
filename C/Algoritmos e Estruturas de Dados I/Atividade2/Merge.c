#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *, int , int, int);
void intercala(int *, int , int , int);
void imprimeVetor(int *, int);


int main()
{
    int n;
    scanf("%d", &n);
    int *vetor = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    imprimeVetor(vetor, n);
	mergeSort(vetor, 0, n-1, n);
    imprimeVetor(vetor, n);

    free(vetor);
    return 0;
}

void imprimeVetor(int *v, int n)
{
    for (int i = 0; i < n-1; i++)
        printf("%d ", v[i]);
    printf("%d\n", v[n-1]);
}

void mergeSort(int *v, int e, int d, int n)
{
    int meio;
    if (e < d)
    {
        meio = (e+d)/2;
        mergeSort(v, e, meio, n);
        mergeSort(v, meio+1, d, n);
        imprimeVetor(v, n);
        intercala(v, e, meio+1, d);
    }
    
}

void intercala(int *v, int e, int m, int d)
{
    int esq_fim = m - 1, tamanho = d-e+1, i, j, iTemp;
    int *vTemp = (int *) malloc(tamanho * sizeof(int));

    for(i = e, j = m, iTemp = 0; i <= esq_fim && j <= d; iTemp++)
    {
        if (v[i] < v[j])
        {
            vTemp[iTemp] = v[i];
            i++;
        } else {
            vTemp[iTemp] = v[j];
            j++;
        }
    }

    for (; i <= esq_fim; i++, iTemp++)
    {
        vTemp[iTemp] = v[i];
    }

    for (; j<= d; j++, iTemp++)
    {
        vTemp[iTemp] = v[j];
    }

    for (i = e, j=0; i <= d; i++, j++)
    {
        v[i] = vTemp[j];
    }

    free(vTemp);
}