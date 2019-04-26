//
// Created by KagurazakaMona on 2019/4/9.
//
#include "header.h"
using namespace std;

//����һ���ն��У���ʼ����
Status InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}
//���
Status EnQueue(LinkQueue& Q, StudentScore e) {
	auto p = new QNode;           //�����µĶ��нڵ�
	p->data = e;                  //���¶��нڵ��data��ֵ
	p->next = NULL;               //�޸��¶��нڵ��next
	Q.rear->next = p;             //������ĩβָ��ָ��ľɽڵ��next�޸�Ϊp
	Q.rear = p;                   //�ƶ����е�ĩβָ��
	return OK;
}
//����
ElemType DeQueue(LinkQueue& Q) {
	if (Q.rear == Q.front) return NULL;     //�����ͷָ�����βָ���غϣ���ӿ�
	auto p = Q.front->next;                 //����ָ�룬ָ���ͷ����һԪ��
	auto e = p->data;						//ȡ��Ԫ��
	Q.front->next = p->next;				//�޸Ķ�ͷָ�룬ָ���ȡ����Ԫ�ص���һ��
	if (Q.rear == p)Q.rear = Q.front;		//�ж�Ԫ�س��Ӻ󣬶����Ƿ�Ϊ��
	delete p;								//ɾ�����ӵ�Ԫ��
	return e;								//���س���Ԫ�ص�ֵ
}
//����һ����ջ����ʼ����
Status InitStack(SqStack & S) {
	S.base = new ElemType[MAXSIZE];			//�����ڴ�ռ䣬����ջͷָ��ָ��ջͷ
	if (!S.base)exit(OVERFLOW);				//���û�ܳɹ����뵽�ռ䣬���ش���
	S.top = S.base;							//��ջβָ��ָ��ջͷ������ջ�ǿյģ�
	S.stacksize = MAXSIZE;					//��������ջ�ռ�Ĵ�С
	return OK;
}
//��ջ
Status Push(SqStack & S, ElemType e) {
	if (S.top - S.base == S.stacksize)return ERROR; //�ж��Ƿ�Ϊջ��
	*S.top++ = e;									//��ջͷָ�����һλ�󣬸�ֵԪ��
	return OK;
}
//��ջ
ElemType Pop(SqStack & S) {
	if (S.top == S.base)return NULL;				//�ж��Ƿ�Ϊջ��
	return *--S.top;								//����Ԫ�غ󣬽�ջͷָ��ǰ��һλ
}