typedef struct Node Node;
Node* tree_init_empty(void);
Node* tree_init(char c, Node *left, Node *right);
Node* tree_free(Node *tree);
int is_tree_empty(Node *tree);
int tree_contains(Node *tree, char c);
void print_tree(Node *tree);