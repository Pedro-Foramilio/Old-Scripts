#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

Info* create_info_random_id(char c)
{
    Info *info = malloc(sizeof(Info));
    info->info = c;
    info->unique_id = rand();
    return info;
}

Info* create_info(char c, long int id)
{
    Info *info = malloc(sizeof(Info));
    info->info = c;
    info->unique_id = id;
    return info;
}

int hash(long int x)
{
    return x % N;
}

void upsert(Hash table, Info *info)
{
    int hash_key = hash(info->unique_id);
    Info *target_element = table[hash_key];

    if (target_element == NULL) //element not in table
    {
        table[hash_key] = info;
        return;
    }
    
    //key colision detected

    Info *last = NULL;
    while (target_element != NULL)
    {
        if (target_element->unique_id == info->unique_id)
            break;
        last = target_element;
        target_element = target_element->next;
    }

    if (target_element != NULL) //element found
    {
        target_element->info = info->info;
        return;
    }

    //target element not found
    last->next = info;
    return;
}

Info* search(Hash table, long int unique_id)
{
    int hash_key = hash(unique_id);
    Info *target_element = table[hash_key];

    if (target_element->unique_id == unique_id) return target_element;

    while (target_element != NULL)
    {
        if (target_element->unique_id == unique_id)
            break;
        target_element = target_element->next;
    }

    return target_element;
}

void remove_info(Hash table, long int unique_id)
{
    int hash_key = hash(unique_id);
    Info *target_element = table[hash_key];
    Info *last = NULL;

    // no collision
    if (target_element->unique_id == unique_id)
    {
        table[hash_key] = target_element->next;
        free(target_element);
        return;
    }

    while (target_element != NULL)
    {
        if (target_element->unique_id == unique_id)
            break;
        last = target_element;
        target_element = target_element->next;
    }

    // collision element detected
    if (target_element != NULL)
    {
        last->next = target_element->next;
        free(target_element);
        return;
    }

    //since targe == NULL, no match was found
    return;
}

void print_info(Info *info)
{
    if (info == NULL) printf(" / ");
    printf("ID: %ld | info: %c -> ", info->unique_id, info->info);
}

void print_hash_table(Hash table)
{
    for (int i = 0; i < N; i++)
    {
        printf("[%d] :: ", i);
        Info *element = table[i];
        while (element != NULL)
        {
            print_info(element);
            element = element->next;
        }
        printf("/\n");
    }
}

void free_hash_table(Hash table)
{
    for (int i = 0; i < N; i++)
    {
        Info *element = table[i];
        Info *last;
        while (element != NULL)
        {
            last = element;
            element = element->next;
            free(last);
        }
        
    }
}
