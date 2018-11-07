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
//创建二叉树 根+左子树+右子树
void _CreatBinTree(PBTNode* pRoot, BTDataType array[], int size,int* index, BTDataType invaild)
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
void CreatBinTree(PBTNode* pRoot, BTDataType array[], int size, BTDataType invaild)
{
	int len = 0;
	_CreatBinTree(pRoot, array, size, &len, invaild);
}

//拷贝二叉树   根+左子树+右子树
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
//前序遍历    根+ 左子树+ 右子树
void PerOrder(PBTNode pRoot)
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);
		PerOrder(pRoot->_pLeft);
		PerOrder(pRoot->_pRight);
	}
}
//中序遍历 左子树+ 根+ 右子树
void MidOrder(PBTNode pRoot)
{
	if (pRoot)
	{
		MidOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);		
		MidOrder(pRoot->_pRight);
	}
}
//后序遍历 左子树+ 右子树+ 根
void PostOrder(PBTNode pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}
//销毁二叉树
void DestroyBinTree(PBTNode* pRoot)
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
//层序遍历
void LevelOrder(PBTNode pRoot)
{
	//如果树为空，直接返回
	if (NULL == pRoot)
		return;
	//否则创建一个队列来存放树里的值
	Queue q;
	QueueInit(&q);

	//将根节点先入队列
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
//二叉树镜像
void Swap(PBTNode* pLeft, PBTNode* pRight)
{
	PBTNode pTemp = *pLeft;
	*pLeft = *pRight;
	*pRight = pTemp;
}
//镜像的递归实现
void MirrorBinTreeNor(PBTNode pRoot)
{
	//非递归
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
//镜像的递归实现
void MirrorBinTree(PBTNode pRoot)
{
	//递归
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

	printf("前序遍历：");
	PerOrder(pRoot);
	printf("\n");
	printf("中序遍历：");
	MidOrder(pRoot);
	printf("\n");
	printf("后序遍历：");
	PostOrder(pRoot);
	printf("\n");

	printf("层序遍历：");
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