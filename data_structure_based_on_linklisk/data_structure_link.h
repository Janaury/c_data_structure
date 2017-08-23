

/*栈结构
*newStack()返回一个栈类型指针 
*pop(s,&out_item)从s中出栈一个元素 
*push(s，new_item)将一个新元素入栈
*clear(s)将栈元素清空
*destory(s)销毁一个栈  
*/
#define TYPES int

typedef struct stack{
	struct node_s *end;
}Stack;
typedef struct node_s{
	TYPES data;
	struct node_s *last;
}NodeS;

Stack* newStack();
int push(Stack* s,TYPES new_item);
int pop(Stack* s,TYPES* out_item);
void clearS(Stack* s);
void destoryS(Stack** s); 
/*栈结构*/


/*队列结构
 *newQueue(q)新建一个队列 
 *enqueue(q,new_item)入队一个元素 
 *dequeue(q,&out_item)出队一个元素 
 *clearQ(q）清空一个队列 
 *destoryQ(&q)销毁一个队列 
 */
#define TYPEQ int

typedef struct queue{
	struct node_q *head;
	struct node_q *rear; 
}Queue;
typedef struct node_q{
	TYPEQ data;
	struct node_q *next;
}NodeQ;

Queue* newQueue();
int enqueue(Queue* q,TYPEQ new_item);
int dequeue(Queue* q,TYPEQ* out_item);
void clearQ(Queue* q);
void destoryQ(Queue** q);
/*队列结构*/ 
