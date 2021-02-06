// Faça um programa conforme descrito a seguir:

//  1.    Leia um código de operação:

// ·         1: soma dois números (a + b)

// ·         2: soma três números (a + b + c)

// ·         3: multiplicação de dois números (a * b)

// ·         0: sair

// 2.    Se o usuário digitar a operação sair, o programa mostra o menor resultado obtido e encerra;

// 3.    Caso contrário, solicitará a entrada dos números (a e b ou a, b e  c) e 
//         imprimirá o resultado da operação (soma ou multiplicação); Após isso, o programa volta ao item 1 (ler código de operação).

// Observação: inclua uma quebra de linha após a impressão do resultado.

#include <stdio.h>


int main(){

    int codigoOperacao = -1;
    int resultado, a, b, c;
    int menorResultado = 1000;

    while (codigoOperacao != 0) {
        scanf("%d", &codigoOperacao);
        
        if (codigoOperacao == 1) { //(a + b)
            scanf("%d %d", &a, &b);
            resultado = a + b;

            if (resultado < menorResultado) {
                menorResultado = resultado;
            }
            printf("%d\n", resultado);
        }

        if (codigoOperacao == 2) {
            scanf("%d %d %d", &a, &b, &c);
            resultado = a + b + c;

            if (resultado < menorResultado) {
                menorResultado = resultado;
            }
            printf("%d\n", resultado);
        }

        if (codigoOperacao == 3) {
            scanf("%d %d", &a, &b);
            
            resultado = a * b;
            if (resultado < menorResultado) {
                    menorResultado = resultado;
                }
            printf("%d\n", resultado);
        }
    }

    printf("%d\n", menorResultado);

    return 0;
}
