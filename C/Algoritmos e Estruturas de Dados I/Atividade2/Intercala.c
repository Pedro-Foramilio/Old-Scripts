#include <stdio.h>
#include <stdlib.h>

void intercala(int *, int , int , int);

int main()
{
    int n1, n2;
    int *v;

    scanf("%d", &n1);
    scanf("%d", &n2);

    v = (int*) malloc((n1 + n2) * sizeof(int));

    for (int i = 0; i < (n1 + n2); i++)
    {
        scanf("%d", &v[i]);
    }

    intercala(v, 0, n1, n1+n2-1);
    
    for (int i = 0; i < (n1 + n2); i++)
        printf("%d\n", v[i]);

    free(v);
    
    return 0;
}

void intercala(int *v, int e, int m, int d)
{
    int esq_fim = m - 1, tamanho = d-e+1, i, j, iTemp;
    int *vTemp = (int *) malloc(tamanho * sizeof(int));

    for(i = e, j = m, iTemp = 0; i <= esq_fim && j <= d; iTemp++)
    {
        if (v[i] < v[j])
        {
            vTemp[iTemp] = v[i];
            i++;
        } else {
            vTemp[iTemp] = v[j];
            j++;
        }
    }

    for (; i <= esq_fim; i++, iTemp++)
    {
        vTemp[iTemp] = v[i];
    }

    for (; j<= d; j++, iTemp++)
    {
        vTemp[iTemp] = v[j];
    }

    for (i = e, j=0; i <= d; i++, j++)
    {
        v[i] = vTemp[j];
    }

    free(vTemp);
}