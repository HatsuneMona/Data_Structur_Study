#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

#define TRUE      1
#define FALSE     0
#define OK        1
#define ERROR     0
typedef int       Status;        //״̬

//һԪ����ʽ�Ķ���
typedef struct {
	float coef;    //����ʽϵ��
	int expn;      //����ʽָ��
}ElemType;

//����Ķ���
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

//��ʼ������
Status InitList(LinkList& L);

//����������ʹ�á���巨������ʹ�ö�ȡ�ļ��ķ������д�����
Status AddElem(LinkList& L, string path);

//���һԪ����ʽ
Status ShowPolynomial(LinkList L);

//�ӹ�һԪ����ʽ���ϲ�ָ����ͬ������������Ѿ������˵Ķ���ʽ
Status ProcessingPolynomial(LinkList &L);

//����һԪ����ʽ��ͣ�������Ӻ�Ľ��
LinkList SumPolynomial(LinkList L, LinkList M);

//������ʽָ����С��С��������
Status Sort(LinkList& L);

//�����������Ԫ�ص�λ��
Status Swap(LNode* p, LNode* q);

//ɾ����һ����
Status RemoveNext(LNode* p);