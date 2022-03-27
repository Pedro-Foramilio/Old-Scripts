#include <stdio.h>
#include <stdlib.h>

int isOrderedIncreasing(int *, int);
int isOrderedDecreasing(int *, int);

int main()
{
    int n;
    int *vetor;
    while (scanf("%d", &n) != EOF)
    {
        if (n < 1) 
        {
            printf("S\n");
            continue;
        }

        vetor = (int *) malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &vetor[i]);
        }

        printf("%c\n", 
            isOrderedDecreasing(vetor, n) ||isOrderedIncreasing(vetor, n) ? 'S': 'N');

        free(vetor);
    }

    return 0;
}

int isOrderedDecreasing(int *v, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        if (v[i] < v[i+1])
            return 0;
    }
    return 1;
}

int isOrderedIncreasing(int *v, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        if (v[i] > v[i+1])
            return 0;
    }
    return 1;
}

