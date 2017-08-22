#include <stdio.h>
#include <stdlib.h>
#include "data_structure_link.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main() 
{
	Stack *s = newStack();
	int item1,item2;
	/*
	s->p =2;
	s->data[0] = 1;
	s->data[1] = 2;
	s->data[2] = 3;
	*/
	push(s,5);
	push(s,8);
	pop(s,&item1);
	pop(s,&item2);
	printf("%d,%d",item1,item2);
	return 0;
}
