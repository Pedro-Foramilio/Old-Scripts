
typedef struct Cliente Cliente;
Cliente* criar_cliente(char nome[], float deposito);
typedef struct FilaClientes FilaClientes;
void atendimentoCaixaBanco(FilaClientes *f);
FilaClientes* criar_fila(void);
void inserir_fila(FilaClientes *fila, Cliente *cliente);
void liberar_fila(FilaClientes *f);
