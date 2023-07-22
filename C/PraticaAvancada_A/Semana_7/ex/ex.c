#include <stdio.h>

int hash(int x, int m)
{
    return x % m;
}

int contains(int lista[], int k, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (lista[i] == k) return 1;
    }
    return 0;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int chaves[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &chaves[i]);
    }

    for (int i = 0; i < m; i++)
    {
        printf("%d -> ", i);
        for (int j = 0; j < n; j++)
        {
            int x_hash = hash(chaves[j], m);
            if (i == x_hash)
            {
                printf("%d -> ", chaves[j]);
            }
        }
        printf("\\\n");
    }

    return 0;
}
