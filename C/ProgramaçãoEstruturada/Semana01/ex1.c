//Faça um programa que leia um inteiro N≥1 da entrada padrão. Na sequência leia N números reais. 
//Seu programa deve imprimir, com duas casas decimais e nessa ordem:
//
//menor valor;
//maior valor;
//média.
//Seu programa não pode armazenar os valores em um vetor!

#include  <stdio.h>

int main()
{
    int  i, n;
    float soma, media, aux, maior, menor;
    soma = 0.0;
    aux = 0;
    media = 0;

    scanf("%d", &n);
    
    for (i=0; i < n; i++)
    {
        scanf("%f", &aux);
        if (i == 0)
        {
            maior = aux;
            menor = aux;
        }

        if (aux > maior)
        {
            maior = aux;
        }

        if (aux < menor)
        {
            menor = aux;
        }
        soma += aux;
        aux = 0;
    }
    
    media = (float) soma / n;
    printf("%.2f\n", menor);
    printf("%.2f\n", maior);
    printf("%.2f\n", media);

    return 0;
}