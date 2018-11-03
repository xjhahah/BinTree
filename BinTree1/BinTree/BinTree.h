#pragma once

typedef char DataType;

//孩子表示法
typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft;
	struct BinTreeNode* _pRight;
	DataType _data;
}Node,*PNode;

//创建二叉树
void CreatBinTree(PNode* pRoot, DataType array[], int size, DataType invaild);
//拷贝二叉树
PNode CopyBinTree(PNode pRoot);

//前序 中序 后序遍历
void PerOrder(PNode pRoot);
void MidOrder(PNode pRoot);
void PostOrder(PNode pRoot);
void DestroyBinTree(PNode* pRoot);
void TestBinTree();