#include <stdio.h>

int main()
{
    int gabarito = 0;
    int pontuacao = 0;
    int chute = 0;
    int nAtletas = 5;
    scanf("%d", &gabarito);

    for (int i = 0; i < nAtletas; i++)
    {
        scanf("%d", &chute);
        pontuacao += (chute == gabarito);
    }

    printf("%d\n", pontuacao);

    return 0;
}