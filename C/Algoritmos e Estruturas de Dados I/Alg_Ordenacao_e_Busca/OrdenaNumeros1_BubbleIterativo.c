#include <stdio.h>
#include <stdlib.h>

void bubbleIterativo(int *, int);
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

	bubbleIterativo(v, n);
	imprimeVetor(v, n);
	free(v);

	return 0;
}

void bubbleIterativo(int *v, int n)
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
			}
		}
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

