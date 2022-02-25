#include <stdio.h>
#include <stdlib.h>

int buscaLinear(int *v, int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (v[i] == x)
            return 1;
    }
    return 0;
}

int main()
{
    int tamanhoVetor, numeroBuscas, i, valor;
    int *vetor;

    scanf("%d", &tamanhoVetor);
    vetor = (int*) malloc(tamanhoVetor * sizeof(int));

    for (i = 0; i < tamanhoVetor; i++)
    {
        scanf("%d", &vetor[i]);
    }

    scanf("%d", &numeroBuscas);

    for(i = 0; i < numeroBuscas; i++)
    {
        scanf("%d", &valor);
        printf("%sACHEI\n", buscaLinear(vetor, tamanhoVetor, valor)? "" : "NAO ");
    }

    free(vetor);

    return 0;
}
