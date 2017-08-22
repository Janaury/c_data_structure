
#define TYPE int
#define STACK_MAX 50

/*栈结构
*newStack()返回一个栈类型指针 
*pop(s,&out_item)从s中出栈一个元素 
*push(s，new_item)将一个新元素入栈
*clear(s)将栈元素清空
*destory(s)销毁一个栈  
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
 
