#include "data_structure_link.h"
#include "stdlib.h"


Stack* newStack()
{
	Stack* node = (Stack*)malloc(sizeof(Stack));
	node->end = NULL;
	return node;
}
int pop(Stack*s,TYPE* out_item)
{
	Item* out_node = s->end;
	if(s->end == NULL)
		return -1;
	s->end = out_node->last;
	if(s->end!=NULL)
		s->end->next = NULL;
	*out_item = out_node->data;
	free(out_node);
	return 1;
}
int push(Stack* s,TYPE new_item)
{
	Item* new_node = (Item*)malloc(sizeof(Item));
	new_node-> data = new_item;
	new_node->last = s->end;
	new_node->next = NULL;
	if(s->end!=NULL)
		s->end->next = new_node;
	s->end = new_node;
	return 0;
}
void destory(Stack** s)
{
	clear(*s);
	free(*s);
	*s = NULL;
}
void clear(Stack* s)
{
	Item* pointer = s->end;
	Item* current = pointer;
	while(pointer!=NULL)
	{
		pointer = current->last;
		free(current);
		current = pointer;
	}
	s->end = NULL;
}

