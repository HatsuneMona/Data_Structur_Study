#include "Header.h"
#include <iostream>
using namespace std;

void 初始化空树(BiTree &T) {
	T = NULL;
}

void 创建树(BiTree &T) {
	char ch;
	ch = getchar();
	if (ch == '#') 
		T = NULL;
	else {
		T = new BiTNode;
		if (!T) {
			cout << "错误，内存不足" << endl;
			return;
		}
		T->data = ch;
		创建树(T->lchild);
		创建树(T->rchild);
	}
}

void 中序遍历(BiTree T) {
	if (T) {
		中序遍历(T->lchild);
		cout << T->data << "  ";
		中序遍历(T->rchild);
	}
}

void 前序遍历(BiTree T) {
	if (T) {
		cout << T->data << "  ";
		前序遍历(T->lchild);
		前序遍历(T->rchild);
	}
}

void 后序遍历(BiTree T) {
	if (T) {
		后序遍历(T->lchild);
		后序遍历(T->rchild);
		cout << T->data << "  ";
	}
}

int 计算深度(BiTree T) {
	if (!T) //如果是空树
		return 0;
	else {
		int m = 计算深度(T->lchild);
		int n = 计算深度(T->rchild);
		return (m > n ? m : n) + 1;
	}
}

int 结点个数统计(BiTree T) {
	if (!T) 
		return 0;
	else 
		return 结点个数统计(T->lchild) + 结点个数统计(T->rchild) + 1;
}

int 叶结点个数统计(BiTree T) {
	if (!T)
		return 0;
	else if (!T->lchild && !T->rchild) 
		return 1;
	else 
		return 叶结点个数统计(T->lchild) + 叶结点个数统计(T->rchild);
}
