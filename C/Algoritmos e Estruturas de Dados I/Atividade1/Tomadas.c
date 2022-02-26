#include <stdio.h>

//qtdBocasTotais = nTomadas * (qtdBocas -1 para cada tomada) + 1
int main()
{
    int nTomadas = 4;
    int qtdBocas = 0;
    int qtdBocasTotais = 1; //evitar +1 no final

    for (int i = 0; i < nTomadas; i++)
    {
        scanf("%d", &qtdBocas);
        qtdBocasTotais += qtdBocas-1;
    }

    printf("%d\n", qtdBocasTotais);

    return 0;
}