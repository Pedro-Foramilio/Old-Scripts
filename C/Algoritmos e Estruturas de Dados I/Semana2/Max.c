#include <stdio.h>

int main()
{
    int n, max;
    scanf("%d", &max);
    n = max;
    while (n >= 0)
    {
        scanf("%d", &n);
        if (n > max)
            max = n;
    }

    if(max >= 0)
        printf("%d\n", max);
    else
        printf("nenhum numero informado\n");

    return 0;
}
