/*
Considere a estrutura a seguir para armazenar dados de um time de futebol:

struct TimeFutebol {
    char *nome;
    int pontos, gols, vitorias, derrotas, empates;
};
Escreva um programa que leia os dados de um time de futebol e armazene em uma estrutura struct TimeFutebol.

Após preencher os dados, chame a função imprimir e passe a estrutura preenchida. 
Essa função, que já está implementada no sistema de correção automática, 
irá imprimir os dados do time de futebol.

Protótipo da função imprimir:

void imprimir(struct TimeFutebol dados_time);


Importante: Não use variáveis globais. Não use printf/puts/fprintf. 
Neste exercício, pode usar stdio.h e stdlib.h. A impressão deve ser feita com a função imprimir.

A definição da struct TimeFutebol já existe no sistema de correção automática 
(portanto, não inclua a definição da struct no código submetido). 
A função imprimir também já existe no sistema de correção. 
É necessário incluir a seguinte linha no início do código programa:

#include "estruturas.h"
*/

//#include "estruturas.h"

#include <stdio.h>
#include <stdlib.h>

struct TimeFutebol {
    char *nome;
    int pontos, gols, vitorias, derrotas, empates;
};

int main() {
    struct TimeFutebol dados;
    dados.nome = malloc(sizeof(char) * 100);
    scanf("%s %d %d %d %d %d", 
    dados.nome, &dados.pontos, &dados.gols, &dados.vitorias, &dados.derrotas, &dados.empates);

    //imprimir(dados);
    printf("%s %d %d %d %d %d", 
    dados.nome, dados.pontos, dados.gols, dados.vitorias, dados.derrotas,dados.empates);

    free(dados.nome);
    return 0;
}
