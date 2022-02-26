#include <stdio.h>

int decisaoRodada(int numeroSorteado, int pontosJogador)
{
    return !((numeroSorteado + pontosJogador) % 2);
}

int main()
{
    int pontosSheldon = 0;
    int pontosLeonard = 0;
    int i = 1;
    int targetScore, nSorteado;
    scanf("%d", &targetScore);

    while (pontosSheldon < targetScore && pontosLeonard < targetScore)
    {
        scanf("%d", &nSorteado);
        if ( i % 2 == 0 )
        //leonard
        {
            pontosLeonard += decisaoRodada(nSorteado, pontosLeonard);
            if (pontosLeonard < 0) pontosLeonard = 0;
        } else
        //sheldon
        {
            pontosSheldon += decisaoRodada(nSorteado, pontosSheldon);
            if (pontosSheldon < 0) pontosSheldon = 0;
        }
        i++;
    }

    printf("%s\n", targetScore == pontosSheldon ? "Sheldon" : "Leonard");

    return 0;    
}
