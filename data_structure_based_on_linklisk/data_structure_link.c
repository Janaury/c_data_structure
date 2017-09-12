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


List* newList()
{
	List* new_array = (List*)malloc(sizeof(List));
	new_array->head = NULL;
	new_array->rear = NULL;
	new_array->index = NULL;
	new_array->node_sum = 0;
	new_array->pointer_num = 0;
	new_array->pointer_node = NULL;
	return new_array;
}
NodeL* getItem(List* l,int index)
{
	NodeL* pointer = (l->pointer_node==NULL)? l->head:l->pointer_node;
	int i = l->pointer_num;
	if(pointer == NULL)
		return NULL;
	if(index>=(l->node_sum-1))
		return l->rear;
	if(index<=0)
		return l->head;
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
	l->pointer_node = pointer;
	l->pointer_num = i;
	return pointer;
}

NodeL* addItem(List* l,NodeL* node,TYPEL new_value)
{
	NodeL* new_node = (NodeL*)malloc(sizeof(NodeL));
	new_node->data = new_value;
	new_node->next = node;
	if(node==NULL)
	{
		new_node->last = l->rear;
		if(l->rear!=NULL)
			l->rear->next = new_node;
		l->rear = new_node;
	}
	else
	{
		new_node->last = node->last;
		node->last = new_node;
	}
	if(node == l->head)
		l->head = new_node;

	l->node_sum++;
	return new_node;
}
void dropItem(List* l,NodeL* node)
{
	node->last->next = node->next;
	node->next->last = node->last;
	free(node);
	l->node_sum--;
}

NodeL** getIndex(List* l)
{
	NodeL** index = (NodeL**)malloc(l->node_sum*sizeof(NodeL*));
	NodeL* p = l->head;
	int i;
	for(i=0;p!=NULL;i++)
	{
		*(index+i) = p;
		p = p->next;
	}
	if(l->index!=NULL)
		free(l->index);
	l->index = index;
	return index;
}

List* getPart(List* l,NodeL* begin_node,int len)
{
	List* new_array;
	NodeL* p = begin_node; 
	int i = 0;
	if(p == NULL)
		return NULL;
	else if(len<=0)
		return NULL;
	new_array = newList();
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
List* connectList(List* l,List* b)
{
	l->rear->next = b->head;
	b->head->last = l->rear;
	l->node_sum = l->node_sum+b->node_sum;
	free(b);
	return l;
}

void clearL(List* l)
{
	NodeL* pointer = l->head;
	NodeL* current = pointer;
	while(pointer!=NULL)
	{
		pointer = current->next;
		free(current);
		current = pointer;
	}
	l->head = NULL;
	l->rear = NULL;
	if(l->index!=NULL)
	{
		free(l->index);
		l->index = NULL;
	}
	l->node_sum = 0;
	l->pointer_num = 0;
	l->pointer_node = NULL;
}
void destoryL(List** l)
{
	clearL(*l);
	free(*l);
	*l = NULL;
}
