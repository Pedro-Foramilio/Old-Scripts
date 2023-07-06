#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct Node
{
    char info;
    struct Node *left;
    struct Node *right;
};

Node* tree_init_empty(void)
{
    return NULL;
}

Node* tree_init(char c, Node *left, Node *right)
{
    Node *p = (Node *) malloc(sizeof(Node));
    p->info = c;
    p->left = left;
    p->right = right;
    return p;
}

Node* tree_free(Node *tree)
{
    if (! is_tree_empty(tree))
    {
        tree_free(tree->left);
        tree_free(tree->right);
        free(tree);
    }
    return NULL;
}

int is_tree_empty(Node *tree)
{
    return tree == NULL;
}

int tree_contains(Node *tree, char c)
{
    if (is_tree_empty(tree))
    {
        return 0;
    }

    return tree->info == c || tree_contains(tree->left, c) || tree_contains(tree->right, c);
}

void print_tree(Node *tree)
{
    if (is_tree_empty(tree))
    {
        return;
    }

    printf("%c ", tree->info);
    print_tree(tree->left);
    print_tree(tree->right);
    
    return;
}

/*
As duas funções para a criação de árvores representam
os dois casos da definição recursiva de árvore binária:
• uma árvore binária Arv* a;
– é vazia a=arv_criavazia()
– é composta por uma raiz e duas sub-árvores a=arv_cria(c,sae,sad);
*/