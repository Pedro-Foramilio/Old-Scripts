/*
Considere a estrutura ListaNumeros definida a seguir:

typedef struct ListaNumeros ListaNumeros;
struct ListaNumeros {
    int *numeros;
    int *primos;
    int n_numeros, n_primos;
};
Implemente a função separa_numeros_primos, que recebe um ponteiro para uma estrutura ListaNumeros. 
A estrutura é passada como um vetor no campo numeros (a quantidade de números é armazenada em n_numeros). 
O valor preenchido no campo primos é NULL (e n_primos = 0).

Se existir números primos no vetor passado em numeros, eles devem ser removidos e 
colocados em um novo vetor que será referenciado pelo campo primos da estrutura. 
Portanto, se existir números primos, será necessário alocar um novo vetor para armazenar os números primos. 
Também deve ser preenchido o valor do campo n_primos com a quantidade de números primos.

Por exemplo, se estrutura for recebida como:

numeros = [3, 40, 11, 507, 10]
n_numeros = 5
primos = NULL
n_primos = 0
A função deve alterar os valores na estrutura para:

numeros = [40, 507, 10]
n_numeros = 3
primos = [3, 11]
n_primos = 2
Observação: a ordem relativa dos números deve ser mantida. No exemplo, 40 vinha antes de 507, 
que por sua vez vinha antes de 10 no vetor numeros. A ordem relativa foi mantida. 
O mesmo vale para o vetor primos, que deve manter a ordem relativa entre os números que existia 
no vetor numeros.



Protótipo da função:

void separar_numeros_primos(ListaNumeros *lista);


Importante: submeta apenas a função. Não use variáveis globais. Não inclua o main. 
Não use printf/fprintf/puts/gets/fgets/scanf/fscanf e headers adicionais (por exemplo, stdio.h). 
Neste exercício, pode usar stdlib.h e math.h.


A definição da struct ListaNumeros já existe no sistema de correção automática 
(portanto, não inclua a definição da struct no código submetido). 
É necessário incluir a seguinte linha no início do código submetido:

#include "primos.h"



Formato do caso de teste: esse é o formato dos casos de teste que aparecem ao avaliar a atividade; 
não inclua impressão de dados no código, essa impressão é feita automaticamente pelo sistema de correção 
de acordo com o retorno da função submetida.

Entrada:

quantidade de números
lista de números
Saída:

lista de números não primos e lista de números primos (após executar a função separar_numeros_primos)
*/

//#include "primos.h"
#include <stdlib.h>

typedef struct ListaNumeros ListaNumeros;
struct ListaNumeros {
    int *numeros;
    int *primos;
    int n_numeros, n_primos;
};

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

void separar_numeros_primos(ListaNumeros *lista) {
    int qtdPrimos = 0;
    for (int i = 0; i < lista->n_numeros; i++) {
        if (ehPrimo(lista->numeros[i])) {
            qtdPrimos++;
        }
    }

    lista->n_primos = qtdPrimos;
    lista->primos = malloc(sizeof(int) * qtdPrimos);

    int numerosNovos[lista->n_numeros - qtdPrimos];

    int percursor = 0;
    for (int i = 0; i < lista->n_numeros; i++) {
        if (ehPrimo(lista->numeros[i])) {
            lista->primos[percursor] = lista->numeros[i];
            percursor++;
            lista->numeros[i] = NULL;
        }
    }
    percursor = 0;
    for (int i = 0; i < lista->n_numeros; i++) {
        if (lista->numeros[i] != NULL) {
            numerosNovos[percursor] = lista->numeros[i];
            percursor++;
        }
    }

    for (int i = 0; i < percursor; i++) {
        lista->numeros[i] = numerosNovos[i];
    }
    lista->n_numeros -= qtdPrimos;

    return;
}
