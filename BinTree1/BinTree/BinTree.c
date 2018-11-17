#include "BinTree.h"
#include "Queue.h"
#include "Stack.h"
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
	if (*index < size && invaild != array[*index])
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
//�߶�
int BinTreeHeight(PBTNode pRoot)
{
	int m = 0, n = 0;
	if (NULL == pRoot)
		return 0;
	else
	{
		if(pRoot->_pLeft)
			m = BinTreeHeight(pRoot->_pLeft);
		if(pRoot->_pRight)
			n = BinTreeHeight(pRoot->_pRight);
	}
	return m > n ? m + 1 : n + 1;
}

//����һ���ڵ��Ƿ��ڶ�������
PBTNode BinTreeFind(PBTNode pRoot, BTDataType data)
{
	PBTNode ret;
	if (NULL == pRoot || pRoot->_data == data)
		return pRoot;
	ret = BinTreeFind(pRoot->_pLeft, data);
	if (ret)
	{
		return ret;
	}
	ret = BinTreeFind(pRoot->_pRight, data);
	if (ret)
	{
		return ret;
	}
	return NULL;
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
// �ǵݹ���� 
void BTreePrevOrderNonR(PBTNode pRoot)
{
	PBTNode pCur = pRoot;
	PBTNode pTop;
	Stack s;
	StackInit(&s);
	if (NULL == pRoot)
		return;
	while (pCur || StackEmpty(&s))
	{
		//������·�ڵ㣬��ڵ��ջ
		while (pCur)
		{
			printf("%c ", pCur->_data);
			StackPush(&s, pCur->_data);
			pCur = pCur->_pLeft;
		}
		//ջ�����Ľڵ��ʾ�����Ѿ����ʹ���
		pTop = StackTop(&s);
		StackTop(&s);
		//�������������
		pCur = pTop->_pRight;
	}
	printf("\n");
}
void BTreeInOrderNonR(PBTNode pRoot)
{
	PBTNode pCur = pRoot;
	Stack s;
	PBTNode pTop;
	StackInit(&s);
	if (NULL == pRoot)
		return;
	while (pCur || StackEmpty(&s))
	{
		while (pCur)
		{
			StackPush(&s, pCur->_data);
			pCur = pCur->_pLeft;
		}
		//������������
		pTop = StackTop(&s);
		StackPop(&s);
		printf("%c ", pTop->_data);
		pCur = pTop->_pRight;
	}
	printf("\n");
}
void BTreePostOrderNonR(PBTNode pRoot)
{
	PBTNode pCur = pRoot;
	Stack s;
	PBTNode pTop,pPre;
	StackInit(&s);
	if (NULL == pRoot)
		return;
	while (pCur || StackEmpty(&s))
	{
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}
		pTop = StackTop(&s);
		pPre = pTop;
		if (NULL == pTop->_pRight|| pTop->_pRight==pPre)
		{
			printf("%c ", pTop->_data);
			pPre = pTop;
			StackPop(&s);
		}
		else
		{
			pCur = pTop->_pRight;
		}
	}
	printf("\n");
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
//����ķǵݹ�ʵ��
void MirrorBinTreeNor(PBTNode pRoot)
{
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
//�������Ľڵ���
int BinTreeSize(PBTNode pRoot)
{
	if (NULL == pRoot)
		return 0;
	int left = BinTreeSize(pRoot->_pLeft);
	int right = BinTreeSize(pRoot->_pRight);

	return left + right + 1;
}
//������Ҷ�ӽڵ���
int BinTreeLeaf(PBTNode pRoot)
{
	if (NULL == pRoot)
		return 0;
	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;
	return BinTreeLeaf(pRoot->_pLeft) + BinTreeLeaf(pRoot->_pRight);
}
//��K��Ľڵ����
int BinTreeLevekKSize(PBTNode pRoot, int K)
{
	if (NULL == pRoot)
		return 0;
	if (K == 1)
		return 1;
	return BinTreeLevekKSize(pRoot->_pLeft, K - 1) + BinTreeLevekKSize(pRoot->_pRight, K - 1);
}
//�ж϶������Ƿ�Ϊ��ȫ������,�������
int IsCompleteBTree(PBTNode pRoot)
{
	Queue q;
	QueueInit(&q);
	if (NULL == pRoot)
		return 0;
	//������������գ������ڵ������
	QueuePush(&q,pRoot);
	while (QueueEmpty(&q)!=0)
	{
		//ȡ��ͷԪ��
		PBTNode pFront = QueueFront(&q);
		QueuePop(&q);
		//������ڵ���ڣ����Һ��������
		if (pFront)
		{
			QueuePush(&q, pFront->_pLeft);
			QueuePush(&q, pFront->_pRight);
		}
		else
		{
			break;
		}
	}
	//�ж϶������Ƿ��ߵ�Ҷ�ӽ��
	while (QueueEmpty(&q) != 0)
	{
		PBTNode pFront = QueueFront(&q);
		if (pFront)
		{
			DestroyQueue(&q);
			return -1;
		}
		else
		{
			QueuePop(&q);
		}
	}
	return 0;
}

//int IsCompleteBTree1(PBTNode pRoot) // flag�ķ�ʽ�ж� 
//{
//
//}


void TestBinTree()
{
	PBTNode pRoot=NULL; 
	PBTNode pNewBTNode = NULL;
	char* array = "ABD###CE##F";

	CreatBinTree(&pRoot, array, strlen(array),'#');
	pNewBTNode = CopyBinTree(pRoot);

	printf("ǰ�������");
	PerOrder(pRoot);
	BTreePrevOrderNonR( pRoot);
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

	printf("�������Ľڵ���Ϊ��%d\n", BinTreeSize(pRoot));
	
	printf("��������Ҷ�ӽڵ�����%d\n", BinTreeLeaf(pRoot));
	printf("�������ĸ߶�Ϊ�� %d\n", BinTreeHeight(pRoot));
	printf("IsCompleteBTree?: %d\n", IsCompleteBTree(pRoot));
	//DestroyBinTree(&q);
}