#include <stdio.h>
#include <stdlib.h>

int particiona(int *, int, int, int);
void quickSort(int *, int, int, int);

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

	imprimeVetor(v, n);
	quickSort(v, 0, n-1, n);
	imprimeVetor(v, n);
	free(v);

	return 0;
}

void quickSort(int *v, int e, int d, int n)
{
    int p, tam, i, aux;
    if (e < d)
    {
        p = particiona(v, e, d, n);
        quickSort(v, e, p-1, n);
        quickSort(v, p+1, d, n);
    }
}

int particiona(int *v, int e, int d, int n)
{
    int pm = e -1, i, aux;
    for (i = e; i < d; i++)
    {
        if (v[i] <= v[d])
        {
            pm++;
            aux = v[pm];
            v[pm] = v[i];
            v[i] = aux;
        }
    	imprimeVetor(v, n);
    }

    aux = v[pm + 1];
    v[pm+1] = v[d];
    v[d] = aux;

    imprimeVetor(v, n);
    return pm+1;
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

