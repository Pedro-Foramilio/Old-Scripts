/*
Uma empresa está desenvolvendo um programa para cadastro de modelos de discos voadores. 
Cada modelo de disco é armazenado na estrututra DiscoVoador definida a seguir. 
A estrutura possui o modelo do disco, velocidade (em km/h), aceleração (em km/s2 ) 
e autonomia (em anos-luz).

Considere a estrutura DiscoVoador definida a seguir:

struct DiscoVoador {
    char modelo[50];
    int velocidade, aceleracao, autonomia;
};
Implemente a função insere_disco, que recebe um modelo de disco voador (parâmetro novo_disco), 
um vetor de discos (parâmetro discos) e a quantidade de modelos de discos. O vetor inicial já está ordenado, 
com os modelos armazenados nas primeiras n_discos posições, mas sem o novo disco). 
O vetor discos tem tamanho n_discos+1, portanto, há espaço para inserir um novo modelo de disco voador. 
A função deve inserir o novo modelo de disco no vetor passado, mantendo a ordenação.

Protótipo da função:

void insere_disco(struct DiscoVoador novo_disco, struct DiscoVoador discos[], int n_discos);
Critério para ordenação: A ordenação deve considerar os campos velocidade, 
aceleracao e autonomia, nesta ordem de prioridade (todos em ordem crescente). 
Por exemplo, um disco com velocidade=2 deve vir antes de um disco com velocidade=10. 
Outro exemplo, se os discos A e B tem velocidades iguais, mas o disco A tem aceleracao=40 e o
 disco B tem aceleracao=20, o disco B deve ficar antes na ordenação. 
 Se ocorrer empate nos campos velocidade e aceleracao, o desempate será pelo campo autonomia 
 (quem tiver a menor autonomia, deve ficar antes na ordenação).



Importante: submeta apenas a função. Não use variáveis globais. Não inclua o main. 
Não use printf/fprintf/puts/gets/fgets/scanf/fscanf e headers adicionais (por exemplo, stdio.h e stdlib.h).

A definição da struct DiscoVoador já existe no sistema de correção automática 
(portanto, não inclua a definição da struct no código submetido). 
É necessário incluir a seguinte linha no início do código submetido:

#include "discos.h"



Formato do caso de teste: esse é o formato dos casos de teste que aparecem ao avaliar a atividade; 
não inclua impressão de dados no código, essa impressão é feita automaticamente pelo sistema de correção 
de acordo com o retorno da função submetida.

Entrada:

dados do disco voador a ser inserido (modelo velocidade aceleracao autonomia)
quantidade de discos já existentes
lista de discos voadores no vetor inicial (modelo velocidade aceleracao autonomia)
Saída:

lista de discos voadores após a inserção do novo disco voador
*/
//#include "discos.h"
#include <stdio.h>

struct DiscoVoador {
    char modelo[50];
    int velocidade, aceleracao, autonomia;
};

void insere_disco(struct DiscoVoador novo_disco, struct DiscoVoador discos[], int n_discos) {
    int pos_inser;
    int vel, asc;
    int com_casos = 0;

    for(int i = 0; i < n_discos; i++) {
        if (discos[i].velocidade == novo_disco.velocidade) {
            vel = 0;
            pos_inser = i;

            com_casos = 1;
            break;
        }
        if (discos[i].velocidade > novo_disco.velocidade) {
            vel = 1;
            pos_inser = i;

            com_casos = 1;
            break;
        }
    }

    if (com_casos) {
        int com_casos2 = 0;

        if (!vel) {
            int percursor = pos_inser;
            while (discos[percursor].velocidade == novo_disco.velocidade) {
                
                if (discos[percursor].aceleracao == novo_disco.aceleracao) {
                    asc = 0;
                    pos_inser = percursor;

                    com_casos2 = 1;
                    break;
                }
                if (discos[percursor].aceleracao > novo_disco.aceleracao) {
                    asc = 1;
                    pos_inser = percursor;

                    com_casos2 = 1;
                    break;
                }

                percursor++;
            }

            if (com_casos2) {
                int com_casos3 = 0;

                if (! asc) {
                    percursor = pos_inser;
                    while (discos[percursor].aceleracao == novo_disco.aceleracao) {
                    
                        if (discos[percursor].autonomia > novo_disco.autonomia) {
                            asc = 1;
                            pos_inser = percursor;

                            com_casos3 = 1;
                            break;
                        }

                        percursor++;
                    }
                    if (!com_casos3)
                        pos_inser = percursor;

                }
            } else {
                pos_inser = percursor;
            }
        }
    } else {
        pos_inser = n_discos;
    }

    //deslocando o vetor pra direita
    for (int i = n_discos; i >= pos_inser; i--) {
        discos[i] = discos[i-1];
    }
    discos[pos_inser] = novo_disco;
    return;
}
