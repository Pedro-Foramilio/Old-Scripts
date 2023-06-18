#include <stdio.h>
#include "TAD_Fila_Clientes.h"

int main()
{
    char nome[80];
    float valor;
    FilaClientes *fila = criar_fila();
    while(scanf("%s %f", nome, &valor) != EOF)
    {
        Cliente *c = criar_cliente(nome, valor);
        inserir_fila(fila, c);
    }
    atendimentoCaixaBanco(fila);
    liberar_fila(fila);
    return 0;
}