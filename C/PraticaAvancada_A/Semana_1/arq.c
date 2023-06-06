#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    int result = n;
    int i = n-1;
    while (i > 0)
    {
        result = result *i;
        i--;
    }

    return result;
}

int main(char* argc, char* argv[])
{
    int n = atoi(argv[1]);

    printf("%d %d\n", n, factorial(n));

    return 0;
}
