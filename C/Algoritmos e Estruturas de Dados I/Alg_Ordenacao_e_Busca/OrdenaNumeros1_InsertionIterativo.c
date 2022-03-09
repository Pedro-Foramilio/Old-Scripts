#include <stdio.h>
#include <stdlib.h>

void insertionIterativo(int *, int);
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

	insertionIterativo(v, n);
	imprimeVetor(v, n);
	free(v);

	return 0;
}

void insertionIterativo(int *v, int n)
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
        }
    }
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

