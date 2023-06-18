#include <stdlib.h>
#include <stdio.h>
#include "FilaDupla.h"

typedef struct List List;
struct List
{
    float info;
    List *next;
    List *prev;
};

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

float remove_ini(D_Queue *f)
{
    float value;
    List *fst = f->first;

    if (fst == NULL) {printf("Lista nao possui membros para remover\n"); exit(1);}

    if (fst->next == NULL)
    {
        value = fst->info;
        free(fst);
        f->first = NULL;
        f->last = NULL;
        return value;
    }

    fst->next->prev = NULL;

    f->first = fst->next;

    value = fst->info;
    free(fst);
    return value;

}

float remove_end(D_Queue *f)
{
    float value;
    List *lst = f->last;

    if (lst == NULL) {printf("Lista nao possui membros para remover\n"); exit(1);}

    if (lst->prev == NULL)
    {
        value = lst->info;
        free(lst);
        f->first = NULL;
        f->last = NULL;
        return value;
    }

    lst->prev->next = NULL;

    f->last = lst->prev;
    value = lst->info;
    free(lst);
    return value;
}

int is_list_empty(D_Queue *f)
{
    return f->first == NULL;
}

void free_list(D_Queue *f)
{
    List *current = f->first;
    List *nxt;
    while (current != NULL) 
    {
        nxt = current->next;
        free(current);
        current = nxt;
    }
    free(f);
    return;
}

void printList(D_Queue *f)
{
    List *current = f->first;
    List *nxt;
    List *lst;
    float crrt, nxtt, lstt;
    while (current != NULL) 
    {
        crrt = current->info;
        nxt = current->next;
        lst = current->prev;

        if (nxt == NULL)
        {
            nxtt = 0;
        }
        else
        {
            nxtt = nxt->info; 
        }

        if (lst == NULL)
        {
            lstt = 0;
        }
        else
        {
            lstt = lst->info; 
        }
        crrt = current->info;
        printf("prev:%f current:%f next:%f\n", lstt, crrt, nxtt);

        current = nxt;
    }
    printf("End of List\n\n");
    return;
}
