#include <stdio.h>
#include <stdlib.h>

float somaDiagonal(int ** m, int n)
{
    int i ;
    float soma = 0.f;
    for (i = 0; i < n; i++)
    {
        soma += m[i][i];
    }
    return soma;
}

float mediaDiagonal(int ** mat, int n)
{
    return somaDiagonal(mat, n)/ (float)n;
}

int main()
{
    char op;
    int n, **mat, i, j;

    scanf("%c", &op);
    scanf("%d", &n);

    mat = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        mat[i] = (int *) malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    if(op == 'S')
    {
        printf("%.1f\n", somaDiagonal(mat, n));
    } else {
        printf("%.1f\n", mediaDiagonal(mat, n));
    }

    for (i = 0; i < n; i++)
    {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
