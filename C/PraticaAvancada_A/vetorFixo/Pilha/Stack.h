typedef struct Stack Stack;
Stack *create_stack(void);
void push_stack(Stack *, float);
float pop_stack(Stack *);
int is_stack_empty(Stack *);
void free_stack(Stack *);
