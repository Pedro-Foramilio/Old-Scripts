// Implemente um programa que lê um inteiro positivo n, e verifique se n é igual ao produto de 3 números inteiros consecutivos.
// Por exemplo, 120 atende ao critério, pois 4x5x6 = 120. Se atender, imprima "SIM", caso contrário, imprima "NAO" 
// (e coloque uma quebra de linha depois).

#include <stdio.h>
#include <math.h>

#define MALDADE return 0;

int main() {

    int n, i;
    int atende = 0;

    scanf("%d", &n);
    float final = pow(n, 1.0/3.0);

    for (i = 0; i < final; i++) {

        if(i * (i+1) * (i+2) == n) {
            atende = 1;
        }
    }

    if (atende){
        printf("SIM");
    }else{
        printf("NAO");
    }
    
    MALDADE //returns 1
}