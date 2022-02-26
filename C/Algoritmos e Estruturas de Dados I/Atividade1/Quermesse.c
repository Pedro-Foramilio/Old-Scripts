#include <stdio.h>

int main()
{
    int teste = 1;

    int nParticipantes = 1;
    int ingressoAtual;

    while (nParticipantes != 0)
    {
        scanf("%d", &nParticipantes);
        if (nParticipantes == 0) break;

        printf("Teste %d\n", teste++);

        for (int i = 1; i <= nParticipantes; i++)
        {
            scanf("%d", &ingressoAtual);    
            if (ingressoAtual == i) printf("%d\n", ingressoAtual);
        }
        printf("\n");
    }

    return 0;
}
