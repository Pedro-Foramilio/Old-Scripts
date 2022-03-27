#include <stdio.h>
#include <stdlib.h>

void particiona(int *, int, int);

int main()
{
    int n, p, aux;
    scanf("%d", &n);
    int *v = (int *) malloc(sizeof(int) * n);
    scanf("%d", &p);

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &v[i]);
    }

    aux = v[p];
    v[p] = v[n-1];
    v[n-1] = aux;
    particiona(v, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", v[i]);
    }

    free(v);
    return 0;
}

void particiona(int *v, int e, int d)
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
    }

    aux = v[pm + 1];
    v[pm+1] = v[d];
    v[d] = aux;
}
