#include "Stack.h"

#include <assert.h>

void StackInit(Stack* s)
{
	assert(s);
	s->_a = (STDataType*)malloc(sizeof(STDataType) * 3);
	s->_top = 0;
	s->_capacity = 3;
}
void StackPush(Stack* s, STDataType data)
{
	assert(s);
	if (s->_top == s->_capacity)
	{
		s->_a = (STDataType*)realloc(s->_a, sizeof(STDataType)*s->_capacity * 2);
		assert(s->_a);
		s->_capacity *= 2;
	}
	s->_a[s->_top++] = data;
}
void StackPop(Stack* s)
{
	assert(s->_a);
	assert(s->_top > 0);
	s->_top--;
}

int StackTop(Stack* s)
{
	assert(!StackEmpty(s));
	return s->_a[s->_top];
}
int StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}
int StackEmpty(Stack* s)
{
	assert(s);
	return 0 == s->_top;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_a)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_capacity = 0;
		ps->_top = 0;
	}
}

//void TestStack()
//{
//	Stack s;
//	StackInit(&s);
//	StackPush(&s, 1);
//	StackPush(&s, 2);
//	StackPush(&s, 3);
//	StackPush(&s, 4);
//	StackPush(&s, 5);
//
//	printf("%d\n", s._top);
//	printf("%d\n", StackSize(&s));
//
//	StackPop(&s);
//	printf("%d\n", s._top);
//	printf("%d\n", StackSize(&s));
//}