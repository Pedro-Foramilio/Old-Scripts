#include <stdio.h>
#include <stdlib.h>

void selectionIterativo(int *, int);
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

	selectionIterativo(v, n);
	imprimeVetor(v, n);
	free(v);

	return 0;
}

void selectionIterativo(int *v, int n)
{
    int i, j, iMin, aux;
    for (i=0; i<n-1; i++)
    {
        for (j = i+1, iMin = i; j < n; j++)
        {
            if (v[j] < v[iMin])
                iMin = j;
        }
        aux= v[i];
        v[i] = v[iMin];
        v[iMin] = aux;
    }
    return;
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

