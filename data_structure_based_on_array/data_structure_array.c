#include "data_structure_array.h"
#include <stdlib.h>

Stack* newStack()
{
	Stack* new_stack = (Stack*)malloc(sizeof(Stack));
	new_stack->p = -1;
	return new_stack;
}

int push(Stack* s,TYPES new_item)
{
	if(STACK_MAX == s->p)
		return -1;
	else
	{
		s->data[++s->p] = new_item;
		return 1;
	}
	
}

int pop(Stack* s,TYPES* out_item)
{
	if(s->p == -1)
		return -1;
	else
	{
		*out_item = s->data[s->p--];
		return 1;
	}
}
void clearS(Stack* s)
{
	s->p = -1;
}
void destoryS(Stack** s)
{
	free(*s);
	*s = NULL;
}

Queue* newQueue()
{
	Queue* new_queue = (Queue*)malloc(sizeof(Queue));
	new_queue->empty = 1;
	new_queue->full  = 0;
	new_queue->head = 0;
	new_queue->rear = 0;
}
int enqueue(Queue* q,TYPEQ new_item)
{
	if(q->full)
		return -1;
	else
	{
		q->data[q->rear] = new_item;
		q->rear = (++q->rear)%QUEUE_MAX;
		if(q->rear == q->head)
			q->full = 1;
		q->empty = 0;
		return 1;
	}
	
}

int dequeue(Queue* q,TYPEQ* out_item)
{
	if(q->empty)
		return -1;
	else
	{
		*out_item = q->data[q->head];
		q->head = (++q->head)%QUEUE_MAX;
		if(q->head == q->rear)
			q->empty = 1;
		q->full = 0;
		return 1; 
	}
}
void clearQ(Queue* q)
{
	q->empty = 1;
	q->full  = 0;
	q->head = 0;
	q->rear = 0;
}
void destoryQ(Queue** q)
{
	free(*q);
	*q = NULL;
}
