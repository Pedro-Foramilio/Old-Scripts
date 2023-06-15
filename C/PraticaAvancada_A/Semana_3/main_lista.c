#include <stdio.h>
#include "Lista.h"

int main()
{
    Fila *f = fila_cria();
    fila_insere(f, 10);
    fila_insere(f, 20);
    fila_insere(f, 30);

    printf("%f\n", fila_retira(f));
    printf("%f\n", fila_retira(f));
    fila_insere(f, 40);
    printf("%f\n", fila_retira(f));
    printf("%f\n", fila_retira(f));
    printf("%d\n", is_fila_vazia(f));
    
    fila_insere(f, 40);
    fila_insere(f, 40);
    fila_insere(f, 40);

    fila_libera(f);

    return 0;

}
