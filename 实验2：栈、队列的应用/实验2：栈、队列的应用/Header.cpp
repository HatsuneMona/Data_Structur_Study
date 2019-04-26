//
// Created by KagurazakaMona on 2019/4/9.
//
#include "header.h"
using namespace std;

//构造一个空队列（初始化）
Status InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}
//入队
Status EnQueue(LinkQueue& Q, StudentScore e) {
	auto p = new QNode;           //创建新的队列节点
	p->data = e;                  //将新队列节点的data赋值
	p->next = NULL;               //修改新队列节点的next
	Q.rear->next = p;             //将队列末尾指针指向的旧节点的next修改为p
	Q.rear = p;                   //移动队列的末尾指针
	return OK;
}
//出队
ElemType DeQueue(LinkQueue& Q) {
	if (Q.rear == Q.front) return NULL;     //如果队头指针与队尾指针重合，则队空
	auto p = Q.front->next;                 //定义指针，指向队头的下一元素
	auto e = p->data;						//取得元素
	Q.front->next = p->next;				//修改队头指针，指向读取到的元素的下一项
	if (Q.rear == p)Q.rear = Q.front;		//判断元素出队后，队伍是否为空
	delete p;								//删除出队的元素
	return e;								//返回出队元素的值
}
//构建一个空栈（初始化）
Status InitStack(SqStack & S) {
	S.base = new ElemType[MAXSIZE];			//申请内存空间，并将栈头指针指向栈头
	if (!S.base)exit(OVERFLOW);				//如果没能成功申请到空间，返回错误
	S.top = S.base;							//将栈尾指针指向栈头（代表栈是空的）
	S.stacksize = MAXSIZE;					//定义分配的栈空间的大小
	return OK;
}
//入栈
Status Push(SqStack & S, ElemType e) {
	if (S.top - S.base == S.stacksize)return ERROR; //判断是否为栈满
	*S.top++ = e;									//将栈头指针后移一位后，赋值元素
	return OK;
}
//出栈
ElemType Pop(SqStack & S) {
	if (S.top == S.base)return NULL;				//判断是否为栈空
	return *--S.top;								//返回元素后，将栈头指针前移一位
}