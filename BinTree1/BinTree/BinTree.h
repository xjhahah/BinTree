#pragma once

typedef char BTDataType;

//孩子表示法
typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft;
	struct BinTreeNode* _pRight;
	BTDataType _data;
}BTNode,*PBTNode;

//////////////////二叉树基本操作/////////////////////////
//创建二叉树
void CreatBinTree(PBTNode* pRoot, BTDataType array[], int size, BTDataType invaild);
//拷贝二叉树
PBTNode CopyBinTree(PBTNode pRoot);
//前序 中序 后序遍历
void PerOrder(PBTNode pRoot);
void MidOrder(PBTNode pRoot);
void PostOrder(PBTNode pRoot);
// 非递归遍历 
void BTreePrevOrderNonR(PBTNode pRoot);
void BTreeInOrderNonR(PBTNode pRoot);
void BTreePostOrderNonR(PBTNode pRoot);
//层序遍历
void LevelOrder(PBTNode pRoot);
//二叉树的销毁
void DestroyBinTree(PBTNode* pRoot);


//查找一个节点是否在二叉树中
PBTNode BinTreeFind(PBTNode pRoot, BTDataType data);



//////////////////二叉树面试题/////////////////////////
//二叉树镜像
void MirrorBinTree(PBTNode pRoot);
void MirrorBinTreeNor(PBTNode pRoot);
//二叉树的节点数
int BinTreeSize(PBTNode pRoot);
//二叉树叶子节点数
int BinTreeLeaf(PBTNode pRoot);
//二叉树的高度
int BinTreeHeight(PBTNode pRoot);
//求K层的节点个数
int BinTreeLevekKSize(PBTNode pRoot, int K);
//判断二叉树是否为完全二叉树
int IsCompleteBTree(PBTNode pRoot);
//int IsCompleteBTree1(PBTNode pRoot); // flag的方式判断 
///////////////////////////////////////////////
void TestBinTree();