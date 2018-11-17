#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

//
//typedef int STDataType;
//
//#define N 10
//typedef struct Stack
//{
//	STDataType _a[N];
//	int _top; // Õ»¶¥
//}Stack;

typedef struct Pos
{
	int _row;
	int _col;
}Pos;

typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top;		// Õ»¶¥
	int _capacity;  // ÈÝÁ¿ 
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);

//void TestStack();

