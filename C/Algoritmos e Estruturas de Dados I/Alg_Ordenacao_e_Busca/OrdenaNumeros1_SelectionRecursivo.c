#include <stdio.h>
#include <stdlib.h>

void selectionRecursivo(int *, int);
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

	selectionRecursivo(v, n);
	imprimeVetor(v, n);
	free(v);

	return 0;
}

void selectionRecursivo(int *v, int n)
{

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

