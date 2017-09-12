#include <stdio.h>
#include <stdlib.h>
#include "data_structure_link.h"

/*启用测试*/
//#define TEST_STACK
//#define TEST_QUEUE
#define TEST_ARRAY

int item[100];
int main() 
{
	#ifdef TEST_STACK
	Stack *s = newStack();
	#endif
	
	#ifdef TEST_ARRAY
	List* l = newList();
	List* b;
	NodeL* p;
	NodeL** index;
	#endif
	
	#ifdef TEST_QUEUE
	Queue *q = newQueue();
	#endif
	int i;

	for(i=0;i<100;i++)
	{
		#ifdef TEST_STACK
		push(s,i);
		#endif
		
		#ifdef TEST_ARRAY
		addItem(l,NULL,i);
		#endif
		
		#ifdef TEST_QUEUE
		enqueue(q,i);
		#endif
	}
	for(i=0;i<100;i++)
	{
		#ifdef TEST_STACK
		pop(s,&item[i]);
		#endif
		
		#ifdef TEST_ARRAY
		p = getItem(l,i);
		item[i] = p->data;
		#endif
		
		#ifdef TEST_QUEUE
		dequeue(q,&item[i]);
		#endif
	}
	
	#ifdef TEST_ARRAY
	puts("索引测试"); 
	index = getIndex(l);
	for(i=0;i<100;i++)
	{
		printf("%p\n",index[i]);
	}
	puts("利用原表生成指定长度新表测试");
	b = getPart(l,getItem(l,15),50);
	for(i=0;i<50;i++)
	{
		printf("%d ",getItem(b,i)->data);
	}
	printf("\n");
	puts("两表连接测试");
	connectList(l,b);
	for(i=0;i<150;i++)
	{
		printf("%d ",getItem(l,i)->data);
	}
	clearL(l);
	destoryL(&l);
	#endif
	
	#ifdef TEST_STACK
	clearS(s);
	destoryS(&s);
	#endif
	
	#ifdef TEST_QUEUE
	clearQ(q);
	destoryQ(&q);
	#endif
	
	puts("读取结果");
	for(i=0;i<100;i++)
	{
		printf("%d ",item[i]);
	}
	
	return 0;
}


