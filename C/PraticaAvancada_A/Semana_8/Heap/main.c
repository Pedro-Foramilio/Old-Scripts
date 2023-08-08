#include <stdio.h>
#include "Heap.h"

int main()
{

    int n;
    scanf("%d", &n);

    int prioridades[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &prioridades[i]);
    }

    Heap *heap = heap_constroi(prioridades, n);

    print_heap(heap);

    return 0;
}
