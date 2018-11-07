#include "BinTree.h"
#include "Queue.h"

PBTNode BuyBinTreeNode(BTDataType data)
{
	PBTNode pNewBTNode = NULL;
	pNewBTNode = (PBTNode)malloc(sizeof(BTNode));
	if (NULL == pNewBTNode)
	{
		assert(0);
		return NULL;
	}
	pNewBTNode->_data = data;
	pNewBTNode->_pLeft = NULL;
	pNewBTNode->_pRight = NULL;
	return pNewBTNode;
}
//���������� ��+������+������
void _CreatBinTree(PBTNode* pRoot, BTDataType array[], int size,int* index, BTDataType invaild)
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
void CreatBinTree(PBTNode* pRoot, BTDataType array[], int size, BTDataType invaild)
{
	int len = 0;
	_CreatBinTree(pRoot, array, size, &len, invaild);
}

//����������   ��+������+������
PBTNode CopyBinTree(PBTNode pRoot)
{
	PBTNode pNewRoot = NULL;
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
void PerOrder(PBTNode pRoot)
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);
		PerOrder(pRoot->_pLeft);
		PerOrder(pRoot->_pRight);
	}
}
//������� ������+ ��+ ������
void MidOrder(PBTNode pRoot)
{
	if (pRoot)
	{
		MidOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);		
		MidOrder(pRoot->_pRight);
	}
}
//������� ������+ ������+ ��
void PostOrder(PBTNode pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}
//���ٶ�����
void DestroyBinTree(PBTNode* pRoot)
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
//�������
void LevelOrder(PBTNode pRoot)
{
	//�����Ϊ�գ�ֱ�ӷ���
	if (NULL == pRoot)
		return;
	//���򴴽�һ����������������ֵ
	Queue q;
	QueueInit(&q);

	//�����ڵ��������
	QueuePush(&q,pRoot);
	while (QueueEmpty(&q))
	{
		PBTNode pCur = NULL;
		pCur = QueueFront(&q);
		printf(" %c", pCur->_data);
		if (pCur->_pLeft)
		{
			QueuePush(&q, pCur->_pLeft);
		}
		if (pCur->_pRight)
		{
			QueuePush(&q, pCur->_pRight);
		}
		QueuePop(&q);
	}
}
//����������
void Swap(PBTNode* pLeft, PBTNode* pRight)
{
	PBTNode pTemp = *pLeft;
	*pLeft = *pRight;
	*pRight = pTemp;
}
//����ĵݹ�ʵ��
void MirrorBinTreeNor(PBTNode pRoot)
{
	//�ǵݹ�
	if (NULL == pRoot)
		return;
	Queue q;
	QueueInit(&q);

	QueuePush(&q, pRoot);
	while (QueueEmpty(&q))
	{
		PBTNode pCur = QueueFront(&q);
		Swap(&(pCur->_pLeft), &(pCur->_pRight));
		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);
		if (pCur->_pRight)
			QueuePush(&q, pCur->_pRight);
		QueuePop(&q);
	}
}
//����ĵݹ�ʵ��
void MirrorBinTree(PBTNode pRoot)
{
	//�ݹ�
	if (NULL == pRoot)
		return;
	if ((NULL == pRoot->_pLeft && NULL == pRoot->_pRight))
		return;
	PBTNode pCur = pRoot->_pLeft;
	pRoot->_pLeft = pRoot->_pRight;
	pRoot->_pRight = pCur;
	if (pRoot->_pLeft)
		MirrorBinTree(pRoot->_pLeft);
	if (pRoot->_pRight)
		MirrorBinTree(pRoot->_pRight);
}
void TestBinTree()
{
	PBTNode pRoot=NULL; 
	PBTNode pNewBTNode = NULL;
	char* array = "ABD###CE##F";

	CreatBinTree(&pRoot, array, strlen(array),'#');
	pNewBTNode = CopyBinTree(pRoot);

	printf("ǰ�������");
	PerOrder(pRoot);
	printf("\n");
	printf("���������");
	MidOrder(pRoot);
	printf("\n");
	printf("���������");
	PostOrder(pRoot);
	printf("\n");

	printf("���������");
	LevelOrder(pRoot);
	//PerOrder(pNewBTNode);
	printf("\n");
	MirrorBinTree(pRoot);
	LevelOrder(pRoot);
	printf("\n");

	MirrorBinTreeNor(pRoot);
	LevelOrder(pRoot);
	printf("\n");
}