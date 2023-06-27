typedef struct Graph Graph;
Graph* new_graph(int, int);
void create_edge(Graph *, int, int);
void free_graph(Graph *);
void print_graph(Graph *);