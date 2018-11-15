#pragma once

typedef char BTDataType;

//���ӱ�ʾ��
typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft;
	struct BinTreeNode* _pRight;
	BTDataType _data;
}BTNode,*PBTNode;

//////////////////��������������/////////////////////////
//����������
void CreatBinTree(PBTNode* pRoot, BTDataType array[], int size, BTDataType invaild);
//����������
PBTNode CopyBinTree(PBTNode pRoot);
//ǰ�� ���� �������
void PerOrder(PBTNode pRoot);
void MidOrder(PBTNode pRoot);
void PostOrder(PBTNode pRoot);
//�������
void LevelOrder(PBTNode pRoot);
//������������
void DestroyBinTree(PBTNode* pRoot);


//����һ���ڵ��Ƿ��ڶ�������
PBTNode BinTreeFind(PBTNode pRoot, BTDataType data);



//////////////////������������/////////////////////////
//����������
void MirrorBinTree(PBTNode pRoot);
void MirrorBinTreeNor(PBTNode pRoot);
//�������Ľڵ���
int BinTreeSize(PBTNode pRoot);
//������Ҷ�ӽڵ���
int BinTreeLeaf(PBTNode pRoot);
//�������ĸ߶�
int BinTreeHeight(PBTNode pRoot);
//��K��Ľڵ����
int BinTreeLevekKSize(PBTNode pRoot, int K);

///////////////////////////////////////////////
void TestBinTree();