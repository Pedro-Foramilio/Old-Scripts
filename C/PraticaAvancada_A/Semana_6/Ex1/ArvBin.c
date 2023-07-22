#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
    char info;
    struct Node *left;
    struct Node *right;
};

Node* inicializa_arv(char c, Node *left, Node *right)
{
    Node *new_node = (Node *) malloc(sizeof(struct Node));
    new_node->info = c;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

Node* tree_free(Node *node)
{
    if ( node != NULL)
    {
        tree_free(node->left);
        tree_free(node->right);
        free(node);

    }
    return NULL;
}

void print_preOrdem(Node *root)
{
    if (root != NULL)
    {
        printf("%c ", root->info);
        print_preOrdem(root->left);
        print_preOrdem(root->right);
    }
}

void print_EmOrdem(Node *root)
{
    if (root != NULL)
    {
        print_EmOrdem(root->left);
        printf("%c ", root->info);
        print_EmOrdem(root->right);
    }
}
void print_PosOrdem(Node *root)
{
    if (root != NULL)
    {
        print_PosOrdem(root->left);
        print_PosOrdem(root->right);
        printf("%c ", root->info);
    }
}

int main(void)
{
    Node *tree1 = inicializa_arv
    ('D', 
            inicializa_arv('B', 
                inicializa_arv('A', NULL, NULL),
                inicializa_arv('C', NULL, NULL)
            ),
            inicializa_arv('F',
                inicializa_arv('E', NULL, NULL),
                inicializa_arv('G', NULL, NULL)
            )
    );

    Node *tree2 = inicializa_arv
    ('C', 
            inicializa_arv('B', 
                inicializa_arv('A', NULL, NULL),
                NULL
            ),
            inicializa_arv('D',
                NULL,
                inicializa_arv('E', NULL, NULL)
            )
    );

    Node *tree3 = inicializa_arv
    ('E', 
            inicializa_arv('C', 
                inicializa_arv('B', inicializa_arv('A', NULL, NULL), NULL),
                inicializa_arv('D', NULL, NULL)
            ),
            inicializa_arv('H',
                inicializa_arv('F', NULL, inicializa_arv('G', NULL, NULL)),
                inicializa_arv('I', NULL, NULL)
            )
    );

    printf("Arvore 1\n");
    printf("Pre-ordem\n");
    print_preOrdem(tree1);
    printf("\n");
    printf("Em-ordem\n");
    print_EmOrdem(tree1);
    printf("\n");
    printf("Pos-ordem\n");
    print_PosOrdem(tree1);
    tree_free(tree1);
    printf("\n");

    printf("Arvore 2\n");
    printf("Pre-ordem\n");
    print_preOrdem(tree2);
    printf("\n");
    printf("Em-ordem\n");
    print_EmOrdem(tree2);
    printf("\n");
    printf("Pos-ordem\n");
    print_PosOrdem(tree2);
    tree_free(tree2);
    printf("\n");

    printf("Arvore 3\n");
    printf("Pre-ordem\n");
    print_preOrdem(tree3);
    printf("\n");
    printf("Em-ordem\n");
    print_EmOrdem(tree3);
    printf("\n");
    printf("Pos-ordem\n");
    print_PosOrdem(tree3);
    tree_free(tree3);
    printf("\n");

    return 0;
}
