#include <stdio.h>
#include "Queue.h"

int main()
{
    Queue *q = create_Q();

    int i = 0;
    while(i < 101)
    {
        insert_Q(q, ++i);
    }
    while (!is_queue_empty(q))
    {
        printf("%f\n", remove_Q(q));
    }

    return 0;
}
