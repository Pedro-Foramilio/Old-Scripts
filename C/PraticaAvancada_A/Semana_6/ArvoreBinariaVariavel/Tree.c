#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

struct Tree
{
    char info;
    Tree *first; //chield
    Tree *next; //sibbiling
};

Tree *create_tree(char c)
{
    Tree *t = (Tree *)malloc(sizeof(Tree));
    t->info = c;
    t->first = NULL;
    t->next = NULL;
    return t;
}

void insert_tree(Tree *root, Tree* new_node)
//inserts the new tree as the first sibbling of the list
//defined by next
{
    new_node->next = root->first;
    root->first = new_node;
}

void print_tree(Tree *t)
{
    Tree *p;
    printf("<%c\n", t->info);
    for (p = t->first; p != NULL; p = p->next)
    {
        print_tree(p);
    }
    printf(">\n");
}

int contains_tree(Tree *t, char c)
{
    Tree *p;
    if (t->info == c) return 1;

    for (p = t->first; p != NULL; p = p->next)
    {
        if (contains_tree(p, c)) return 1;
    }

    return 0;
}

void free_tree(Tree *t)
{
    Tree *p = t->first;
    Tree *q;
    while (p != NULL)
    {
        q = p->next;
        free_tree(p);
        p = q;
    }
    free(t);
    return;
}

int height(Tree *t)
{
    int hmax = -1;
    Tree *p;
    for (p = t->first; p != NULL; p=p->next)
    {
        int h = height(p);
        if (h > hmax) hmax = h;
    }
    return hmax;
}

int static max2(int a, int b) { return a > b ? a : b; }

int height2(Tree *t)
{
    if (t == NULL) return -1;
    else
    {
        return max2(1 + height2(t->first), height2(t->next));
    }
}
