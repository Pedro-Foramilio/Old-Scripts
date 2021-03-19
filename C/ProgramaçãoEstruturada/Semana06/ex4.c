/*
Escreva um programa que leia dois vetores de inteiros. Assuma que os dois vetores estão ordenados em ordem crescente. 
Depois, o programa deve imprimir todos os números lidos em ordem crescente, intercalando os valores dos dois vetores. 
Por exemplo, se os vetores lidos forem [1, 5, 8, 12, 90] e [2, 5, 7, 46], o programa deverá imprimir 1, 2, 5, 5, 7, 8, 12, 46, 90.



Entrada:

n1 (quantidade de elementos no vetor 1)
elementos do vetor 1
n2 (quantidade de elementos no vetor 2)
elementos do vetor 2
Saída:

elementos dos vetores 1 e 2 intercalados em ordem crescente 
(inclua um caractere espaço entre cada elemento, também inclua uma quebra de linha ao final)


Importante: o programa não pode usar colchetes, portanto, será necessário utilizar artimética de 
ponteiros para acessar os elementos dos vetores. Para alocar os vetores, use malloc.
*/

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *v, int tamanho) {
    int aux = 0;
    for (int i = tamanho; i > 0; i--) {
        for (int j = 0; j < i -1; j++) {
            if (*(v+j) > *(v+j+1)) {
                aux = *(v+j);
                *(v+j) = *(v+j+1);
                *(v+j+1) = aux;
                aux = 0;
            }
        }
    }  
}

int main() {

    int n1;
    scanf("%d", &n1);
    int *vetor1 = calloc(n1, sizeof(int));
    for (int i = 0; i < n1; i++) {
        scanf("%d", (vetor1 + i));
    }

    int n2;
    scanf("%d", &n2);
    int *vetor2 = calloc(n2, sizeof(int));
    for (int i = 0; i < n2; i++) {
        scanf("%d", (vetor2 + i));
    }

    int *vetorFinal = calloc((n1+n2), sizeof(int));
    int k = 0;
    for (int i = 0; i < n1; i++) {
        *(vetorFinal+i) = *(vetor1 + i);
        k++;
    }
    for (int i=0; i < n2; i++) {
        *(vetorFinal+k) = *(vetor2 + i);
        k++;
    }

    bubbleSort(vetorFinal, (n1+n2));

    for (int i=0; i < n1+n2; i++) {
        printf("%d ", *(vetorFinal+i));
    }


    /*
    while ( (k < n1) || (k < n2)) {

        if (k < n1){
            printf("%d ", *(vetor1 + k));
        }

        if (k < n2){
            printf("%d ", *(vetor2 + k));
        }
        k++;
    }
    */
    printf("\n");

    free(vetor1);
    free(vetor2);
    free(vetorFinal);
    return 0;
}



