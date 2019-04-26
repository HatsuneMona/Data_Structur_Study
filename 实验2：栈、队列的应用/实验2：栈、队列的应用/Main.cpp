#include "header.h"
using namespace std;

void LoadData(LinkQueue& Q);//从文件中读取信息
void ShowData(LinkQueue Q);//显示数据

int main() {
	LinkQueue StuLQ;					//创建新队列
	InitQueue(StuLQ);					//初始化新队列
	for (int i = 60; i <= 100; i++)		//产生队列数据源
		EnQueue(StuLQ, i);
	ShowData(StuLQ);					//显示队列中的数据
	SqStack StuSq;						//创建新的栈
	InitStack(StuSq);					//初始化栈
	//利用栈将学生队列逆序
	while (auto e = DeQueue(StuLQ))		//先将队列中的数据出队
		Push(StuSq, e);					    //并推到栈中
	while (auto e = Pop(StuSq))			//再将栈中的数据弹出
		EnQueue(StuLQ, e);					//并加入到队列中
	ShowData(StuLQ);					//显示队列中的数据
	return 0;
}

//从文件中读取信息
void LoadData(LinkQueue& Q) {
	for (int i = 60; i <= 100; i++)
		EnQueue(Q, i);
}
//显示队列数据
void ShowData(LinkQueue Q) {
	auto p = Q.front;
	while (p = p->next)
		cout << p->data << "    ";
	cout << endl << "数据显示完毕" << endl;
}