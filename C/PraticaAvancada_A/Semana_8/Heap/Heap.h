typedef struct Heap Heap;
Heap* heap_cria(int max);
void heap_insere(Heap *heap, int prioridade);
int heap_remove(Heap *heap);
void heap_liberate(Heap *heap);