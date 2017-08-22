
#define TYPE int

typedef struct stack{
	struct item *end;
}Stack;
typedef struct item{
	TYPE data;
	struct item *next;
	struct item *last;
}Item;
Stack* newStack();
int push(Stack* s,TYPE new_item);
int pop(Stack* s,TYPE* out_item);
void clear(Stack* s);
void destory(Stack** s); 
