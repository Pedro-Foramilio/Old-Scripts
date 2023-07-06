typedef struct Tree Tree;
Tree *create_tree(char c);
void insert_tree(Tree *root, Tree* new_node);
void print_tree(Tree *t);
int contains_tree(Tree *t, char c);
void free_tree(Tree *t);
int height(Tree *);
int height2(Tree *);