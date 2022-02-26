#include <stdio.h>

int main()
{
    char letra;
    int posicao;
    scanf("%c", &letra);

    posicao = ((int)letra) - 96 > 0 ? ((int)letra) - 96: ((int)letra) - 64;

    printf("%d\n", posicao);

    return 0;
}
