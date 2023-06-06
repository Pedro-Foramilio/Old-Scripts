#include <stdio.h>
#include "pilha.h"

int main(void)
{
    Pilha *p = criar();
    push(p, 10);
    push(p, 20);
    push(p, 30);


    printf("%f\n", pop(p));
    printf("%f\n", pop(p));
    printf("%f\n", pop(p));

    liberar(p);

    return 0;

}