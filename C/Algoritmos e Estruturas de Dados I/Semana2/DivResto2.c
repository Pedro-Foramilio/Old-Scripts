//mesmo ex do DivResto mas com solucao alternativa

#include <stdio.h>

void divResto(int a, int b, int *p_div, int *p_rest)
{
    *p_div = (int) a / b;
    *p_rest = (int) a % b;
    return;
}

int main(void)
{
    int a, b, divisao, resto;
    scanf("%d %d", &a, &b);
    divResto(a, b, &divisao, &resto);
    printf("%d %d\n", divisao, resto);
    return 0;
}