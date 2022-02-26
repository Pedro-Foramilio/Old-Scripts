#include <stdio.h>

int maior(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    printf("%d eh o maior.\n", maior(a, maior(b, c)));

    return 0;
}
