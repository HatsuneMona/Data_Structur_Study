#include "header.h"
using namespace std;

void LoadData(LinkQueue& Q);//���ļ��ж�ȡ��Ϣ
void ShowData(LinkQueue Q);//��ʾ����

int main() {
	LinkQueue StuLQ;					//�����¶���
	InitQueue(StuLQ);					//��ʼ���¶���
	for (int i = 60; i <= 100; i++)		//������������Դ
		EnQueue(StuLQ, i);
	ShowData(StuLQ);					//��ʾ�����е�����
	SqStack StuSq;						//�����µ�ջ
	InitStack(StuSq);					//��ʼ��ջ
	//����ջ��ѧ����������
	while (auto e = DeQueue(StuLQ))		//�Ƚ������е����ݳ���
		Push(StuSq, e);					    //���Ƶ�ջ��
	while (auto e = Pop(StuSq))			//�ٽ�ջ�е����ݵ���
		EnQueue(StuLQ, e);					//�����뵽������
	ShowData(StuLQ);					//��ʾ�����е�����
	return 0;
}

//���ļ��ж�ȡ��Ϣ
void LoadData(LinkQueue& Q) {
	for (int i = 60; i <= 100; i++)
		EnQueue(Q, i);
}
//��ʾ��������
void ShowData(LinkQueue Q) {
	auto p = Q.front;
	while (p = p->next)
		cout << p->data << "    ";
	cout << endl << "������ʾ���" << endl;
}