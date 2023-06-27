#include <stdlib.h>
#include <stdio.h>
#include "Grafos.h"

typedef struct Node Node;
int _does_edge_exist(Node *, int);
void _init_nodes(Graph *);

struct Graph
{
    int n_nodes, n_edges;
    Node **list_of_nodes;
};

struct Node
{
    int id_node;
    Node *adjacent;
};

Graph* new_graph(int n_nodes, int n_edges)
{
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->n_nodes = n_nodes;
    graph->n_edges = n_edges;

    graph->list_of_nodes = (Node **)malloc(sizeof(Node *) * n_nodes);
    _init_nodes(graph);
    return graph;
}

void _init_nodes(Graph *graph)
{
    Node *new_node;
    for (int i = 0; i < graph->n_nodes; i++)
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->id_node = i;
        graph->list_of_nodes[i] = new_node;
    }
    return;
}

void create_edge(Graph *graph, int id_node_1, int id_node_2)
{
    Node *node1 = graph->list_of_nodes[id_node_1];
    Node *node2 = graph->list_of_nodes[id_node_2];

    Node *new_node;
    // ta tudo cagado
    if (! _does_edge_exist(node1, id_node_2))
    {
        new_node = (Node *)malloc(sizeof(Node));
        new_node->id_node = id_node_2;
        new_node->adjacent = node1->adjacent;
        node1->adjacent = new_node;
    }

    if (! _does_edge_exist(node2, id_node_1))
    {
        new_node = (Node *)malloc(sizeof(Node));
        new_node->id_node = id_node_1;
        new_node->adjacent = node2->adjacent;
        node2->adjacent = new_node;
    }
    return;
}

int _does_edge_exist(Node *node_to_verify, int id_related_node)
{
    Node *current_node = node_to_verify;
    while (current_node != NULL)
    {
        if (node_to_verify->id_node == id_related_node) return 1;
        current_node = current_node->adjacent;
    }
    return 0;
}

void free_graph(Graph *graph)
{
    for (int i=0; i < graph->n_nodes; i++)
    {
        Node *current_node = graph->list_of_nodes[i];
        Node *temp;
        while (current_node != NULL)
        {
            temp = current_node;
            current_node = current_node->adjacent;
            free(temp);
        }
    }
    return;
}

void print_graph(Graph *graph)
{
    printf("---Iniciando impressao de grafo:---\n\n");
    for (int i=0; i < graph->n_nodes; i++)
    {
        Node *current_node = graph->list_of_nodes[i];
        printf("%d =>", current_node->id_node);
        current_node = current_node->adjacent;

        while (current_node != NULL)
        {
            printf(" %d ->", current_node->id_node);
            current_node = current_node->adjacent;
        }
        printf("end//\n");
    }
    printf("-----------------------------------\n\n");
    return;
}

