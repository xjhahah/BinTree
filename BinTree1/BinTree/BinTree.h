#pragma once

typedef char DataType;

//���ӱ�ʾ��
typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft;
	struct BinTreeNode* _pRight;
	DataType _data;
}Node,*PNode;

//����������
void CreatBinTree(PNode* pRoot, DataType array[], int size, DataType invaild);
//����������
PNode CopyBinTree(PNode pRoot);

//ǰ�� ���� �������
void PerOrder(PNode pRoot);
void MidOrder(PNode pRoot);
void PostOrder(PNode pRoot);
void DestroyBinTree(PNode* pRoot);
void TestBinTree();