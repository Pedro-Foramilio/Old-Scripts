// Recebendo como entrada dois valores inteiros, 
// calcular a quantidade de números primos entre esses dois valores (incluindo eles).

#include <stdio.h>

int ehPrimo(int n) {
    int divisores = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisores += 1;
        }
    }
    if (divisores == 2) {
        return 1;
    }
    return 0;
}

int main() {
    int qtdPrimos = 0;
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    for (int i = n1; i <= n2; i++) {
        if (ehPrimo(i)) {
            qtdPrimos++;
        }
    }

    printf("%d", qtdPrimos);

    return 0;
}