#include "TAD_Fila_Clientes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Cliente Cliente;
struct Cliente
{
    char nome[80];
    float valorDeposito;
};

typedef struct Lista Lista;
struct Lista
{
    Cliente *info;
    Lista *prox;
};

typedef struct FilaClientes FilaClientes;
struct FilaClientes
{
    Lista *ini;
    Lista *fim;     
};

Cliente* criar_cliente(char *name, float deposito)
{
    Cliente *c = (Cliente *) malloc(sizeof(Cliente));
    strcpy(c->nome, name);
    c->valorDeposito = deposito;
}

void atendimentoCaixaBanco(FilaClientes *f)
{
    Lista *q = f->ini;
    int counter = 1;
    float ValorTotal = 0;
    while (q != NULL)
    {
        printf("Cliente %d - %s atendido, deposito de %.0f reais\n", 
            counter, q->info->nome, q->info->valorDeposito);
        counter++;
        ValorTotal += q->info->valorDeposito;
        q = q->prox;
    }

    printf("Total de clientes: %d\n", counter-1);
    printf("Deposito total: %0.f reais\n", ValorTotal);
}

FilaClientes* criar_fila(void)
{
    FilaClientes *fila = (FilaClientes *)malloc(sizeof(FilaClientes));
    fila->ini = NULL;
    fila->fim = NULL;
    return fila;
}

void inserir_fila(FilaClientes *fila, Cliente *cliente)
{
    Lista *n = (Lista *)malloc(sizeof(Lista));
    n->info = cliente;
    n->prox = NULL;

    if (fila->fim != NULL)
    {
        fila->fim->prox = n;
    }
    else
    {
        fila->ini = n;
    }

    fila->fim = n;
    return;
}

void liberar_fila(FilaClientes *f)
{
    Lista *q = f->ini;
    while (q != NULL)
    {
        Lista *t = q->prox;
        free(q->info);
        free(q);
        q = t;
    }
    free(f);
    return;
}

