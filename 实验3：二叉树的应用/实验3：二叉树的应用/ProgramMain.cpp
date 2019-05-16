#include"Header.h"
#include<iostream>
using namespace std;

void main() {
	BiTree tree;
	初始化空树(tree);
	cout << "请输入树的内容，空树以 # 代替：" << endl;
	创建树(tree);
	cout << endl << "二叉树中序遍历的结果为：" << endl;
	中序遍历(tree);
	cout << endl << "二叉树前序遍历的结果为：" << endl;
	前序遍历(tree);
	cout << endl << "二叉树后序遍历的结果为：" << endl;
	后序遍历(tree);
	cout << endl << "二叉树的深度为：" << 计算深度(tree);
	cout << endl << "二叉树结点个数为：" << 结点个数统计(tree);
	cout << endl << "二叉树叶节点个数为：" << 叶结点个数统计(tree);
}