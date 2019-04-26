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
typedef int       Status;        //状态

//定义最大值
#define MAXSIZE 100

//学生成绩的定义
typedef int StudentScore;
typedef StudentScore ElemType;

//栈的定义
typedef struct {
	ElemType* base;//栈底指针
	ElemType* top;//栈顶指针
	int stacksize;//当前已分配的栈空间
}SqStack;

//队列的定义
//结点类型
typedef struct QNode {
	ElemType data;
	struct QNode* next;
}QNode, * QueuePtr;

//栈队列类型
typedef struct {
	QueuePtr front;//对头指针
	QueuePtr rear;//队尾指针
}LinkQueue;

//构造一个空队列（初始化）
Status InitQueue(LinkQueue& Q);
//入队
Status EnQueue(LinkQueue& Q, StudentScore e);
//出队
ElemType DeQueue(LinkQueue& Q);

//构建一个空栈（初始化）
Status InitStack(SqStack& S);
//入栈
Status Push(SqStack& S, ElemType e);
//出栈
ElemType Pop(SqStack& S);
