#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

char next_char(int c)
{
    c = c + 1;
    if (c > 65 && c < 91) return c;
    if (c > 96 && c < 123) return c;

    if (c > 91) return 'A';
    return 'a';
}

int main()
{
    Hash table;
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL; // Initialize the table with NULL pointers
    }

    int c = 64;
    for (int i = 0; i < (int)(N * 0.75); i++)
    {
        char nc = next_char(c);
        upsert(table,create_info_random_id(nc));
        c = (int) nc;
    }

    print_hash_table(table);
    free_hash_table(table);

    return 0;
}
