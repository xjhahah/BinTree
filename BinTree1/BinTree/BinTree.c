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
//���������� ��+������+������
void _CreatBinTree(PNode* pRoot, DataType array[], int size,int* index,DataType invaild)
{
	assert(pRoot);
	if (*index < size&&invaild != array[*index])
	{
		*pRoot = BuyBinTreeNode(array[*index]);

		//��������������
		++(*index);
		_CreatBinTree(&(*pRoot)->_pLeft, array, size, index, invaild);

		//��������������
		++(*index);
		_CreatBinTree(&(*pRoot)->_pRight, array, size, index, invaild);
	}	
}
//�ⲿ��Ա���������������ʱ���ǲ���Ҫ֪��������
void CreatBinTree(PNode* pRoot, DataType array[], int size, DataType invaild)
{
	int len = 0;
	_CreatBinTree(pRoot, array, size, &len, invaild);
}

//����������   ��+������+������
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
//ǰ�����    ��+ ������+ ������
void PerOrder(PNode pRoot)
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);
		PerOrder(pRoot->_pLeft);
		PerOrder(pRoot->_pRight);
	}
}
//������� ������+ ��+ ������
void MidOrder(PNode pRoot)
{
	if (pRoot)
	{
		MidOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);		
		MidOrder(pRoot->_pRight);
	}
}
//������� ������+ ������+ ��
void PostOrder(PNode pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}
//���ٶ�����
void DestroyBinTree(PNode* pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		//������������
		DestroyBinTree(&(*pRoot)->_pLeft);
		//������������
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

	printf("ǰ�������");
	PerOrder(pRoot);
	printf("\n");
	printf("���������");
	MidOrder(pRoot);
	printf("\n");
	printf("���������");
	PostOrder(pRoot);
	//PerOrder(pNewNode);
}