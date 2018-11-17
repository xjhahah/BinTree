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
//创建二叉树 根+左子树+右子树
void _CreatBinTree(PBTNode* pRoot, BTDataType array[], int size,int* index, BTDataType invaild)
{
	assert(pRoot);
	if (*index < size && invaild != array[*index])
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
//高度
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

//查找一个节点是否在二叉树中
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
// 非递归遍历 
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
		//访问左路节点，左节点进栈
		while (pCur)
		{
			printf("%c ", pCur->_data);
			StackPush(&s, pCur->_data);
			pCur = pCur->_pLeft;
		}
		//栈出来的节点表示左树已经访问过了
		pTop = StackTop(&s);
		StackTop(&s);
		//子问题访问右树
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
		//左树遍历结束
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
//镜像的非递归实现
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
//二叉树的节点数
int BinTreeSize(PBTNode pRoot)
{
	if (NULL == pRoot)
		return 0;
	int left = BinTreeSize(pRoot->_pLeft);
	int right = BinTreeSize(pRoot->_pRight);

	return left + right + 1;
}
//二叉树叶子节点数
int BinTreeLeaf(PBTNode pRoot)
{
	if (NULL == pRoot)
		return 0;
	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;
	return BinTreeLeaf(pRoot->_pLeft) + BinTreeLeaf(pRoot->_pRight);
}
//求K层的节点个数
int BinTreeLevekKSize(PBTNode pRoot, int K)
{
	if (NULL == pRoot)
		return 0;
	if (K == 1)
		return 1;
	return BinTreeLevekKSize(pRoot->_pLeft, K - 1) + BinTreeLevekKSize(pRoot->_pRight, K - 1);
}
//判断二叉树是否为完全二叉树,层序遍历
int IsCompleteBTree(PBTNode pRoot)
{
	Queue q;
	QueueInit(&q);
	if (NULL == pRoot)
		return 0;
	//如果二叉树不空，将根节点入队列
	QueuePush(&q,pRoot);
	while (QueueEmpty(&q)!=0)
	{
		//取队头元素
		PBTNode pFront = QueueFront(&q);
		QueuePop(&q);
		//如果根节点存在，左右孩子入队列
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
	//判断二叉树是否走到叶子结点
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

//int IsCompleteBTree1(PBTNode pRoot) // flag的方式判断 
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

	printf("前序遍历：");
	PerOrder(pRoot);
	BTreePrevOrderNonR( pRoot);
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

	printf("二叉树的节点数为：%d\n", BinTreeSize(pRoot));
	
	printf("二叉树的叶子节点数：%d\n", BinTreeLeaf(pRoot));
	printf("二叉树的高度为： %d\n", BinTreeHeight(pRoot));
	printf("IsCompleteBTree?: %d\n", IsCompleteBTree(pRoot));
	//DestroyBinTree(&q);
}