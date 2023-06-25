#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"
#define limit 50

struct Stack
{
	int fst_free_index;
	float arr[limit];
};

Stack *create_stack(void)
{
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->fst_free_index = 0;
	return s;
}

void push_stack(Stack *s, float v)
{
	if (s->fst_free_index == limit)
	{
		printf("Stack overflow\n");
		return;
	} 
	s->arr[s->fst_free_index] = v;
	s->fst_free_index = s->fst_free_index + 1;
	return;
}

float pop_stack(Stack *s)
{
	if (is_stack_empty(s)) 
	{
		printf("Stack empty\n"); 
		return 0;
	}
	float v = s->arr[s->fst_free_index-1];
	s->fst_free_index--;
	return v;
}

int is_stack_empty(Stack *s)
{
	return s->fst_free_index == 0;
}

void free_stack(Stack *s)
{
	free(s);
}
