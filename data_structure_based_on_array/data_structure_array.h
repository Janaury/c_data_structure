
#define TYPE int
#define STACK_MAX 50

/*ջ�ṹ
*newStack()����һ��ջ����ָ�� 
*pop(s,&out_item)��s�г�ջһ��Ԫ�� 
*push(s��new_item)��һ����Ԫ����ջ
*clear(s)��ջԪ�����
*destory(s)����һ��ջ  
*/

typedef struct stack{
	int p;
	TYPE data[STACK_MAX];
}Stack;

Stack* newStack();
int push(Stack* s,TYPE new_item);
int pop(Stack* s,TYPE* out_item);
void clear(Stack* s); 
void destory(Stack** s); 
 
