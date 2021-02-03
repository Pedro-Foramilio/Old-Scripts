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
    int soma, aux, n, media, maior, menor;
    soma = 0;
    aux = 0;
    media = 0;

    scanf("%d", &n);
    
    for (int i=0; i < n; i++)
    {
        scanf("%d", &aux);
        if (n == 0)
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
    }
    
    media = soma / n;
    printf("%d", menor);
    printf("%d", maior);
    printf("%d", media);

    return 0;
}