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
typedef int       Status;        //状态

//一元多项式的定义
typedef struct {
	float coef;    //多项式系数
	int expn;      //多项式指数
}ElemType;

//链表的定义
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

//初始化链表
Status InitList(LinkList& L);

//创建单链表（使用“后插法”）（使用读取文件的方法进行创建）
Status AddElem(LinkList& L, string path);

//输出一元多项式
Status ShowPolynomial(LinkList L);

//加工一元多项式（合并指数相同的项），必须是已经排序了的多项式
Status ProcessingPolynomial(LinkList &L);

//两个一元多项式求和，返回相加后的结果
LinkList SumPolynomial(LinkList L, LinkList M);

//按多项式指数大小由小到大排序
Status Sort(LinkList& L);

//交换两个结点元素的位置
Status Swap(LNode* p, LNode* q);

//删除下一项结点
Status RemoveNext(LNode* p);