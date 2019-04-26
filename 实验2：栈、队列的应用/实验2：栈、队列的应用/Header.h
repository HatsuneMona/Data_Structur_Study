#pragma once
//
// Created by KagurazakaMona on 2019/4/9.
//
#include <iostream>
#include <string>

#define TRUE      1
#define FALSE     0
#define OK        1
#define ERROR     0
typedef int       Status;        //״̬

//�������ֵ
#define MAXSIZE 100

//ѧ���ɼ��Ķ���
typedef int StudentScore;
typedef StudentScore ElemType;

//ջ�Ķ���
typedef struct {
	ElemType* base;//ջ��ָ��
	ElemType* top;//ջ��ָ��
	int stacksize;//��ǰ�ѷ����ջ�ռ�
}SqStack;

//���еĶ���
//�������
typedef struct QNode {
	ElemType data;
	struct QNode* next;
}QNode, * QueuePtr;

//ջ��������
typedef struct {
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}LinkQueue;

//����һ���ն��У���ʼ����
Status InitQueue(LinkQueue& Q);
//���
Status EnQueue(LinkQueue& Q, StudentScore e);
//����
ElemType DeQueue(LinkQueue& Q);

//����һ����ջ����ʼ����
Status InitStack(SqStack& S);
//��ջ
Status Push(SqStack& S, ElemType e);
//��ջ
ElemType Pop(SqStack& S);
