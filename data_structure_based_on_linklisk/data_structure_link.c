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


Array* newArray()
{
	Array* new_array = (Array*)malloc(sizeof(Array));
	new_array->head = NULL;
	new_array->rear = NULL;
	new_array->index = NULL;
	new_array->node_sum = 0;
	new_array->pointer_num = 0;
	new_array->pointer_node = NULL;
	return new_array;
}
NodeA* getItem(Array* a,int index)
{
	NodeA* pointer = (a->pointer_node==NULL)? a->head:a->pointer_node;
	int i = a->pointer_num;
	if(pointer == NULL)
		return NULL;
	if(index>=(a->node_sum-1))
		return a->rear;
	if(index<=0)
		return a->head;
	if(index>=i)
	{
		while(i!=index)
		{
			i++;
			pointer = pointer->next;
		}
	}
	else
	{
		while(i!=index)
		{
			i--;
			pointer = pointer->last;
		}
	}
	a->pointer_node = pointer;
	a->pointer_num = i;
	return pointer;
}

NodeA* addItem(Array* a,NodeA* node,TYPEA new_value)
{
	NodeA* new_node = (NodeA*)malloc(sizeof(NodeA));
	new_node->data = new_value;
	new_node->next = node;
	if(node==NULL)
	{
		new_node->last = a->rear;
		if(a->rear!=NULL)
			a->rear->next = new_node;
		a->rear = new_node;
	}
	else
	{
		new_node->last = node->last;
		node->last = new_node;
	}
	if(node == a->head)
		a->head = new_node;

	a->node_sum++;
	return new_node;
}
void dropItem(Array* a,NodeA* node)
{
	node->last->next = node->next;
	node->next->last = node->last;
	free(node);
	a->node_sum--;
}

NodeA** getIndex(Array* a)
{
	NodeA** index = (NodeA**)malloc(a->node_sum*sizeof(NodeA*));
	NodeA* p = a->head;
	int i;
	for(i=0;p!=NULL;i++)
	{
		*(index+i) = p;
		p = p->next;
	}
	if(a->index!=NULL)
		free(a->index);
	a->index = index;
	return index;
}

Array* getPart(Array* a,NodeA* begin_node,int len)
{
	Array* new_array;
	NodeA* p = begin_node; 
	int i = 0;
	if(p == NULL)
		return NULL;
	else if(len<=0)
		return NULL;
	new_array = newArray();
	while(p!=NULL)
	{
		addItem(new_array,NULL,p->data);
		p = p->next;
		i++;
		if(i == len)
			break;
	}
	return new_array;
}
Array* connectArray(Array* a,Array* b)
{
	a->rear->next = b->head;
	b->head->last = a->rear;
	a->node_sum = a->node_sum+b->node_sum;
	free(b);
	return a;
}

void clearA(Array* a)
{
	NodeA* pointer = a->head;
	NodeA* current = pointer;
	while(pointer!=NULL)
	{
		pointer = current->next;
		free(current);
		current = pointer;
	}
	a->head = NULL;
	a->rear = NULL;
	if(a->index!=NULL)
	{
		free(a->index);
		a->index = NULL;
	}
	a->node_sum = 0;
	a->pointer_num = 0;
	a->pointer_node = NULL;
}
void destoryA(Array** a)
{
	clearA(*a);
	free(*a);
	*a = NULL;
}
