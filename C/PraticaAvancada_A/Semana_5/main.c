#include <stdlib.h>
#include <stdio.h>
#include "Grafos.h"

int main(int argc, char **argv)
{
    int i = atoi(argv[1]);
    int j = atoi(argv[2]);

    int id1, id2;

    Graph *graph = new_graph(i, j);
    printf("Graph created with %d nodes.\nInsert %d (i,j) pairs to create edges between them.\n", i, j);
    printf("Example:\n(1,2)\n");
    for (int n = 0; n < j; n++)
    {
        scanf("(%d,%d)", &id1, &id2);
        create_edge(graph, id1, id2);
    }

    print_graph(graph);
    free_graph(graph);

    return 0;
}
