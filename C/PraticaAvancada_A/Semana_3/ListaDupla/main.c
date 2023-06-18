#include <stdio.h>
#include "FilaDupla.h"

int main()
{
    D_Queue *q = create_queue();
    insert_ini(q, 2);
    printList(q);
    insert_ini(q, 1);
    printList(q);
    insert_end(q, 3);
    printList(q);
    insert_end(q, 4);
    printList(q);

    remove_ini(q);
    printList(q);
    remove_end(q);
    printList(q);

    insert_ini(q, 1);
    printList(q);
    insert_end(q, 4);
    printList(q);

    free_list(q);

    return 0;
}
