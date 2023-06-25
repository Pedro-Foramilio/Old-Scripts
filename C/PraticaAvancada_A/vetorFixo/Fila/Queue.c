#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#define LIMIT 100

struct Queue
{
    int size;
    int start;
    float arr[LIMIT];
};

Queue* create_Q(void)
{
    Queue *q = malloc(sizeof(Queue));
    q->size = 0;
    q->start = 0;
    return q;
}

void insert_Q(Queue *q, float v)
{
    if (q->size == LIMIT)
    {
        printf("Queue overflow\n");
        return;
    }

    int insert_position = (q->start + q->size) % LIMIT;
    q->arr[insert_position] = v;
    q->size++;
    return;
}

float remove_Q(Queue *q)
{
    if (is_queue_empty(q))
    {
        printf("Queue empty\n");
        return 0;
    }

    float v = q->arr[q->start];
    q->start = (q->start + 1)% LIMIT;
    q->size--;
    return v;
}

int is_queue_empty(Queue *q)
{
    return q->size == 0;
}

void free_Q(Queue *q)
{
    free(q);
}
