#include "Header.h"
#include <iostream>
using namespace std;

void ��ʼ������(BiTree &T) {
	T = NULL;
}

void ������(BiTree &T) {
	char ch;
	ch = getchar();
	if (ch == '#') 
		T = NULL;
	else {
		T = new BiTNode;
		if (!T) {
			cout << "�����ڴ治��" << endl;
			return;
		}
		T->data = ch;
		������(T->lchild);
		������(T->rchild);
	}
}

void �������(BiTree T) {
	if (T) {
		�������(T->lchild);
		cout << T->data << "  ";
		�������(T->rchild);
	}
}

void ǰ�����(BiTree T) {
	if (T) {
		cout << T->data << "  ";
		ǰ�����(T->lchild);
		ǰ�����(T->rchild);
	}
}

void �������(BiTree T) {
	if (T) {
		�������(T->lchild);
		�������(T->rchild);
		cout << T->data << "  ";
	}
}

int �������(BiTree T) {
	if (!T) //����ǿ���
		return 0;
	else {
		int m = �������(T->lchild);
		int n = �������(T->rchild);
		return (m > n ? m : n) + 1;
	}
}

int ������ͳ��(BiTree T) {
	if (!T) 
		return 0;
	else 
		return ������ͳ��(T->lchild) + ������ͳ��(T->rchild) + 1;
}

int Ҷ������ͳ��(BiTree T) {
	if (!T)
		return 0;
	else if (!T->lchild && !T->rchild) 
		return 1;
	else 
		return Ҷ������ͳ��(T->lchild) + Ҷ������ͳ��(T->rchild);
}
