
typedef struct Fila Fila;
Fila* fila_cria(void);
void fila_insere(Fila *f, float v);
float fila_retira(Fila *f);
void fila_libera(Fila *f);
int is_fila_vazia(Fila *f);
