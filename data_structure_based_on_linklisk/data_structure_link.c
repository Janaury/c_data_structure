#include "data_structure_link.h"
#include <stdlib.h>


Stack* newStack()
{
	Stack* new_stack = (Stack*)malloc(sizeof(Stack));
	new_stack->end = NULL;
	return new_stack;
}
int pop(Stack*s,TYPES* out_item)
{
	NodeS* out_node = s->end;
	if(out_node == NULL)
		return -1;
	s->end = out_node->last;
	*out_item = out_node->data;
	free(out_node);
	return 1;
}
int push(Stack* s,TYPES new_item)
{
	NodeS* new_node = (NodeS*)malloc(sizeof(NodeS));
	new_node-> data = new_item;
	new_node->last = s->end;
	s->end = new_node;
	return 0;
}
void destoryS(Stack** s)
{
	clearS(*s);
	free(*s);
	*s = NULL;
}
void clearS(Stack* s)
{
	NodeS* pointer = s->end;
	NodeS* current = pointer;
	while(pointer!=NULL)
	{
		pointer = current->last;
		free(current);
		current = pointer;
	}
	s->end = NULL;
}

Queue* newQueue()
{
	Queue* new_queue = (Queue*)malloc(sizeof(Queue));
	new_queue->head = NULL;
	new_queue->rear = NULL;
	return new_queue;
}
int enqueue(Queue* q,TYPEQ new_item)
{
	NodeQ* new_node = (NodeQ*)malloc(sizeof(NodeQ));
	new_node->data = new_item;
	new_node->next = NULL;
	if(q->head==NULL)
		q->head = new_node;
	else
		q->rear->next = new_node;
	q->rear = new_node;
	return 0;
	
}
int dequeue(Queue* q,TYPEQ* out_item)
{
	NodeQ* out_node = q->head;
	if(out_node == NULL)
		return -1;
	q->head = out_node->next;
	*out_item = out_node->data;
	free(out_node); 
	return 1;
}
void clearQ(Queue* q)
{
	NodeQ* pointer = q->head;
	NodeQ* current = pointer;
	while(pointer!=NULL)
	{
		pointer = current->next;
		free(current);
		current = pointer;
	}
	q->head = NULL;
	q->rear = NULL;
}
void destoryQ(Queue** q)
{
	clearQ(*q);
	free(*q);
	*q = NULL;
}
