typedef struct Queue Queue;
Queue* create_Q(void);
void insert_Q(Queue *, float);
float remove_Q(Queue *);
int is_queue_empty(Queue *);
void free_Q(Queue *);