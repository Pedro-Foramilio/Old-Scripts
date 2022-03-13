#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *, int, int);
void intercala(int *, int, int, int);

void imprimeVetor(int *, int);

int main(void)
{
	int n;
	int *v;
	
	scanf("%d", &n);

	if (n < 1) return 0;
	
	v = (int *) malloc(sizeof(int) * n);
	
	for (int i=0; i<n; i++)
		scanf("%d", &v[i]);

	mergeSort(v, 0, n-1);
	imprimeVetor(v, n);
	free(v);

	return 0;
}

void mergeSort(int *v, int e, int d)
{
    int meio;
    if (e < d)
    {
        meio = (e+d)/2;
        mergeSort(v, e, meio);
        mergeSort(v, meio+1, d);
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

void imprimeVetor(int *v, int n)
{
	int i = 0;
	while(i < n-1)
	{
		printf("%d ", v[i]);
		i++;
	}
	printf("%d\n", v[i]);
	return;
}

