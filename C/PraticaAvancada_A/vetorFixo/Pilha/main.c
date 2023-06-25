#include <stdio.h>
#include "Stack.h"

int main()
{
    Stack *s = create_stack();
    for (int i = 1; i <= 52; i++) 
    {
        push_stack(s, i);
        printf("Stack push %d\n", i);
    }
    
    while (!is_stack_empty(s))
    {
        printf("pop: %f\n", pop_stack(s));
    }
    free_stack(s);
    return 0;
}
