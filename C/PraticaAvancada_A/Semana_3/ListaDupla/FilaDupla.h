
typedef struct D_Queue D_Queue;
D_Queue* create_list(void);
void insert_ini(D_Queue *f, float v);
void insert_end(D_Queue *f, float v);
float remove_ini(D_Queue *f);
float remove_end(D_Queue *f);
int is_list_empty(D_Queue *f);
void free_list(D_Queue *f);
