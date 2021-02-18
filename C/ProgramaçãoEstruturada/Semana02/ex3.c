/*
Faça um programa que fique lendo números inteiros positivos:
• Cada número deverá ser inserido ordenado (ordem crescente) em um vetor (assuma que haverá no máximo 100 números).
• Após cada inserção, imprima o vetor completo. O programa encerra quando o usuário digitar o número -1 (não imprima o vetor após o usuário digitar -1, apenas encerre o programa).

Exemplo de funcionamento:

Digite: 5
5
Digite: 8
5 8
Digite: 2
2 5 8
Digite: 7
2 5 7 8
Digite: -1
*/

#include <stdio.h>

void bubbleSort(int v[], int tamanho) {
    int aux = 0;
    for (int i = tamanho; i > 0; i--) {
        for (int j = 0; j < i -1; j++) {
            if (v[j] > v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                aux = 0;
            }
        }
    }  
}

int main() {

    int input = 0, contador = 0;
    int vetor[100];

    while (input != -1) {
        scanf("%d", &input);
        if (input == -1) {
            break;
        }

        vetor[contador] = input;

        bubbleSort(vetor,contador+1);

        for (int i=0; i <= contador; i++) {
            if (i == contador) {
                printf("%d", vetor[i]);
            } else {
                printf("%d ", vetor[i]);
            }
        }
        printf("\n");
        contador++;
    }


    return 0;
}
