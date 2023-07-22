#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
    int custo;
    struct Node *left;
    struct Node *right;
};

Node* inicializa_arv(int c, Node *left, Node *right)
{
    Node *new_node = (Node *) malloc(sizeof(struct Node));
    new_node->custo = c;
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
        printf("%d ", root->custo);
        print_preOrdem(root->left);
        print_preOrdem(root->right);
    }
}

void print_EmOrdem(Node *root)
{
    if (root != NULL)
    {
        print_EmOrdem(root->left);
        printf("%d ", root->custo);
        print_EmOrdem(root->right);
    }
}
void print_PosOrdem(Node *root)
{
    if (root != NULL)
    {
        print_PosOrdem(root->left);
        print_PosOrdem(root->right);
        printf("%d ", root->custo);
    }
}

int maior_custo(Node *node)
{
    if (node == NULL) return 0;

    int maior = 0;
    int custo_esq = 0;
    int custo_dir = 0;

    custo_esq = maior_custo(node->left);
    custo_dir = maior_custo(node->right);

    if (custo_esq > custo_dir)
    {
        maior = custo_esq;
    }
    else
    {
        maior = custo_dir;
    }

    return maior + node->custo; 
}

void somaCaminhoLongo(Node *node, int soma, int len, int *max_len, int *max_sum)
{
    if (node == NULL)
    {
        if (len > *max_len)
        {
            *max_len = len;
            *max_sum = soma;
        }
        else if (*max_len == len && soma > *max_sum)
        {
            *max_sum = soma;
        }
        return;
    }

    somaCaminhoLongo(node->left, soma + node->custo, len + 1, max_len, max_sum);
    somaCaminhoLongo(node->right, soma + node->custo, len + 1, max_len, max_sum);
}

int custo_maior_caminho(Node *node)
{
    if (node == NULL) return 0;
    int max_sum = 0;
    int max_len = 0;

    somaCaminhoLongo(node, 0, 0, &max_len, &max_sum);
    return max_sum;
}

int main(void)
{
    Node *tree1 = inicializa_arv(
        34,
            inicializa_arv(24,
                inicializa_arv(11,
                    inicializa_arv(5, NULL, NULL),
                    NULL
                ),
                inicializa_arv(19,
                    NULL,
                    NULL
                )
            ),
            inicializa_arv(17,
                inicializa_arv(7, 
                    NULL, 
                    NULL
                ),
                inicializa_arv(9,
                    NULL,
                    NULL
                )
            )    
        );
    
    print_preOrdem(tree1);
    int custo = maior_custo(tree1);
    int custo_m_c = custo_maior_caminho(tree1);
    printf("\nmaior custo: %d\n", custo);
    printf("maior caminho (custo): %d\n", custo_m_c);
    tree_free(tree1);

    return 0;
}
