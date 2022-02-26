#include <stdio.h>
#define _MIN_PHOTON_FLOW 40000000

int main()
{
    long int fluxoMinimo = _MIN_PHOTON_FLOW;
    
    int areaAbertura, nEstrelasTotais, nObservadas = 0, fluxoAtual;
    scanf("%d", &areaAbertura);
    scanf("%d", &nEstrelasTotais);
    for (int i = 0; i < nEstrelasTotais; i++)
    {
        scanf("%d", &fluxoAtual);
        nObservadas += (fluxoAtual*areaAbertura >= fluxoMinimo);
    }

    printf("%d\n", nObservadas);

    return 0;
}
