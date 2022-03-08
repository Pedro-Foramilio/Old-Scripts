#include <stdio.h>
#include <stdlib.h>

void bubbleRecursivo(int *, int);
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

	bubbleRecursivo(v, n);
	imprimeVetor(v, n);
	free(v);

	return 0;
}

void bubbleRecursivo(int *v, int n)
{
    if (n == 1) return;
    int aux;
    for (int i = 0; i < n-1; i++)
    {
        if (v[i] > v[i+1])
        {
            aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
        }
    }
    bubbleRecursivo(v, n-1);
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

