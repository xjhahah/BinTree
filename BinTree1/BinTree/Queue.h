#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

//extern struct BTNode;
typedef BTNode* DataType;

typedef struct Node
{
	struct Node* _pNext;
	DataType _data;
}Node,*PNode;

typedef struct Queue
{
	PNode _pHead;
	PNode _pTail;
}Queue;

PNode BuyNode(DataType data)
{
	PNode pNewNode = NULL;
	pNewNode = (PNode)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}
void QueueInit(Queue* q)
{
	assert(q);
	q->_pHead = q->_pTail = 0;
}
void QueuePush(Queue* q, DataType data)
{
	assert(q);
	if (NULL == q->_pHead)
	{
		q->_pHead = q->_pTail = BuyNode(data);
	}
	else
	{
		q->_pTail->_pNext = BuyNode(data);
		q->_pTail = q->_pTail->_pNext;
	}
}
DataType QueueFront(Queue* q)
{
	assert(q);
	return q->_pHead->_data;
}
void QueuePop(Queue* q)
{
	assert(q);
	PNode pDelNode = q->_pHead;
	if (NULL == pDelNode)
		return;
	q->_pHead = pDelNode->_pNext;
	free(pDelNode);
}
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_pHead)
	{
		return 1;
	}
	return 0;
}
void DestroyQueue(Queue* q)
{
	PNode pNewHaed = NULL;
	pNewHaed = q->_pHead;
	if (q->_pHead)
	{
		pNewHaed = q->_pHead->_pNext;
		free(q->_pHead);
		q->_pHead = pNewHaed;
	}
}