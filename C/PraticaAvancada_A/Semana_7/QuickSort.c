#include <stdio.h>

void quickSort(int n, int *v)
{
    if (n <= 1) return;

    int x = v[0];
    int a = 1;
    int b = n-1;

    do 
    {
        while (a < n && v[a] >= x) a++;
        while (v[b] < x) b--;

        if (a < b)
        {
            int temp = v[a];
            v[a] = v[b];
            v[b] = temp;
            a++;
            b--;
        }
    } while (a <= b);

    v[0] = v[b];
    v[b] = x;

    quickSort(b, v);
    quickSort(n-a, &v[a]);
}

int main(void)
{
    int n, q;
    int p = 0;
    scanf("%d %d", &n, &q);

    int numeros[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numeros[i]);
    }

    quickSort(n, numeros);

    for (int i = 0; i < q; i++)
    {
        scanf("%d", &p);
        printf("%d\n", numeros[p-1]);
    }

    return 0;
}
