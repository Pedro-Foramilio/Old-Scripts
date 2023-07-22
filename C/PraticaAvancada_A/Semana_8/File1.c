#include <stdio.h>

int maxBy(float lista[], float maxBy, int tam)
{
    float maximo = 0;
    int index = -1;
    for (int i = 0; i < tam; i++)
    {
        //printf("lista[%d]:%f maxBy: %f max:%f\n", i, lista[i], maxBy, maximo);
        if (lista[i] > maximo && lista[i] < maxBy)
        {
            maximo = lista[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    int beneficios[] = {8, 16, 20, 12, 6, 10, 4};
    int pesos[] = {3, 7, 9, 6, 3, 5, 2};
    int capacidade = 17;

    float relacao[7];
    for (int i = 0; i < 7; i++)
    {
        relacao[i] = (float)beneficios[i] / (float)pesos[i];
        printf("Relacao: %f\n", relacao[i]);
    }

    int contador = 0;
    int cap = 0;
    int beneficio_acumulado = 0;
    float maximo = __FLT_MAX__;
    int indice_axuiliar;
    while (cap < capacidade && contador < 7)
    {
        contador++;
        indice_axuiliar = maxBy(relacao, maximo, 7);
        maximo = relacao[indice_axuiliar];
        printf("indice %d maximo %f %d %d\n", indice_axuiliar, maximo, beneficio_acumulado, cap);
        if (cap + pesos[indice_axuiliar] > capacidade || indice_axuiliar == -1) continue;
        beneficio_acumulado += beneficios[indice_axuiliar];
        cap += pesos[indice_axuiliar];
    }

    printf("Beneficio: %d - peso: %d\n", beneficio_acumulado, cap);
    return 0;
}


