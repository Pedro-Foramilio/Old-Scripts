#include <stdio.h>

int ehBissexto(int n)
{
    return !(n % 400) || (!(n % 4) && (n%100) );
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("ANO%s BISSEXTO\n", ehBissexto(n)? "" :" NAO");

    return 0;
}
