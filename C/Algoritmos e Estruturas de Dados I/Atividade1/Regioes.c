#include <stdio.h>

//obs: (n+1)*n eh par para todo n natural
int maximoRegioes(int n)
{
    return ((n+1) * n / 2 ) + 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", maximoRegioes(n));

    return 0;
}

