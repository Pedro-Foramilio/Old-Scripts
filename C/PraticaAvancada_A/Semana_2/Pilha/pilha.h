typedef struct pilha Pilha;

Pilha* criar(void);
void push(Pilha *p, float v);
float pop(Pilha *p);
int esta_vazia(Pilha *p);
void liberar(Pilha *p);
