#include <stdlib.h>
#include "FilaDupla.h"

typedef struct List List;
struct List
{
    float info;
    List *next;
    List *prev;
};

typedef struct D_Queue D_Queue;
struct D_Queue
{
    List *first;
    List *last;
};

D_Queue* create_queue(void)
{
    D_Queue *f = (D_Queue *) malloc(sizeof(D_Queue));
    f->first = NULL;
    f->last = NULL;
    return f;
}

void insert_ini(D_Queue *f, float v)
{
    List *l = (List *) malloc(sizeof(List));
    l->info = v;
    l->prev = NULL;
    l->next = f->first;

    if (is_list_empty(f))
    {
        f->first = l;
        f->last = l;
        return;
    }

    f->first->prev = l;
    f->first = l;
    return;
}

void insert_end(D_Queue *f, float v)
{
    List *l = (List *) malloc(sizeof(List));
    l->info = v;
    l->prev = f->last;
    l->next = NULL;

    if (is_list_empty(f))
    {
        f->first = l;
        f->last = l;
        return;
    }
    
    f->last->next = l;
    f->last = l;
    return;
}

float remove_ini(D_Queue *f);
float remove_end(D_Queue *f);
int is_list_empty(D_Queue *f);
void free_list(D_Queue *f);
