
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

/*通用线性表--List 
*我真是愚不可及，为啥当初要拿array来命令这个结构，现在又得改一堆东西 
*节点的数据类型可以自定义，所以建议每一个节点储存一个数组从而减少节点数，提高效率 
*newArray()创建一个List 
*getItem(a,index)返回索引序号为index的节点（第index+1）个节点 
*addItem(a,node,new_value)在node节点前插入一个新节点，node为NULL则表示在List a的末尾插入一个元素
*getIndex(a)遍历所有节点，建立一个各节点地址的索引数组，用于快速使用序号访问 某个节点(注意：在执行插入，删除操作时，索引不会自动更新，
			再次调用该函数可以更新索引)
*dropItem(a,node)删除node节点
*getPart(a,begin_node,length)以begin_node 为起点，从List a中截取长度为lenght各节点构成新的List并返回，此操作不影响原List 
*connectArray(a,b)把List b接在List a的后面， 并返回List a（原a，b List不存在了，List a为连接后的新List） 
*clearA(a)清空List a（留下头节点，相当于新建的空List） 
*destoryA(a)销毁List a(删除整个list，头结点置为NULL)
*/
//定义基本数据类型 
#define TYPEL int

typedef struct list{
	int node_sum;
	struct node_l* head;
	struct node_l* rear;
	struct node_l** index; 
	struct node_l* pointer_node;
	int pointer_num;
}List; 
typedef struct node_l{
	TYPEL data;
	struct node_l* next;
	struct node_l* last;
}NodeL;

List* newList();
NodeL* getItem(List* a,int index);
NodeL* addItem(List* a,NodeL* node,TYPEL new_value);
void dropItem(List* a,NodeL* node);
NodeL** getIndex(List* a);
List* getPart(List* a,NodeL* begin_node,int len);
List* connectList(List* a,List* b);
void clearL(List* a);
void destoryL(List** a);

