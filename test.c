#include <stdio.h>
#include <stdlib.h>
#include "data_structure_link.h"

/*启用测试*/
#define TEST_STACK
//#define TEST_QUEUE


int main() 
{
	#ifdef TEST_STACK
	Stack *s = newStack();
	#endif
	
	#ifdef TEST_QUEUE
	Queue *q = newQueue();
	#endif
	int i,item[100];

	for(i=0;i<100;i++)
	{
		#ifdef TEST_STACK
		push(s,i);
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
		
		#ifdef TEST_QUEUE
		dequeue(q,&item[i]);
		#endif
	}
	
	#ifdef TEST_STACK
	clearS(s);
	destoryS(&s);
	#endif
	
	#ifdef TEST_QUEUE
	clearQ(q);
	destoryQ(&q);
	#endif
	
	for(i=0;i<100;i++)
	{
		printf("%d ",item[i]);
	}
	return 0;
}


