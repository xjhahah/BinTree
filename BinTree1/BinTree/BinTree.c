#include "BinTree.h"

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

PNode BuyBinTreeNode(DataType data)
{
	PNode pNewNode = NULL;
	pNewNode = (PNode)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	return pNewNode;
}
//创建二叉树 根+左子树+右子树
void _CreatBinTree(PNode* pRoot, DataType array[], int size,int* index,DataType invaild)
{
	assert(pRoot);
	if (*index < size&&invaild != array[*index])
	{
		*pRoot = BuyBinTreeNode(array[*index]);

		//创建根的左子树
		++(*index);
		_CreatBinTree(&(*pRoot)->_pLeft, array, size, index, invaild);

		//创建根的右子树
		++(*index);
		_CreatBinTree(&(*pRoot)->_pRight, array, size, index, invaild);
	}	
}
//外部人员来调用这个函数的时候是不需要知道索引的
void CreatBinTree(PNode* pRoot, DataType array[], int size, DataType invaild)
{
	int len = 0;
	_CreatBinTree(pRoot, array, size, &len, invaild);
}

//拷贝二叉树   根+左子树+右子树
PNode CopyBinTree(PNode pRoot)
{
	PNode pNewRoot = NULL;
	if (pRoot)
	{
		pNewRoot = BuyBinTreeNode(pRoot->_data);
		if(pRoot->_pLeft)
			pNewRoot->_pLeft = CopyBinTree(pRoot->_pLeft);
		if(pRoot->_pRight)
			pNewRoot->_pRight = CopyBinTree(pRoot->_pRight);
	}	
	return pNewRoot;
}
//前序遍历    根+ 左子树+ 右子树
void PerOrder(PNode pRoot)
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);
		PerOrder(pRoot->_pLeft);
		PerOrder(pRoot->_pRight);
	}
}
//中序遍历 左子树+ 根+ 右子树
void MidOrder(PNode pRoot)
{
	if (pRoot)
	{
		MidOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);		
		MidOrder(pRoot->_pRight);
	}
}
//后序遍历 左子树+ 右子树+ 根
void PostOrder(PNode pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}
//销毁二叉树
void DestroyBinTree(PNode* pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		//先销毁左子树
		DestroyBinTree(&(*pRoot)->_pLeft);
		//再销毁右子树
		DestroyBinTree(&(*pRoot)->_pRight);

		free(*pRoot);
		*pRoot=NULL;
	}
}
void TestBinTree()
{
	PNode pRoot=NULL; 
	PNode pNewNode = NULL;
	char* array = "ABD###CE##F";

	CreatBinTree(&pRoot, array, strlen(array),'#');
	pNewNode = CopyBinTree(pRoot);

	printf("前序遍历：");
	PerOrder(pRoot);
	printf("\n");
	printf("中序遍历：");
	MidOrder(pRoot);
	printf("\n");
	printf("后序遍历：");
	PostOrder(pRoot);
	//PerOrder(pNewNode);
}