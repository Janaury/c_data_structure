
#define ERROR -1
#define OK	   1

/*栈结构
*newStack()返回一个栈类型指针 
*pop(s,&out_item)从s中出栈一个元素 
*push(s，new_item)将一个新元素入栈
*clear(s)将栈元素清空
*destory(s)销毁一个栈  
*/
//定义基本数据类型 
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
 //定义基本数据类型 
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

/*通用线性表--更灵活的数组 
*虽然我已array来命名，但这其实是一个双链表，至于为什么取名叫数组，可能是用惯了php和python那种很灵活的数组的缘故吧，
*大家也可以自己改一下名字，使用搜索替换就好了 （以下出现的“数组”均只我的这个数据结构） 
*节点的数据类型可以自定义，所以建议每一个节点储存一个数组从而减少节点数，提高效率 
*newArray()创建一个数组 
*getItem(a,index)返回索引序号为index的节点（第index+1）个节点 
*addItem(a,node,new_value)在node节点前插入一个新节点，node为NULL则表示在数组a的末尾插入一个元素
*getIndex(a)遍历所有节点，建立一个各节点地址的索引数组，用于快速使用序号访问 某个节点(注意：在执行插入，删除操作时，索引不会自动更新，
			再次调用该函数可以更新索引)
*dropItem(a,node)删除node节点
*getPart(a,begin_node,length)以begin_node 为起点，从数组a中截取长度为lenght各节点构成新的数组并返回，此操作不影原数组
*connectArray(a,b)把数组b接在数组a的后面， 并返回数组a（原a，b数组不存在了，数组a为连接后的新数组） 
*clearA(a)清空数组a（留下头节点，相当于新建的空数组） 
*destoryA(a)销毁数组a 
*/
//定义基本数据类型 
#define TYPEA int

typedef struct array{
	int node_sum;
	struct node_a* head;
	struct node_a* rear;
	struct node_a** index; 
	struct node_a* pointer_node;
	int pointer_num;
}Array; 
typedef struct node_a{
	TYPEA data;
	struct node_a* next;
	struct node_a* last;
}NodeA;

Array* newArray();
NodeA* getItem(Array* a,int index);
NodeA* addItem(Array* a,NodeA* node,TYPEA new_value);
void dropItem(Array* a,NodeA* node);
NodeA** getIndex(Array* a);
Array* getPart(Array* a,NodeA* begin_node,int len);
Array* connectArray(Array* a,Array* b);
void clearA(Array* a);
void destoryA(Array** a);

