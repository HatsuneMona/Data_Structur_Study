#pragma once

//�������Ĵ洢�ṹ
typedef char TElemType;

//�ڵ�ṹ
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;//���Һ���ָ��
}BiTNode, * BiTree;

typedef BiTree SElemType;

//�������
void ��ʼ������(BiTree &T);

//�������Ķ���
void ������(BiTree &T);

//���������������������
void �������(BiTree T);

//�����������ǰ��������
void ǰ�����(BiTree T);

//����������ĺ���������
void �������(BiTree T);

//��������������
int �������(BiTree T);

//ͳ�ƶ������Ľ�����
int ������ͳ��(BiTree T);

//ͳ�ƶ�������Ҷ�ڵ����
int Ҷ������ͳ��(BiTree T);
