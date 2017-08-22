#include "data_structure_array.h"
#include "stdlib.h"

Stack* newStack()
{
	return (Stack*)malloc(sizeof(Stack));
}

int push(Stack* s,TYPE new_item)
{
	if(STACK_MAX == s->p)
		return -1;
	else
	{
		s->data[++s->p] = new_item;
		return 1;
	}
	
}

int pop(Stack* s,TYPE* out_item)
{
	if(s->p == -1)
		return -1;
	else
	{
		*out_item = s->data[s->p--];
		return 1;
	}
}
void clear(Stack* s)
{
	s->p = -1;
}
void destory(Stack** s)
{
	free(*s);
	*s = NULL;
}
