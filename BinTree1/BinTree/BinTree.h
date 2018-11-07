#pragma once

typedef char BTDataType;

//孩子表示法
typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft;
	struct BinTreeNode* _pRight;
	BTDataType _data;
}BTNode,*PBTNode;

//创建二叉树
void CreatBinTree(PBTNode* pRoot, BTDataType array[], int size, BTDataType invaild);
//拷贝二叉树
PBTNode CopyBinTree(PBTNode pRoot);

//前序 中序 后序遍历
void PerOrder(PBTNode pRoot);
void MidOrder(PBTNode pRoot);
void PostOrder(PBTNode pRoot);
void DestroyBinTree(PBTNode* pRoot);
//层序遍历
void LevelOrder(PBTNode pRoot);

//二叉树镜像
void MirrorBinTree(PBTNode pRoot);
void MirrorBinTreeNor(PBTNode pRoot);
//二叉树的节点数
int BinTreeSize(PBTNode pRoot);

void TestBinTree();